#include <stdio.h>
#include <stdarg.h>
#include <windows.h>
#include "console.h"

WORD toWord(FontColor color) {

	// Left 4 bits is background
	WORD res = color.background;
	res <<= 4;
	// Right 4 bits is foreground color
	res |= color.foreground;

	return res;
}

void clprintf(FontColor color, char* const _Format, ...) {

	// Create va_list to pass further
	va_list a_list;
	va_start(a_list, _Format);
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), toWord(color));
	vprintf(_Format, a_list);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void ccprintf(COORD coords, char* const _Format, ...) {

	// Create va_list to pass further
	va_list a_list;
	va_start(a_list, _Format);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
	vprintf(_Format, a_list);
}

void cclprintf(COORD coords, FontColor color, char* const _Format, ...) {

	// Create va_list to pass further
	va_list a_list;
	va_start(a_list, _Format);

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), toWord(color));
	vprintf(_Format, a_list);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
};