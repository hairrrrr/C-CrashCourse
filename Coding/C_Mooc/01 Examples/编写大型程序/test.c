#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//全局变量

int f(void);

int gAll = 12;

int main(void){
	
	//__func__ 可以打印出当前函数的函数名，下划线一边是两个
	printf("in %s gAll = %d\n", __func__, gAll);
	f();
	printf("again in %s gAll = %d\n", __func__, gAll);

	return 0;
}

int f(void) {
	
	printf("in %s gAll = %d\n", __func__, gAll);
	gAll += 2;
	printf("again in %s gAll = %d\n", __func__, gAll);

	return gAll;
}

int gAll = 12;
int g = gAll;

int main(void) {

	return 0;
}

const int gAll = 12;
int g = gAll;

int main(void) {

	return 0;
}

int f(void);

int gAll = 12;

int main(void) {
	
	int gAll = 2;

	printf("in %s gAll = %d\n", __func__, gAll);

	f();

	printf("again in %s gAll = %d\n", __func__, gAll);

	return 0;
}

int f(void) {
	
	printf("in %s gAll = %d\n", __func__, gAll);
	gAll += 2;
	printf("again in %s gAll = %d\n", __func__, gAll);

	return gAll;
}

int f(void);

int main(void) {

	f();
	f();
	f();

	return 0;
}

int f(void) {

	static int All = 1;
	printf("in %s All = %d\n", __func__, All);
	All += 2;
	printf("again in %s All = %d\n", __func__, All);

	return All;
}

int f(void);

int gAll = 12;

int main(void) {

	printf("1 st\n");
	f();
	printf("2 nd\n");
	f();

	return 0;
}

int f(void) {
	
	int a = 0;
	int b = 0;
	static int All = 1;

	printf("&All :  %p\n", &All);
	printf("&gAll:  %p\n", &gAll);
	printf("&a :    %p\n", &a);
	printf("&b :    %p\n", &b);

	return All;
}

int* f(void);
void g(void);

int main(void) {

	int* p = f();
	printf("*p = %d\n", *p);
	g();
	printf("*p = %d\n", *p);

	return 0;
}

int* f(void) {

	int i = 12;

	return &i;
}
void g(void) {

	int k = 24;
	
	printf("k = %d\n", k);

	return k;
}

编译预处理 与 宏

#include<stdio.h>

const double PI = 3.14159;

int main(void) {

	printf("%f\n", 2 * PI * 3.0);
	return 0;
}

#include<stdio.h>

#define PI  3.14159
//注意：不写分号 不写等于号

int main(void) {

	printf("%f\n", 2 * PI * 3.0);
	return 0;
}

int main(void) {

	printf("%s : %d\n", __FILE__, __LINE__);
	printf("%s %s\n", __DATE__, __TIME__);

	return 0;
}

#define cube(x) ((x) * (x) * (x))

int main(void) {

	printf("%d\n", cube(5));
	return 0;
}

#define ERROR1(x) (x * 57)
#define ERROR2(x) (x) * 57

int main(void) {
	
	int i = 1;
	printf("%d\n", ERROR1(i + 2));
	printf("%d\n", 300 / ERROR2(1));

	return 0;
}

#define PRETTY_PRINT(msg) printf(msg);

int main(void) {

	int n = 0;

	printf("Input an number\n");
	scanf("%d", &n);

	if (n < 10)
		PRETTY_PRINT("less than 10\n");
	else
		PRETTY_PRINT("more than 10\n");

	return 0;
}

#include<stdio.h>
#include<string.h>

#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))

int main(void) {

	int i = 0;
	char s[1000];
	strcpy(s, "abcd");
	putchar(TOUPPER(s[++i]));

	return 0;
}

大程序结构


