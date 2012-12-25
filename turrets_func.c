#ifndef FUNC_C

/* file: turrets_func.c */

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

#include <string.h>
#include <stdio.h>
#include "turrets.h"
#include "color.h"
void gprintf(char **g1, char **g2, int n, int sh1, int sh2) {
	char row='h';
	int i,j;
	printf("Round %d! ",n);
	if (n%2==1)
		printf("You play!\n\n");
	else
		printf("I play!\n\n");
	printf("              Your turrets                         Your bombs          \n");
	printf("             %d turrets left                     %d turrets left\n\n",sh1,sh2);
	printf("  +---+---+---+---+---+---+---+---+     +---+---+---+---+---+---+---+---+\n");
	for(i=7;i>=0;i--) {
		printf("%c |",row);
		for (j=0;j<=7;j++) {
			if (g1[i][j]==TURRET) chcolor(LIGHTBLUE);
			if (g1[i][j]==MISSED) chcolor(GREEN);
			if (g1[i][j]==HIT) chcolor(RED);
			printf(" %c ",g1[i][j]);
			chcolor(WHITE);
			printf("|");
		}
		printf("   %c |",row);
		for (j=0;j<=7;j++) {
			if (g2[i][j]!=TURRET&&g2[i][j]!=PLAIN) {
				if (g2[i][j]==MISSED) chcolor(GREEN);
				if (g2[i][j]==HIT) chcolor(RED);
				printf(" %c ",g2[i][j]);
				chcolor(WHITE);
				printf("|");
			}
			else
				printf("   |");
		}
		printf("\n");
		--row;
		printf("  +---+---+---+---+---+---+---+---+     +---+---+---+---+---+---+---+---+\n");
	}
	printf("    1   2   3   4   5   6   7   8         1   2   3   4   5   6   7   8\n\n");
}

void grid(char **g1, char **g2) {
	int i,j;
	char row='h';
	printf("             Your turrets                         Your bombs\n");
	printf("  +---+---+---+---+---+---+---+---+     +---+---+---+---+---+---+---+---+\n");
	for(i=7;i>=0;i--) {
		printf("%c |",row);
		for (j=0;j<=7;j++) {
			if (g1[i][j]==TURRET) chcolor(LIGHTBLUE);
			if (g1[i][j]==MISSED) chcolor(GREEN);
			if (g1[i][j]==HIT) chcolor(RED);
			printf(" %c ",g1[i][j]);
			chcolor(WHITE);
			printf("|");
		}
		printf("   %c |",row);
		for (j=0;j<=7;j++) {
			if (g2[i][j]!=TURRET&&g2[i][j]!=PLAIN) {
				if (g2[i][j]==MISSED) chcolor(GREEN);
				if (g2[i][j]==HIT) chcolor(RED);
				printf(" %c ",g2[i][j]);
				chcolor(WHITE);
				printf("|");
			}
			else
				printf("   |");
		}
		printf("\n");
		--row;
		printf("  +---+---+---+---+---+---+---+---+     +---+---+---+---+---+---+---+---+\n");
	}
	printf("    1   2   3   4   5   6   7   8         1   2   3   4   5   6   7   8\n\n");
}

void resetf(char **g1,char **g2) {
	int i,j;
	for(i=0;i<8;i++) {
		for(j=0;j<8;j++) {
			g1[i][j] = g2[i][j] = PLAIN;
		}
	}
}

#define FUNC_C
#endif
