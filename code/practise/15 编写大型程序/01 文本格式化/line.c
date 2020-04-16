#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include"line.h"

#define MAX_LINE_LEN 60 // 每行的最大字符数

char line[MAX_LINE_LEN + 1]; 
int line_len = 0; // 当前行长度
int num_words = 0; // 当前行的单词数

void clear_line() {
	
	line[0] = '\0';
	line_len = 0;
	num_words = 0;
}

void add_word(const char* word) {

	// 非首个单词,需要在上一个单词后添加空格
	if (num_words > 0) {
		line[line_len] = ' ';
		line[line_len + 1] = '\0';
		line_len++;
	}

	strcat(line, word);
	line_len += strlen(word);
	num_words++;
}

int space_remaining() {
	
	return MAX_LINE_LEN - line_len;
}


void write_line() {

	int extra_space, spaces_to_insert, i, j;

	extra_space = MAX_LINE_LEN - line_len; // 当前行未被填满的字符数
	for (i = 0; i < line_len; i++) {
		if (line[i] != ' ')
			putchar(line[i]);
		else {
			spaces_to_insert = extra_space / num_words; // 遵循这个公式来增加空格
			for (j = 0; j <= spaces_to_insert; j++) // 使用 = 确保至少打印一个
				putchar(' ');
			extra_space -= spaces_to_insert;
			num_words--;
		}
	}
	putchar('\n');
}

void flush_line(void) {

	if (line_len > 0)
		puts(line);
}
