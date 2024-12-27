#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H
#include <stdio.h>
#include <malloc.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "http_types.h"
#include "http_utils.h"
#include "mem_utils.h"
#include "utils.h"

#define SOC_ALIGN       0x1000
#define SOC_BUFFERSIZE  0x100000

#define DEFAULT_PAGE_CONTENT "<html><title>404 Not found</title><h1>404 - Not found</h1></html>"
#define DEFAULT_PAGE_SIZE sizeof(DEFAULT_PAGE_CONTENT)

#define CONTENT_TYPE_HTML "Content-Type: text/html\r\n"
#define CONTENT_TYPE_HTML_SIZE sizeof(CONTENT_TYPE_HTML)

#define CONTENT_TYPE_MAX_SIZE 1024
#define REQUEST_TYPE_MAX_SIZE 10

// silence the unused warning because we use it!
__attribute__((unused))
static http_response DEFAULT_PAGE = {.code = 404, .content_type = CONTENT_TYPE_HTML, .payload = DEFAULT_PAGE_CONTENT};
extern PrintConsole topScreen, bottomScreen;
void init();
int loop();
void destroy();
void manage_connection(http_server *data, char *payload);
void register_handler(http_request_type type, is_handler check, compute_response get_response, situational_handle before_response, situational_handle after_response);
void init_handlers();
#endif
