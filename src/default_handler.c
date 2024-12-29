#include "handlers.h"
#include "content.h"

typedef struct content_type
{
	const char *str;
	const unsigned int len;
} content_type;

static const content_type content_type_jpeg = {.str = "Content-Type: image/jpeg\r\n", .len = 27};
static const content_type content_type_html = {.str = "Content-Type: text/html\r\n", .len = 26};
static const content_type content_type_icon = {.str = "Content-Type: image/vnd.microsoft.icon\r\n", .len = 41};

static void fill_request(http_response *response, const content_type* content_type, const unsigned char *jpg, unsigned int len)
{
	response->code = 200;
	response->content_type = memdup(content_type->str, content_type->len);
	response->payload = memdup(jpg, len);
	response->payload_len = len;
}

typedef struct resource
{
	const char *path;
	const content_type *content_type;
	const unsigned char *data;
	const unsigned int *len;
} resource;

static const resource s_resources[] = {
	{.path = "/", .content_type = &content_type_html, .data = __3ds_site_dist_index_html, .len = &__3ds_site_dist_index_html_len},
	{.path = "/favicon.ico", .content_type = &content_type_icon, .data = __3ds_site_dist_favicon_ico, .len = &__3ds_site_dist_favicon_ico_len},
	{.path = "/2ds.jpg", .content_type = &content_type_jpeg, .data = __3ds_site_dist_2ds_jpg, .len = &__3ds_site_dist_2ds_jpg_len},
	{.path = "/books/HNI_0002.jpg", .content_type = &content_type_jpeg, .data = __3ds_site_dist_books_HNI_0002_jpg, .len = &__3ds_site_dist_books_HNI_0002_jpg_len},
	{.path = "/books/HNI_0003.jpg", .content_type = &content_type_jpeg, .data = __3ds_site_dist_books_HNI_0003_jpg, .len = &__3ds_site_dist_books_HNI_0003_jpg_len},
	{.path = "/books/HNI_0004.jpg", .content_type = &content_type_jpeg, .data = __3ds_site_dist_books_HNI_0004_jpg, .len = &__3ds_site_dist_books_HNI_0004_jpg_len},
	{.path = "/books/HNI_0005.jpg", .content_type = &content_type_jpeg, .data = __3ds_site_dist_books_HNI_0005_jpg, .len = &__3ds_site_dist_books_HNI_0005_jpg_len},
	{.path = "/books/HNI_0006.jpg", .content_type = &content_type_jpeg, .data = __3ds_site_dist_books_HNI_0006_jpg, .len = &__3ds_site_dist_books_HNI_0006_jpg_len},
	{.path = "/books/HNI_0007.jpg", .content_type = &content_type_jpeg, .data = __3ds_site_dist_books_HNI_0007_jpg, .len = &__3ds_site_dist_books_HNI_0007_jpg_len},
};

int is_default_page(http_request *request)
{
	for (int i = 0; i < sizeof(s_resources) / sizeof(resource); i++)
	{
		if (strcmp(request->path, s_resources[i].path) == 0)
			return 1;
	}

	return 0;
}

http_response *get_default_page(http_request *request)
{
	http_response *response = memalloc(sizeof(http_response));
	for (int i = 0; i < sizeof(s_resources) / sizeof(resource); i++)
	{
		const resource *entry = &s_resources[i];

		if (strcmp(request->path, entry->path) == 0)
		{
			fill_request(response, entry->content_type, entry->data, *entry->len);
			return response;
		}
	}

	return NULL;
}
