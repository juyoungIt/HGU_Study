#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "Console.h"
#include "KeyBuffer.h"

#define SHM_FILE "key_buffer.shm"


int main(int argc, char *argv)
{
	// TO DO: open SHM_FILE for using shm_open()
	//  check if the file was successfully open
	const char *name = "/shmSpace";
	int shm_fd = shm_open(name, O_RDWR, 0666);
	if(shm_fd == -1) {
		printf("Error! - shm_oepn() was failed.\n");
		return 0;
	}

	int buffer_size = sizeof(KeyBuffer);

	// TO DO: map the shared memory file and receive the return address into     key_buffer
	// check if the file was successfully mapped
	KeyBuffer *key_buffer = (KeyBuffer*)mmap(0, buffer_size, PROT_WRITE, MAP_SHARED, shm_fd, 0);
	if(key_buffer == MAP_FAILED) {
		printf("Error! - mmap() was failed.\n");
		return 0;
	}

	int screen_width = getWindowWidth();
	int screen_height = getWindowHeight() - 3;

	clrscr();

	printf("screen size: %d x %d\n", screen_width, screen_height);
	int x = screen_width / 2;
	int y = screen_height / 2;
	int key = 0;
	char c = '*';
	int repeat = 1;

	gotoxy(x, y);
	putchar('#');

	while(repeat){
		int oldx = x;
		int oldy = y;
	
		gotoxy(screen_width, 1);	// move cursor to upper right corner

		// TO DO: read a key from the key buffer in the shared memory
		// if the key is zero, repeat until a non-zero key is read
		
		key = DeleteKey(key_buffer);
		if(key == 0)
			continue;

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
			repeat = 0;
		}

		// TO DO: print c at (oldx, oldy)
		gotoxy(oldx, oldy);
		printf("%c", c);

		// TO DO: print '#' at (x, y)
		gotoxy(x, y);
		printf("%c", '#');
	}

	// my addtional part
	if(munmap(key_buffer, buffer_size) == -1) {
		printf("Error - munmap() was failed.\n");
		return 0;
	}

	clrscr();
	printf("Bye!\n");

	return 0;
}
