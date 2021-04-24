#include <stdio.h>

#include "Console.h"

int main(int argc, char *argv)
{
	clrscr();			// clear screen

	// retrieve the size of window
	int screen_width = getWindowWidth();
	int screen_height = getWindowHeight() - 3;

	printf("i: up, j: left, k: down, l: right, c: change color, q: quit\n");
	printf("screen size: %d x %d\n", screen_width, screen_height);

	int x = screen_width / 2;	// horizontal coordinate
	int y = screen_height / 2;	// vertical coordinate
	int key = 0;
	int repeat = 1;
	char c = '*';		// initial color

	gotoxy(x, y);		// move the cursor to (x, y)
	putchar('#');

	int oldx = 0, oldy = 0;
	while(repeat){

		gotoxy(1, 3);
		printf("x = %3d, y = %3d", x, y);

		gotoxy(screen_width, 1);	// move cursor to upper right corner
		key = getch();		// read a key not waiting for ENTER
		
		// TO DO: save current coordinate in (oldx, oldy)
		oldx = x; // save current x coordinate
		oldy = y; // save current y coordinate

		// input i
		if(key == 73 || key == 105) {
			if(1 > y-1)
				continue;
			y = y-1;
		}
		// input j
		else if(key == 74 || key == 106) {
			if(1 > x-1)
				continue;
			x = x-1;
		}
		// input k
		else if(key == 75 || key == 107) {
			if(y+1 > screen_height)
				continue;
			y = y+1;
		}
		// input l
		else if(key == 76 || key == 108) {
			if(x+1 > screen_width)
				continue;
			x = x+1;
		}
		// input c
		else if(key == 67 || key == 99) {
			if(c == 42)
				c = ' ';
			else
				c = '*';
		}
		// input q
		else if(key == 81 || key == 113) {
			break;
		}

		// TO DO: print c at (oldx, oldy)
		gotoxy(oldx, oldy);
		printf("%c", c);

		// TO DO: print '#' at (x, y)
		gotoxy(x, y);
		printf("%c", '#');
	}

	clrscr();
	printf("Bye!\n");

	return 0;
}
