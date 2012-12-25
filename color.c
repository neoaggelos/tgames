#ifndef COLOR_C

#include <string.h>
#include <stdio.h>
#include "turrets.h"
#include "color.h"

#ifdef WIN32
#include <windows.h>
#endif

void chcolor(char* color) {
#ifdef LINUX
	printf("%s",color);
#endif
#ifdef WIN32
	HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
	if (!strcmp(color,RED)) {
		SetConsoleTextAttribute(h,WRED);
	}
	if (!strcmp(color,LIGHTBLUE)) {
		SetConsoleTextAttribute(h,WBLUE);
	}
	if (!strcmp(color,GREEN)) {
		SetConsoleTextAttribute(h,WGREEN);
	}
	if (!strcmp(color,WHITE)) {
		SetConsoleTextAttribute(h,DEFAULT);
	}
#endif
}

#define COLOR_C
#endif
