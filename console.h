#pragma once

#define WIDTH 150
#define HEIGHT 60

typedef enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_CYAN,
	DARK_RED,
	DARK_MAGENTA,
	DARK_YELLOW,
	LIGHT_GRAY,
	GRAY,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	YELLOW,
	WHITE
} Color;

typedef struct {
	Color foreground;
	Color background;
} FontColor;

void clprintf(FontColor color, char* const _Format, ...);
void ccprintf(COORD coords, char* const _Format, ...);
void cclprintf(COORD coords, FontColor color, char* const _Format, ...);