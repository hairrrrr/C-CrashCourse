#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<ctype.h>

#define KEY '&'

int main(void) {

	int orig_ch, new_ch;

	while ((orig_ch = getchar()) != EOF) {
		new_ch = orig_ch ^ KEY;
		if (isprint(orig_ch) && isprint(new_ch))
			putchar(new_ch);
		else
			putchar(orig_ch);
	}

	return 0;
}
