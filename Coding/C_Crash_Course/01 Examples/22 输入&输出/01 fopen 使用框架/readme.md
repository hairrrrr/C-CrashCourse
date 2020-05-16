下面给出了一个程序的框架。此程序打开文件 example.dat 进行读操作，并检查打开是否成功，让后在程序终止前把文件关闭：

可以将 fp 的声明与函数调用结合：

```c
FILE* fp = fopen(FILE_NAME, "r");
```

还可以将函数调用与 NULL 判定结合：

```c
if((fp = fopen(FILE_NAME, "r")) == NULL) ...
```


