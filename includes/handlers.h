#ifndef HTTP_HANDLERS_H
#define HTTP_HANDLERS_H
#include "httpserver.h"

int is_default_page(http_request *request);
http_response *get_default_page(http_request *request);

int is_books_request(http_request *request);
http_response *get_books_image(http_request *request);
#endif
