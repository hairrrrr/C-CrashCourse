#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

int main(void) {

	char ch = -1;

	int a = 0;

	a = putchar(ch);

	printf("\n%d", a);

	return 0;

}

int main(void) {

	int ch;

	while ((ch = getchar()) != EOF) {
		putchar(ch);
	}

	printf("EOF\n");

	return 0;
}

int main() {

	char str[] = { 'H', 'E', 'L', 'L', 'O', };

	printf("%d\n", strlen(str));

	printf("%d\n", strnlen_s(str, (size_t)sizeof(str)));

	return 0;
}

int test(const char* str) {

	str++;
	*str = '1';
}

int main() {

	char str[] = { 'H', 'I', '!' };

	str++;

	printf("%d\n", test(str));

	return 0;
}

int mystrlen(const char* str) {

	char* end = str;

	while (*end++);

	//退出while循环时，多加了一次 1
	return end - str - 1;

}

int main() {

	char* str = "Hello World!";

	printf("%d\n", mystrlen(str));

	return 0;
}

int mystrcmp(char* str1, char* str2) {

	int ret = 0;

	while ((ret = ((unsigned char)*str1 - (unsigned char)*str2)) == 0 && *str1) {
		++str1, ++str2;
	}

	return ret;
}

UINT_MAX

int main() {

	char* str1 = "abc ";
	char* str2 = "abc";

	printf("%d\n", mystrcmp(str1, str2));

	return 0;
}

int main() {

	char* str1 = NULL;
	char* str2 = "Hello";

	printf("%d\n", strcmp(str1, str2));
	printf("%d\n", strncmp(str1, str2, 1));

	return 0;
}

int mystrcmp(char* str1, char* str2) {

	while (*str1 == *str2 && *str1)
		++str1, ++str2;

	return (*str1 - *str2);
}

int main() {

	char* str1 = "Hello ";
	char* str2 = "Hello";

	printf("%d\n", mystrcmp(str1, str2));

	return 0;
}

int main() {

	char* str1 = "Hello";
	char* str2 = "Hello";

	//strcpy(str1, str2);
	strncpy(str1, str2, 5);

	puts(str1);

	return 0;
}

int main() {

	char str1[] = "Hello";
	char str2[] = "Hello";

	//strcpy(str1, str2);
	strncpy(str1, str2, 6);

	puts(str1);

	return 0;
}

int main() {

	char str1[] = "hello";
	char str2[] = "hello world";

	strcpy(str1, str2);
	//strncpy(str1, str2, 5);

	puts(str1);

	return 0;
}


int main() {

	char* str1 = "Hello";
	char* str2 = "Hello World";

	strcpy(str1, str2);
	strncpy(str1, str2, 12);

	puts(str1);

	return 0;
}
int main() {

	char str1[] = "Hello World";
	char str2[] = { 'H', 'e', 'l','l', 'o' };

	strncpy(str1, str2, 10);

	puts(str1);

	return 0;
}

int main() {

	char str1[] = "Hello World";
	char str2[] = "World";

	//strncpy(str1, str2, 10);
	strcpy(str1, str2);
	puts(str1);

	return 0;
}

#include<assert.h>

char* mystrcpy(char* str1, char* str2) {

	assert(str1 != NULL && str2 != NULL);
	assert(strlen(str1) >= strlen(str2));

	//核心代码从这里开始， 上面的不懂可以加QQ群问我（群在我公众号关注回复的消息里）
	char* after = str1;

	while (*str1++ = *str2++);

	return after;
}

int main() {

	char* str1 = "HI!!!";
	char* str2 = "Hello";

	mystrcpy(str1, str2);
	puts(str1);

	return 0;
}

int main() {

	char str1[11] = "Hello";
	char str2[3] = { 'J', 'I', 'M' };

	strcat(str1, str2);
	puts(str1);

	return 0;
}

int main() {

	char str2[3] = { 'J', 'I', 'M' };
	char str1[3] = "JIM";


	printf("%d\n", strcmp(str1, str2));


	return 0;
}

int main() {

	char str1[8] = "hi";
	char str2[4] = "you";

	strncat(str1, str2, 5);
	puts(str1);

	return 0;
}

char* mystrcat(char* str1, char* str2) {

	while (str1[strlen(str1)] = *str2++);

	return str1;
}

int main() {

	char str1[8] = "Hi";
	char str2[4] = "YOU";

	mystrcat(str1, str2);
	puts(str1);

	return 0;
}
