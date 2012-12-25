#ifndef MAIN_H

/* file: turrets.h */

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

#define HIT 'H'
#define TURRET 'T'
#define PLAIN ' '
#define MISSED 'M'

void gprintf(char **g1, char **g2, int n, int sh1, int sh2);/* grid of the game */
void resetf(char **g1, char **g2);/*reset the grids*/
void grid(char **g1, char **g2);/*grid when placing ships*/

#define LINUX
//#define WIN32

#define MAIN_H
#endif
