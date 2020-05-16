#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {

	FILE* fp;

	if (argc != 2) {
		printf("usage: canopen filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL) {
		printf("%s can't be opend.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	printf("%s can be opend.\n", argv[1]);
	
	fclose(fp);
	
	return 0;
}
