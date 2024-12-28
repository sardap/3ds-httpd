#include "handlers.h"

void init_handlers()
{
	register_handler(GET, is_default_page, get_default_page, NULL, NULL);
}
