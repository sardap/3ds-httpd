#include "handlers.h"

void init_handlers()
{
	register_handler(GET, is_default_page, get_default_page, NULL, NULL);
	register_handler(GET, is_books_request, get_books_image, NULL, NULL);
}
