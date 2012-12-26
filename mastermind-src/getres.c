#include "getres.h"

struct results getres(int* code,int *guess) {
	struct results res={0,0};
	int i,j;
	for (i=0;i<4;i++) {
		for (j=0;j<4;j++) {
			if (guess[i]==code[j]) res.w++;
		}
		if (guess[i]==code[i]) res.r++;
	}
	return res;	
}
