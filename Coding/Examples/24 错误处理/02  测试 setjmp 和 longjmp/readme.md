#### 程序测试setjmp和1ongjmp

下面的程序使用 setjmp 宏在 main 函数中标记一个位置，然后函数 f2 通过调用 1ongjmp 函数返回到这个位置。

**tsetjmp.c**

```c
/* Tests setjmp/1ongjmp */
#include<setjmp.h>
#include<stdio.h>

jmp_buf env;

void f1(void);
void f2(void);

int main(void) {

	if (setjmp(env) == 0)
		printf("setjmp returned 0\n");
	else {
		printf("Program terminates: longjmp called\n");
		return 0;
	}

	f1();
	printf("Program terminates normally\n");
	
	return 0;
}
void f1(void) {
	printf("f1 begins\n");
	f2();
	printf("f1 returs\n");
}
void f2(void) {
	printf("f2 begins\n");
	longjmp(env, 1);
	printf("f2 returns\n");
}
```

这段程序的输出如下:

```
setjmp returned 0
f1 begins
f2 begins
Program terminates: longjmp called
```

setjmp 宏的最初调用返回 0，因此main函数会调用 f1。接着，f1 调用 f2，f2 使用1ongjmp 函数将控制权重新转给 main 函数，而不是返回到 f1 。当 longjmp 函数被执行时，控制权重新回到 setjmp 宏调用。这次 setjmp宏返回 1  (就是在longjmp函数调用时所指定的值)。