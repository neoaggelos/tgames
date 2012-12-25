#include "mastermind.h"

int main(int argc,char** argv) {
	int n,k,l,pc,ch,**guess,*code;
	char c,buf[15];
	struct results r;
	getargs(argc,argv,&pc,&ch);
	guess=(int**)malloc(9*sizeof(int*));
	for (k=0;k<9;k++) {
		guess[k]=(int*)malloc(4*sizeof(int));
	}
	code=(int*)malloc(4*sizeof(int));
	printf("Mastermind basic rules -- Please read\n");
	printf("-------------------------------------\n");
	printf(">>> Mastermind is meant to be played by 2 players\n");
	printf(">>> The one has a range of 8 different colors to create\n");
	printf(">>> a 4-color \'code\',without using a color more than\n");
	printf(">>> once. The other player is the \'code-breaker\'. He\n");
	printf(">>> has 9 tries to break the code. Breaking the code means\n");
	printf(">>> finding all colors and putting them in the correct order\n");
	printf(">>> After each guess the \'code-maker\' informs him about his\n");
	printf(">>> progress. That means he tells the second player how many\n");
	printf(">>> of the colors are used in the code and how many of them are\n");
	printf(">>> in the correct place.\n");
	printf(">>> In this game, instead of 8 colors, we use 8 numbers (1 to 8)\n");
	printf(">>> Also the computer informs the 'code-breaker' about his progress\n\n");
	printf(">>> Happy mastermind gaming!!!!\n"); 
	if (ch==0) {
		pc=1;
		printf("Do you want the want the computer to generate a code?(<y>/n)\n");
		c='y';
		c=getchar();
		if (c=='n') pc=0;
	}
	code=createcode(pc);
	printf("Code generated!!!\n");
	for (n=0;n<200;n++) printf("\n");
	printf("Code * * * *\n");
	for (n=0;n<9;n++) {
		do {
			ch=0;
			printf("%d  > ",n+1);
			for (k=0;k<4;k++) {
				scanf("%d",&(guess[n][k]));
			}
			for (k=0;k<4;k++) {
				if (guess[n][k]<1 || guess[n][k]>8) {
					printf("Invalid guess\nPlease re-enter\n");
					ch=1;
				}
				for (l=0;l<k;l++) {
					if (guess[n][l]==guess[n][k]) {
						printf("Invalid guess\nPlease re-enter\n");
						ch=1;
					}
				}
			}
		} while(ch==1);
		r=getres(code,guess[n]);
		if (r.r==4) {
			printf("Congatulations! You broke the code with %d tries\n Your score was %d\n",n+1,9-n);
			printf("Would you like to play again?(yes/no)\n> ");
			while(1) {
				scanf("%s",buf);
				if (!strcmp("yes",buf)) {
					main(argc,argv);
				}
				if (!strcmp("no",buf)) {
					printf("Thank you for playing mastermind!\n\n");
					return 0;
				}
				else {
					printf("You have to fully type \'yes\' or \'no\'\n> ");
				}
			}			
		}
		if (n==8) {
			printf("Too bad... You lost...\n");
			printf("The code was ");
			for (k=0;k<4;k++) {
				printf("%d ",code[k]);
			}
			while(1) {
				scanf("%s",buf);
				if (!strcmp("yes",buf)) {
					main(argc,argv);
				}
				if (!strcmp("no",buf)) {
					printf("Thank you for playing mastermind!\n\n");
					return 0;
				}
				else {
					printf("You have to fully type \'yes\' or \'no\'\n> ");
				}
			}			
		}
		else {
			printf("You have %d correct colors and %d of them are in the correct place!\n",r.w,r.r);
		}
	}
	return 0;
} 		
