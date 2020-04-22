#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define FILE_NAME "example.dat"

int main(void) {

	FILE* fp;
	
	fp = fopen(FILE_NAME, "r");
	if (fp == NULL) {
		printf("Can't open %s\n", FILE_NAME);
		exit(EXIT_FAILURE);
	}
	
	// Ö´ÐÐ²Ù×÷

	fclose(fp);

	return 0;
}

// FILE* fp = fopen(FILE_NAME, "r");
// if((fp = fopen(FILE_NAME, "r")) == NULL) ...
