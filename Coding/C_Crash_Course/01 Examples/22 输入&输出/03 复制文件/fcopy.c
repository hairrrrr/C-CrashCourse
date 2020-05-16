#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {

	FILE* src_fp, * dest_fp;
	int ch;

	if (argc != 3) {
		fprintf(stderr, "usage: fcopy source dest\n");
		exit(EXIT_FAILURE);
	}

	if ((src_fp = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
		fprintf(stderr, "Can't open file %s\n", argv[2]);
		fclose(src_fp);
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(src_fp)) != EOF)
		putc(ch, dest_fp);

	fclose(src_fp);
	fclose(dest_fp);

	return 0;
}