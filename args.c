#include "args.h"

void getargs(int argc,char** argv,int* pc,int* ch) {
	int i;
	*pc=*ch=0;
	for (i=0;i<argc;i++) {
		if (!strcmp(argv[i],"--play-with-computer") || !strcmp(argv[i],"-c")) {
			*pc=1; *ch=1;
		}
	}
}
