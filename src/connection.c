#include "httpserver.h"

static void compute_path(http_request *request)
{
	// Default value
	request->path = "/";
	char *request_type = get_request_name(request->type);
	char *path = request->header;

	// Unknown request type?
	if (request_type)
		path += strnlen(request_type, 8) + 1;
	path = strtok(path, " ");

	// If path isn't NULL
	if (path)
		request->path = path;
}

void send_response(s32 client_id, http_response *response)
{
	const u32 buffer_size = 256;
	char buffer[buffer_size];
	memset(buffer, 0, buffer_size);
	snprintf(buffer, buffer_size, "HTTP/1.1 %d %s\r\n", response->code, get_http_code_name(response->code));

	// HTTP/1.1 code message
	send(client_id, buffer, buffer_size, 0);
	// headers (TODO: Implement a global list?)
	send(client_id, response->content_type, strnlen(response->content_type, CONTENT_TYPE_MAX_SIZE), 0);

	// server name
	send(client_id, "Server: 3ds-httpd\r\n", 19, 0);
	// tell the browser that we will not keep the connection active after the transaction
	send(client_id, "Connection: close\r\n", 19, 0);

	// payload Length
	memset(buffer, 0, buffer_size);
	snprintf(buffer, buffer_size, "Connection-Length: %u\r\n", response->payload_len);
	send(client_id, buffer, strnlen(buffer, buffer_size), 0);
	// End the header section
	send(client_id, "\r\n", 2, 0);

	// Send the payload
	send(client_id, response->payload, response->payload_len, 0);
}

void manage_connection(http_server *data, char *payload)
{
	http_request *request = memalloc(sizeof(http_request));
	request->payload = payload;
	request->header = strtok(payload, "\r\n");
	request->type = get_type(request->header);

	// scan others lines
	char *rawData = strtok(NULL, "\r\n");
	while (rawData)
	{
		if (startWith(rawData, "Host: "))
			request->hostname = rawData + 6;
		else if (startWith(rawData, "User-Agent: "))
			request->agent = rawData + 12;
		rawData = strtok(NULL, "\r\n");
	}

	// extract the path from the header
	compute_path(request);

	// get request handler
	http_request_handler *handler = get_request_handler(request);

	// prehandle the request
	if (handler && handler->before_response != NULL)
		handler->before_response(data, request);

	http_response *response = NULL;

	// use the handler to try to generate a response to send
	if (handler)
		response = handler->generate_response(request);

	// if the response is null, we use the default "Not Implemented" page (returning a 501 error code)
	if (response == NULL)
	{
		// copy default response
		response = memalloc(sizeof(http_response));
		response->code = DEFAULT_PAGE.code;
		response->content_type = (char*)memdup(DEFAULT_PAGE.content_type, CONTENT_TYPE_HTML_SIZE);
		response->payload = (char*)memdup(DEFAULT_PAGE.payload, DEFAULT_PAGE_SIZE);
		response->payload_len = strnlen(DEFAULT_PAGE.payload, DEFAULT_PAGE_SIZE);
	}

	printTop("[%d]: %s %s (client: %s)\n", response->code, get_request_name(request->type), request->path, inet_ntoa(data->client_addr.sin_addr));
	send_response(data->client_id, response);

	// response isn't needed anymore, delete it!
	memdel((void**)&response->content_type);
	memdel((void**)&response->payload);
	memdel((void**)&response);

	// post handle
	if (handler && handler->after_response != NULL)
		handler->after_response(data, request);

	// job done, clean request
	memdel((void**)&request);
}
