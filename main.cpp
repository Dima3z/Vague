#include <iostream> 
#include <windows.h>
#include "console.h"

void test();


int main()
{
	// Set console dimensions
	char a[40];
	sprintf(a, "mode CON: COLS=%d LINES=%d", WIDTH, HEIGHT + 1);
	system(a);

	test();

	return 0;
}

void test() {
	for (int i = 0; i < 2000; i++) {
		short x = rand() % WIDTH;
		short y = rand() % HEIGHT;
		short choice = rand() % 2 == 1;
		for (short j = 0; j < 9; j++) 
			cclprintf({ x + j / 3 , y + j % 3 } , { choice ? RED : BLUE, BLACK }, choice ? "+" : "-");
		_sleep(400);
		for (short j = 0; j < 9; j++)
			ccprintf({ x + j / 3 , y + j % 3 } ,  " ");
		_sleep(150);
	}
};
