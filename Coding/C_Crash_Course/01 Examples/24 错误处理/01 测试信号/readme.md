#### 程序：测试信号

下面的程序说明了如何使用信号。首先，给 SIGINT 信号安装了一个惯用的处理函数(并小心地保存了原先的处理函数)，然后调用`raise_sig` 产生该信号：接下来，程序将 SIG_IGN设置为SIGINT的处理函数并再次调用 raise_sig；最后，它重新安装信号 SIGINT原先的处理函数，并最后调用一次 raise_sig。

**tsignal.c**

```c
#include <signal.h>
#include <stdio.h>

void handler(int sig) ;
void raise_sig(void) ;

int main(void){

	void (*orig_handler) (int);
    
	printf("Installing handler for signal %d\n"， SIGINT) ;

	orig_ handler = signal(SIGINT, handler);
	raise_sig();
    
	printf("Changing handler to SIG_IGN\n");
	signal (SIGINT, SIG_IGN) ;
	raise_ sig();
    
	printf("Restoring original handler\n");
	signal (SIGINT, orig_handler);
	raise_ sig();

	printf("Program terminates normally\n");
	return 0
}

void handler(int sig){
	printf("Handler called for signal ad\n", sig);
}

void raise_sig(void){
	raise (SIGINT);
}
```



当然，调用 raise 并不需要在单独的函数中。这里定义 raise_sig 函数只是为了说明一点：无论信号是从哪里产生的(无论是在main函数中还是在其他函数中)，它都会被最近安装的该信号的处理函数捕获。

这段程序的输出可能会有多种。下面是一 种可能的输出形式:

```
Installing handler for signal 2
Handler called for signal 2
Changing handler to SIG_IGN
Restoring original handler
```

这个输出结果表明，我们的实现把 SIGINT 的值定义为 2，而且 SIGIN原先的处理函数一定是 SIG_DFL。(如果是 SIG_IGN，应该会看到信息 Program terminates normally) 最后， 我们注意到 SIG_DFL 会导致程序终止，但不会显示出错消息。