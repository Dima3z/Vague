#include <iostream>
#include <windows.h>
#include "console.h"

int main()
{
	
	test();
	return 0;
}

void test() {
	FontColor clr = { RED, CYAN };
	clprintf(clr, "This text is RED on CYAN and supports %s", "formattiing!");
	printf(" ");
	clprintf({ GREEN, DARK_GREEN }, "ENTER THE MATRIX\n");

	Color rainbow[] = { GREEN, DARK_GREEN };

	for (int i = 0; i < 3000; i++) {
		for (int j = 0; j < 10; j++) {
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { rand() % 80 , rand() % 22 + 1 });
			clprintf({ rainbow[i % 2], BLACK }, "%c", (char)(rand() % 245 + 10));
		}
		_sleep(1);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 23 });
		printf("Loading... ", i);

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)(69.0 / 3000.0 *i) + 11 , 23 });
		clprintf({ WHITE, WHITE }, "#");
	}

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,24 });
	printf("Done! ");
};
