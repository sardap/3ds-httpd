#include "httpserver.h"
#include <3ds.h>
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	int port = 8081;
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
		bool didit = false;
		if (kDown & KEY_X)
		{
			didit = true;
			swkbdInit(&swkbd, SWKBD_TYPE_NUMPAD, 1, 5);
			itoa(port,keybuf,10);
			swkbdSetInitialText(&swkbd, keybuf);
			swkbdSetValidation(&swkbd, SWKBD_NOTEMPTY_NOTBLANK, 0, 0);
			swkbdSetFeatures(&swkbd, SWKBD_FIXED_WIDTH);
			button = swkbdInputText(&swkbd, keybuf, sizeof(keybuf));
		}
		if (didit)
		{
			if (button != SWKBD_BUTTON_NONE)
			{
				if(atoi(keybuf) > 0 && atoi(keybuf) < 65566) 
				{
					port = atoi(keybuf);
					destroy();
					init(port);
				} else printTop("Port needs to be a value between 1-65565\n");
			} else
				printTop("swkbd event: %d\n", swkbdGetResult(&swkbd));
		}
		
		
	}
	while (aptMainLoop() && loop());
	destroy();
	return 0;
}
