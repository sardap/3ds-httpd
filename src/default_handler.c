#include "handlers.h"
#include "content.h"

static const char content_type_jpeg[] = "Content-Type: image/jpeg\r\n";
static const char content_type_html[] = "Content-Type: text/html\r\n";


static void fill_request(http_response *response, const char* content_type, const unsigned int content_type_len, const unsigned char* jpg, unsigned int len)
{
	response->code = 200;
	response->content_type = memdup(content_type, content_type_len);
	response->payload = memdup(jpg, len);
	response->payload_len = len;
}


int	is_default_page(http_request *request)
{
	return startWith(request->path, "/");
}

http_response *get_default_page(http_request *request)
{
	http_response *response = memalloc(sizeof(http_response));
	if (strcmp(request->path, "/") == 0)
		fill_request(response, content_type_html, sizeof(content_type_html), __3ds_site_dist_index_html, __3ds_site_dist_index_html_len);
	else if (strcmp(request->path, "/2ds.jpg") == 0)
		fill_request(response, content_type_jpeg, sizeof(content_type_jpeg), __3ds_site_dist_2ds_jpg, __3ds_site_dist_2ds_jpg_len);
	else if (strcmp(request->path, "/books/HNI_0002.jpg") == 0)
		fill_request(response, content_type_jpeg, sizeof(content_type_jpeg), __3ds_site_dist_books_HNI_0002_jpg, __3ds_site_dist_books_HNI_0002_jpg_len);
	else if (strcmp(request->path, "/books/HNI_0003.jpg") == 0)
		fill_request(response, content_type_jpeg, sizeof(content_type_jpeg), __3ds_site_dist_books_HNI_0003_jpg, __3ds_site_dist_books_HNI_0003_jpg_len);
	else if (strcmp(request->path, "/books/HNI_0004.jpg") == 0)
		fill_request(response, content_type_jpeg, sizeof(content_type_jpeg), __3ds_site_dist_books_HNI_0004_jpg, __3ds_site_dist_books_HNI_0004_jpg_len);
	else if (strcmp(request->path, "/books/HNI_0005.jpg") == 0)
		fill_request(response, content_type_jpeg, sizeof(content_type_jpeg), __3ds_site_dist_books_HNI_0005_jpg, __3ds_site_dist_books_HNI_0005_jpg_len);
	else if (strcmp(request->path, "/books/HNI_0006.jpg") == 0)
		fill_request(response, content_type_jpeg, sizeof(content_type_jpeg), __3ds_site_dist_books_HNI_0006_jpg, __3ds_site_dist_books_HNI_0006_jpg_len);
	else if (strcmp(request->path, "/books/HNI_0007.jpg") == 0)
		fill_request(response, content_type_jpeg, sizeof(content_type_jpeg), __3ds_site_dist_books_HNI_0007_jpg, __3ds_site_dist_books_HNI_0007_jpg_len);
	else
		return NULL;
	
	return response;
}
