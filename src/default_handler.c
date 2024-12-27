#include "handlers.h"
#include "content.h"

int	is_default_page(http_request *request)
{
	return strcmp(request->path, "/") == 0;
}

http_response *get_default_page(http_request *request)
{
	http_response *response = memalloc(sizeof(http_response));
	response->code = 200;
	const char content_type[] = "Content-Type: text/html\r\n";
	response->content_type = memdup(content_type, sizeof(content_type));
	response->payload = memdup(__3ds_site_dist_index_html, __3ds_site_dist_index_html_len);
	response->payload_len = __3ds_site_dist_index_html_len;
	return response;
}
