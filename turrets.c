/* file: turrets.c */

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

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "turrets.h"
#include "turrets_func.c"
#include "color.c"
#include "color.h"
int sh1, sh2; /*number of turrets left*/

int main(void) {
	chcolor(WHITE);
	char **s, **b; /*bombs and turrets arrays*/		
	s = malloc(8*sizeof(char*));
	b = malloc(8*sizeof(char*));
	int i,j; /*x and y coordinates*/
	for (i=0;i<=7;i++) {
		s[i] = malloc (8*sizeof(char));
		b[i] = malloc (8*sizeof(char));
	}
	char buf[20];
	int n; 
	printf("Turrets v0.1\n\n\n\n");
	printf("Press enter to continue...");
	getchar();	
	sh1 = sh2 = 10;
	resetf(s,b);
	printf("Place your turrets!!!\n\n");
	for(n=0;n<10;n++) {
		grid(s,b);
		sh1:
			do { 
				printf("Choose place for turret %d\n>>> ",n+1);
				scanf("%s",buf);
				if (!strcmp(buf,"exit")) exit(-1);
			} while (buf[0] < 'a' || buf[0] > 'h' || buf[1] < '1' || buf[1] > '8' );
			i = buf[0]-97;
			j = buf[1]-48;
			--j;
		switch (s[i][j]) {
			case TURRET:
				goto sh1;
				break;
			default:
				if (n == 0)
					printf("1st turret placed!!!\n");
				else if (n == 1) 
					printf("2nd turret placed!!!\n");
				else if (n == 2) 
					printf("3rd turret placed!!!\n");
				else 
					printf("%dth turret placed!!!\n",n+1);				
				s[i][j] = TURRET;
				break;			
		}
	}
	
	printf("Please wait while I place my turrets\n\n");
	for(n=0;n<10;n++) {
		sh:
		srand((unsigned)time(NULL)+47);
		i = rand() % 8;
		srand(time(NULL)+43223);
		j = rand() % 8;
		switch (b[i][j]) {
			case TURRET:
				goto sh;
				break;
			default:
				if (n == 0)
					printf("1st turret placed!!!\n");
				else if (n == 1) 
					printf("2nd turret placed!!!\n");
				else if (n == 2) 
					printf("3rd turret placed!!!\n");
				else 
					printf("%dth turret placed!!!\n",n+1);				
				b[i][j] = TURRET;
				break;			
		}
	}
	for (n = 1; n <= 2*8*8 ; n++) {
		if (n%2==1) {
			gprintf (s, b, n,sh1,sh2);
			set:
			do { 
				printf("Choose place to drop bombs\n>>> ");
				scanf("%s",buf);
				if (!strcmp(buf,"exit")) exit(-1);
			} while (buf[0] < 'a' || buf[0] > 'h' || buf[1] < '1' || buf[1] > '8' );
			i = buf[0]-97;
			j = buf[1]-48;
			--j;
			switch (b[i][j]) {
				case TURRET:
					printf("You got my turret in place %c%d\n\n",i+97,j+1);
					b[i][j] = HIT;				
					if (--sh2 == 0) {
						gprintf(s,b,n,sh1,sh2);
						printf("\n\nThe game is over! Congratulations!!! You are the winner!!!!\n\n");
						printf("Would you like to play again??? (yes/no)\n>>> ");
						fflush(stdin);
						scanf("%s",buf);
						if (!strcmp(buf,"yes")) main();
						else {
							system("clear");
							printf("Thanks for playing Turrets v0.1\n\n");
							exit(0);
						}
					}
					break;
				case PLAIN:
					printf("Sorry... You got nothing!\n\n");
					b[i][j] = MISSED;
					break;
				default:
					goto set;
					break;
			}
		}
		if (n%2==0) {
			gprintf(s,b,n,sh1,sh2);
			printf("It's my turn\n\n");
			do {
				srand((unsigned)time(NULL)+342);
				i = rand() % 8;
				srand(time(NULL)+21321);
				j = rand() % 8;
			} while (s[i][j] == HIT || s[i][j] == MISSED);
			switch (s[i][j]) {
				case TURRET:
					printf("Haha... I got you in place %c%d\n\n",i+97,j+1);
					s[i][j] = HIT;
					if (--sh1 == 0) {
						system("clear");
						gprintf(s,b,n,sh1,sh2);
						printf("\n\nThe game is over! I am the winner!!!!\n\n");
						printf("Would you like to play again??? (yes/no)\n>>> ");
						fflush(stdin);
						scanf("%s",buf);
						if (!strcmp(buf,"yes")) main();
						else {
							system("clear");
							printf("Thanks for playing Turrets v0.1\n\n");
							exit(0);
						}
					}
					break;
				case PLAIN:
					printf("Oh no... Plain land!\n\n");
					s[i][j] = MISSED;
					break;
			}
		}
	}
	return 0;
}
