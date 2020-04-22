#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>
#include"word.h"
#include"line.h"

#define MAX_WORD_LEN 20  //每个单词的最大长度

int main(void) {

	char word[MAX_WORD_LEN + 2];
	int word_len;

	clear_line();
	for (;;) {
		// 允许 read_word 函数多读 1 个字符，多读则代表单词长度超过 20，需要截断
		read_word(word, MAX_WORD_LEN + 1);
		word_len = strlen(word);
		if (word_len == 0) {
			flush_line();
			return 0;
		}
		// 截断超过 20 个字符的单词
		if (word_len > MAX_WORD_LEN)
			word[MAX_WORD_LEN] = '*';
		// + 1 是因为需要在上一个单词后添加空格。
		// 如果满足条件，则需要输出当前行并清空当前行
		if (word_len + 1 > space_remaining()) {
			write_line();
			clear_line();
		}
		add_word(word);
	}

	return 0;
}
