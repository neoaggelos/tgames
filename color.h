#ifndef COLOR_H

/* file: colors.h */
#include "turrets.h"
//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//

#define BLACK 				"\033[22;30m"
#define RED				"\033[22;31m"
#define GREEN				"\033[22;32m"
#define BROWN				"\033[22;33m"
#define BLUE				"\033[22;34m"
#define MAGENTA				"\033[22;35m"
#define CYAN				"\033[22;36m"
#define GRAY				"\033[22;37m"
#define DARKGRAY			"\033[01;30m"
#define LIGHTRED			"\033[01;31m"
#define LIGHTGREEN			"\033[01;32m"
#define YELLOW				"\033[01;33m"
#define LIGHTBLUE			"\033[01;34m"
#define LIGHTMAGENTA			"\033[01;35m"
#define LIGHTCYAN			"\033[01;36m"
#define WHITE 				"\033[01;37m"

#ifdef WIN32
#include <windows.h>

#define WRED FOREGROUND_INTENSITY|FOREGROUND_RED
#define WBLUE FOREGROUND_INTENSITY|FOREGROUND_BLUE
#define WGREEN FOREGROUND_INTENSITY|FOREGROUND_GREEN
#define DEFAULT FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE

#endif
#define COLOR_H
#endif
