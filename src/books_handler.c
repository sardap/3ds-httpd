#include "handlers.h"
#include "content.h"

static void fill_book_request(http_response *response, const unsigned char* jpg, unsigned int len)
{
	response->code = 200;
	const char content_type[] = "Content-Type: image/jpeg\r\n";
	response->content_type = memdup(content_type, sizeof(content_type));
	response->payload = memdup(jpg, len);
	response->payload_len = len;
}

int	is_books_request(http_request *request)
{
	return startWith(request->path, "/books/");
}

http_response *get_books_image(http_request *request)
{
	http_response *response = memalloc(sizeof(http_response));
	if (strcmp(request->path, "/books/HNI_0002.jpg") == 0)
		fill_book_request(response, __3ds_site_public_books_HNI_0002_jpg, __3ds_site_public_books_HNI_0002_jpg_len);
	else if (strcmp(request->path, "/books/HNI_0003.jpg") == 0)
		fill_book_request(response, __3ds_site_public_books_HNI_0003_jpg, __3ds_site_public_books_HNI_0003_jpg_len);
	else if (strcmp(request->path, "/books/HNI_0004.jpg") == 0)
		fill_book_request(response, __3ds_site_public_books_HNI_0004_jpg, __3ds_site_public_books_HNI_0004_jpg_len);
	else if (strcmp(request->path, "/books/HNI_0005.jpg") == 0)
		fill_book_request(response, __3ds_site_public_books_HNI_0005_jpg, __3ds_site_public_books_HNI_0005_jpg_len);
	else if (strcmp(request->path, "/books/HNI_0006.jpg") == 0)
		fill_book_request(response, __3ds_site_public_books_HNI_0006_jpg, __3ds_site_public_books_HNI_0006_jpg_len);
	else if (strcmp(request->path, "/books/HNI_0007.jpg") == 0)
		fill_book_request(response, __3ds_site_public_books_HNI_0007_jpg, __3ds_site_public_books_HNI_0007_jpg_len);
	else
	{
		response->code = DEFAULT_PAGE.code;
		response->content_type = (char*)memdup(DEFAULT_PAGE.content_type, CONTENT_TYPE_HTML_SIZE);
		response->payload = (char*)memdup(DEFAULT_PAGE.payload, DEFAULT_PAGE_SIZE);
		response->payload_len = strnlen(DEFAULT_PAGE.payload, DEFAULT_PAGE_SIZE);
	}
	return response;
}

