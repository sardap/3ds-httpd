#include "httpserver.h"
#include <3ds.h>
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	printBottom("Booted\n");
	int port = 8081;
	int manualpage = 0;
	char keybuf[6];
	init(port);
	do
	{
		hidScanInput();

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break;
		
		static SwkbdState swkbd;
		SwkbdButton button = SWKBD_BUTTON_NONE;
	}
	while (aptMainLoop() && loop());
	destroy();
	return 0;
}
