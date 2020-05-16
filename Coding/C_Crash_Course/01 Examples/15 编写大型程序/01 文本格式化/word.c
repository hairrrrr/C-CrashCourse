#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include"word.h"

// 解决换行符和制表符问题
int read_char(void) {

	int ch = getchar();

	if (ch == '\n' || ch == '\t')
		return ' ';

	return ch;
}

void read_word(char* word, int len) {

	int ch, i;

	while ((ch = read_char()) == ' ')
		;

	i = 0;
	while (ch != ' ' && ch != EOF) {
		if (i < len)
			word[i++] = ch;

		ch = read_char();
	}

	word[i] = '\0';
}
