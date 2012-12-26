#include "makecode.h"

int* createcode(int pc) {
	int i,j,false,value,*code;
	code=(int*)malloc(4*sizeof(int));
	if (pc==1) {
		srand((unsigned)time(NULL));
		i=rand()%30;
		switch(i) {
			case 0:
				code[0]=1;
				code[1]=4;
				code[2]=6;
				code[3]=2;
				break;
			case 1:
				code[0]=4;
				code[1]=7;
				code[2]=2;
				code[3]=1;
				break;
			case 2:
				code[0]=6;
				code[1]=8;
				code[2]=1;
				code[3]=5;
				break;
			case 3:
				code[0]=4;
				code[1]=8;
				code[2]=5;
				code[3]=1;
				break;
			case 4:
				code[0]=3;
				code[1]=7;
				code[2]=4;
				code[3]=6;
				break;
			case 5:
				code[0]=1;
				code[1]=7;
				code[2]=3;
				code[3]=6;
				break;
			case 6:
				code[0]=1;
				code[1]=2;
				code[2]=3;
				code[3]=4;
				break;
			case 7:
				code[0]=5;
				code[1]=3;
				code[2]=8;
				code[3]=2;
				break;
			case 8:
				code[0]=4;
				code[1]=2;
				code[2]=6;
				code[3]=8;
				break;
			case 9:
				code[0]=1;
				code[1]=5;
				code[2]=7;
				code[3]=3;
				break;
			case 10:
				code[0]=3;
				code[1]=5;
				code[2]=1;
				code[3]=2;
				break;
			case 11:
				code[0]=6;
				code[1]=4;
				code[2]=8;
				code[3]=2;
				break;
			case 12:
				code[0]=1;
				code[1]=5;
				code[2]=2;
				code[3]=8;
				break;
			case 13:
				code[0]=1;
				code[1]=5;
				code[2]=3;
				code[3]=7;
				break;
			case 14:
				code[0]=4;
				code[1]=6;
				code[2]=2;
				code[3]=3;
				break;
			case 15:
				code[0]=3;
				code[1]=5;
				code[2]=6;
				code[3]=1;
				break;
			case 16:
				code[0]=5;
				code[1]=3;
				code[2]=1;
				code[3]=2;
				break;
			case 17:
				code[0]=4;
				code[1]=2;
				code[2]=1;
				code[3]=3;
				break;
			case 18:
				code[0]=5;
				code[1]=3;
				code[2]=8;
				code[3]=7;
				break;
			case 19:
				code[0]=4;
				code[1]=3;
				code[2]=8;
				code[3]=7;
				break;
			case 20:
				code[0]=1;
				code[1]=3;
				code[2]=6;
				code[3]=8;
				break;
			case 21:
				code[0]=4;
				code[1]=3;
				code[2]=6;
				code[3]=1;
				break;
			case 22:
				code[0]=3;
				code[1]=5;
				code[2]=7;
				code[3]=2;
				break;
			case 23:
				code[0]=4;
				code[1]=6;
				code[2]=3;
				code[3]=5;
				break;
			case 24:
				code[0]=1;
				code[1]=3;
				code[2]=5;
				code[3]=2;
				break;
			case 25:
				code[0]=4;
				code[1]=6;
				code[2]=8;
				code[3]=3;
				break;
			case 26:
				code[0]=1;
				code[1]=3;
				code[2]=5;
				code[3]=4;
				break;
			case 27:
				code[0]=1;
				code[1]=4;
				code[2]=2;
				code[3]=3;
				break;
			case 28:
				code[0]=4;
				code[1]=5;
				code[2]=6;
				code[3]=7;
				break;
			case 29:
				code[0]=7;
				code[1]=5;
				code[2]=3;
				code[3]=1;
		}	
	}
	else {
		do {
			false=0;
			printf("Give code: (e.g. 5 4 1 2)\n--->>");
			for (i=0;i<4;i++){ 
				scanf("%d",&(code[i]));
			}
			for (i=0;i<4;i++) {
				if (code[i]<1 || code[i]>8) { 
					printf("Invalid code\nPlease re-enter\n");
					false=1;
				}
				for (j=0;j<i;j++) {
					if (code[j]==code[i]) {
						printf("Invalid code\nPlease re-enter\n");
						false=1;
					}
				}
			}
		} while(false==1);		
	}
	return code;
}
