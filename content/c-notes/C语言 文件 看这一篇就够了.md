**想看更好排版，可以看原文**
[点击看原文](https://mp.weixin.qq.com/s/H1Yp5miEf8NP4HdP8OECqg)

![本节思维导图](https://img-blog.csdnimg.cn/20200212165510350.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70)
### 文件
#### 格式化的输入输出
> `printf`
> % [flag] [width] [.prec] [hlL] type
> `scanf`
> % [flag]  type

##### printf
###### **flag 属性一般与 width 属性结合**
| Flag | 含义         |
| ---- | ------------ |
| -    | 左对齐       |
| +    | 在正数放 +   |
| 0    | 在前面填充 0 |

例1
```c
int main(void) {

	printf("%9d\n", 123);
	printf("%-9d\n", 123);
	return 0;
}
```
```
      123
123
```
例2
```c
int main(void) {

	printf("%+9d\n", 123);
	printf("%-9d\n", -123);
	return 0;
}
```
```
     +123
-123
```
**`+` 可以让正数打印出符号，负数的符号自动会打印出来**

例3
```c
int main(void) {

	printf("%+09d\n", 123);
	printf("%-09d\n", -123);
	return 0;
}
```
```
+00000123
-123
```
*有的编译器不允许 `- 0`*这样的语法，因为 `-` 已经表示左对齐了，`0` 就没有意义了

###### width.prec
| width.prec      | 含义                               |
| --------------- | ---------------------------------- |
| number . number | 总共的输出占几位 . 小数点后占几位  |
| `*.*`           | 下一个参数是字符数或小数点后的位数 |

例1
```c
int main(void) {

	printf("%9.2f\n", 12.3);
	printf("%8.4f\n", -12.3);
	return 0;
}
```
```
    12.30
-12.3000
```
例2：融合一下
```c
int main(void) {

	printf("%+09.2f\n", 12.3);
	printf("%-8.3f\n", -12.3);
	return 0;
}
```
```
+00012.30
-12.300
```
**小数点 `.` 也是占位数的**

例3：
```c
int main(void) {

	int len = 5;
	int dec = 2;
	printf("%*.*f\n",5, 2, 12.3);
	printf("%*.*f\n",len, dec, 12.3);
	return 0;
}
```
```
12.30
12.30
```
**给了我们用参数控制格式的途径，可以用变量来改变输出的格式**

###### hlL 格式
| 修饰类型 | 含义        |
| -------- | ----------- |
| hh       | 单个字节    |
| h        | short       |
| l        | long        |
| ll       | long long   |
| L        | long double |
```c
int main(void) {

	printf("%hhd\n", (char)12345);//当作 1 个字节输出(最低为作为 char 输出)
	printf("%hd\n", 12345);//当作 short 输出
	return 0;
}
```
12345 的 16 进制数是：3039
39 的十进制是 57
```
57
12345
```
##### 格式
| type | 表示           | type | 表示            |
| ---- | -------------- | ---- | --------------- |
| i&d  | int            | g    | float           |
| u    | unsigned int   | G    | float           |
| o    | 八进制         | a&A  | 十六进制浮点    |
| x    | 十六进制       | c    | char            |
| X    | 大写的十六进制 | s    | 字符串          |
| f&F  | float          | p    | 指针            |
| e&E  | 指数           | n    | 读入/写出的个数 |

##### scanf  ：% [flag] type
**flag 属性**
| flag | 含义         |
| ---- | ------------ |
| *    | 跳过         |
| 数字 | 最大字符数   |
| hh   | char         |
| h    | short        |
| l    | long ,double |
| ll   | long long    |
| L    | long double  |

例：
```c
int main() {

	int num;
	scanf("%*d %d", &num);
	printf("%d\n", num);

	return 0;
}
```
程序输出如下：
输入：123 456
```c
456
```

**type属性**
| type    | 用于                          |
| ------- | ----------------------------- |
| d       | int                           |
| i       | 整数（10进制，8进制或16进制） |
| u       | unsigned int                  |
| o       | 八进制                        |
| x       | 十六进制                      |
| a,e,f,g | float                         |
| c       | char                          |
| s       | 字符串                        |
| [...]   | 允许的字符                    |
| p       | 指针                          |

#### printf 与 scanf 的返回值
>`scanf`:读入的项目（item）数
>`printf`: 输出的字符数

有什么用？
**再由严格要求的程序中，应该判断每次调用 scanf 或 printf 的返回值，从而了解运行中的程序是否出现了问题**

例如：
```c
int main(void) {

	int num = 0;
	int return_scanf = 0;
	int return_printf = 0;

	return_scanf = scanf("%d", &num);
	return_printf = printf("%d\n", num);

	printf("%d:%d\n", return_scanf, return_printf);
	return 0;
}
```
```c
//输入
1234
//输出
1234
1:5  //回车键要算进去
```
### 文件输入输出
**< 与 > 来重定向**
- `< `重定向输入
- `>` 重定向输出

我们用 linux 操作系统为例：


<div align = "center" font style = "font-size:100px" >
<img src ="https://img-blog.csdnimg.cn/20200211220335414.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70" width = "600" height = "250"  ></img>
<p >1.写一个c文件并完成编译</p>
</div>

<div align = "center" font style = "font-size:100px" >
<img src ="https://img-blog.csdnimg.cn/20200211220423492.png" width = "600" height = "200"  ></img>
<p >2.这是标准的输入输出</p>
</div>

<div align = "center" font style = "font-size:100px" >
<img src ="https://img-blog.csdnimg.cn/20200211222935631.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70" width = "600" height = "200"  ></img>
<p >3.我们先创建一个文件 read.out，并写入 1234</p>
</div>

<div align = "center" font style = "font-size:100px" >
<img src ="https://img-blog.csdnimg.cn/20200211223231641.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70" width = "600" height = "200"  ></img>
<p >4.用 read.out 作为输入，向 write.out 中写入程序运行结果</p>
</div>

###### 用程序打开文件
#### fopen
>`FILE *fopen( const char *filename, const char *mode )`;(C99 前)
>`FILE *fopen( const char *restrict filename, const char *restrict mode )`;(C99 起)
>**头文件**：stdio.h
>**参数**：
>filename	-	关联到文件系统的文件名
>mode	-	确定访问模式的空终止字符串
>**返回值**：
>若成功，则返回指向新文件流的指针。流为完全缓冲，除非 filename 表示一个交互设备。错误时，返回空指针

![](https://img-blog.csdnimg.cn/20200212155233249.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70)
**简单理解**

| r    | 打开只读                                               |
| ---- | ------------------------------------------------------ |
| r+   | 打开读写，从文件头开始                                 |
| w    | 打开只写。如果不存在则新建，如果存在就清空             |
| w+   | 打开读写。如果不存在则新建，如果存在清空               |
| a    | 打开追加。如果不存在则新建，如果存在则从文件尾开始追加 |
| x    | 后附于上面。表示如果文件已存在则不能打开               |

#### fclose
>`int fclose( FILE *stream )`
>**头文件：**stdio.h
>**参数：**
>stream	-	需要关闭的文件流
>**返回值：**
>成功时为 0 ，否则为 EOF 。
>***
>**定义：**
>关闭给定的文件流。冲入任何未写入的缓冲数据到 OS 。舍弃任何未读取的缓冲数据。
>
>无论操作是否成功，流都不再关联到文件，且由 setbuf 或 setvbuf 分配的缓冲区若存在，则亦被解除关联，并且若使用自动分配则被解分配。
>
>若在 fclose 返回后使用指针 stream 的值则行为未定义。

#### scanf系
>·`int scanf( const char          *format, ... )`;(C99 前)
>
>`int scanf( const char *restrict format, ... )`;(C99 起)
>(2)	
>`int fscanf( FILE          *stream, const char          *format, ... )`;(C99 前)
>
>`int fscanf( FILE *restrict stream, const char *restrict format, ... )`;(C99 起)
>(3)	
>`int sscanf( const char          *buffer, const char          *format, ... )`;(C99 前)
>
>`int sscanf( const char *restrict buffer, const char *restrict format, ... )`;(C99 起)
>**定义**
>从各种资源读取数据，按照 format 转译，并将结果存储到指定位置。
>
>1) 从 stdin 读取数据
>
>2) 从文件流 stream 读取数据
>
>3) 从空终止字符串 buffer 读取数据。抵达字符串结尾等价于 fscanf 的抵达文件尾条件
>
>**参数：**
>stream	-	要读取的输入文件流
>
>buffer	-	指向要读取的空终止字符串的指针
>
>format	-	指向指定读取输入方式的空终止字符串的指针。
>
>**返回值：**
>成功赋值的接收参数的数量（可以为零，在首个接收用参数赋值前匹配失败的情况下），者若输入在首个接收用参数赋值前发生失败，则为EOF。

#### printf系
>**头文件：** stdio.h
>(1)
>`int printf( const char *format, ... )`(C99 前)
>
>`int printf( const char *restrict format, ... )`;(C99 起)
>
>(2)	
>
>`int fprintf( FILE *stream, const char *format, ... )`;(C99 前)
>
>`int fprintf( FILE *restrict stream, const char *restrict format, ... );`(C99 起)
>
>(3)	
>
>`int sprintf( char *buffer, const char *format, ... )`;(C99 前)
>
>`int sprintf( char *restrict buffer, const char *restrict format, ... )`;(C99 起)
>
>(4)	
>
>`int snprintf( char *restrict buffer, int bufsz,  const char *restrict format, ... )`;(C99 起)
>
>**定义：**
>从给定位置加载数据，转换为字符串等价物，并写结果到各种池。
>
>1) 写结果到 stdout 。
>
>2) 写结果到文件流 stream 。
>
>3) 写结果到字符串 buffer 。
>
>4) 写结果到字符串 buffer 。至多写 buf_size - 1 个字符。产生的字符串会以空字符终止，除非 buf_size 为零。若 buf_size 为零，则不写入任何内容，且 buffer 可以是空指针，然而依旧计算返回值（会写入的字符数，不包含空终止符）并返回。
>
>**参数：**
>stream	-	要写入的输出文件流
>
>buffer	-	指向要写入的字符串的指针
>
>bufsz	-	最多会写入 bufsz - 1 个字符，再加空终止符
>
>format	-	指向指定数据转译方式的空终止多字节字符串的指针。
>
>**返回值：**
>1,2) 传输到输出流的字符数，或若出现输出错误或编码错误（对于字符串和字符转换指定符）则为负值。
>
>3) 写入到 buffer 的字符数（不计空终止字符），或若输出错误或编码错误（对于字符串和字符转换指定符）发生则为负值。
>
>4) 假如忽略 bufsz 则本应写入到 buffer 的字符数（不计空终止字符），或若出现输出错误或编码错误（对于字符串和字符转换指定符）则为负值。

标准代码：
```c
FILE* fp = fopen("file", "r");

if (fp) {
	fscanf(fp, ...);
	fclose(fp);
}
else {
	...
}
```
例：
![写一个c程序](https://img-blog.csdnimg.cn/20200211232202971.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70)
![测试](https://img-blog.csdnimg.cn/20200211232237160.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQ0OTU0MDEw,size_16,color_FFFFFF,t_70)



#### 二进制文件
##### fread
>`size_t fread( void *restrict buffer, size_t size, size_t count, FILE *restrict stream );`
>定义于头文件 <stdio.h>
>**参数**：
>buffer	-	指向要读取的数组中首个对象的指针
>size	-	每个对象的字节大小
>count	-	要读取的对象数
>stream	-	读取来源的输入文件流
>**返回值**：
>成功读取的对象数，若出现错误或文件尾条件，则可能小于 count 。
>若 size 或 count 为零，则 fread 返回零且不进行其他动作。
>fread 不区别文件尾和错误，而调用者必须用 feof 和 ferror 鉴别出现者为何。
>***
>**定义**：
>从给定输入流 stream 读取至多 count 个对象到数组 buffer 中，如同以对每个对象调用 size 次 fgetc ，并按顺序存储结果到转译为 unsigned char 数组的 buffer 中的相继位置。流的文件位置指示器前进读取的字符数。
>若出现错误，则流的文件位置指示器的结果值不确定。若读入部分的元素，则元素值不确定。

直白点说就是从 一个流（文件）种读取 count 个 size 大小 的对象到 buffer 数组中

成功返回读取的对象数( <= count), 失败返回 0

##### fwrite
>`size_t fwrite( const void *restrict buffer, size_t size, size_t count,
>         FILE *restrict stream );`
>定义于头文件 <stdio.h>
>**参数**：
>buffer	-	指向数组中要被写入的首个对象的指针
>size	-	每个对象的大小
>count	-	要被写入的对象数
>stream	-	指向输出流的指针
>**返回值**：
>成功写入的对象数，若错误发生则可能小于 count 。
>若 size 或 count 为零，则 fwrite 返回零并不进行其他行动。
>***
>**定义**
>写 count 个来自给定数组 buffer 的对象到输出流stream。如同转译每个对象为 unsigned char 数组，并对每个对象调用 size 次 fputc 以将那些 unsigned char 按顺序写入 stream 一般写入。文件位置指示器前进写入的字节数。

###### 程序演示
现在我们想将学生的信息以二进制文本写入到 student.data 文件中

应该如何写这个程序呢？

关注公众号: 不会编程的程序圆  回复[0212 1]
获取程序演示以及程序的详细注释！

#### ftell
>`long ftell( FILE *stream );`
>定义于头文件 <stdio.h>
>**参数**：stream	-	要检验的文件流
>**返回值**：
>成功时为文件位置指示器，若失败发生则为 -1L 。
>失败时，设 errno 对象为实现定义的正值。
>***
>**定义**：
>返回流 stream 的文件位置指示器。
>若流以二进制模式打开，则由此函数获得的值是从文件开始的字节数。
>若流以文本模式打开，则由此函数返回的值未指定，且仅若作为 fseek() 的输入才有意义。

#### fseek
>`int fseek( FILE *stream, long offset, int origin );`
>定义于头文件 <stdio.h>
>**参数**：
>stream	-	要修改的文件流
>offset	-	相对 origin 迁移的字符数
>origin	-	offset 所加上的位置。它能拥有下列值之一： SEEK_SET 、 SEEK_CUR 、 SEEK_END
>**返回值**：
>成功时为 0 ，否则为非零。
>***
>**定义**：
>设置文件流 stream 的文件位置指示器为 offset 所指向的值。
>
>若 stream 以二进制模式打开，则新位置准确地是文件起始后（若 origin 为 SEEK_SET ）或当前文件位置后（若 origin 为 SEEK_CUR ），或文件结尾后（若 origin 为 SEEK_END ）的 offset 字节。不要求二进制流支持 SEEK_END ，尤其是是否输出附加的空字节。
>
>若 stream 以文本模式打开，则仅有的受支持 offset 值为零（可用于任何 origin ）和先前在关联到同一个文件的流上对 ftell 的调用的返回值（仅可用于 SEEK_SET 的 origin ）。
>
>若 stream 为宽面向，则一同应用对文本和二进制流的限制（允许 ftell 的结果与 SEEK_SET 一同使用，并允许零 offset 以 SEEK_SET 和 SEEK_CUR 但非 SEEK_END 为基准）。
>
>除了更改文件位置指示器， fseek 还撤销 ungetc 的效果并清除文件尾状态，若可应用。
>
>若发生读或写错误，则设置流的错误指示器（ ferror ）而不影响文件位置。

>SEEK_SET 从头开始
>SEEK_CUR 从当前位置开始
>SEEK_END 从尾开始

简单的理解：将 stream 指针，从 origin 开始，移动 offset 个字节

比如：`fseek(fp, 100L, SEEK_SET)`

它的意义时，将 fp 指针从 文件头开始移动100个字节

###### 程序演示
上面一个程序我们将学生信息以二进制形式写入到了 student.data 文件中

如何打开这个二进制文件呢？

关注公众号: 不会编程的程序圆  回复[0212 1]
获取程序演示以及程序的详细注释！

###### 可移植性
这一节，我们看了到各种比较复杂的函数，

如`fprintf` `fscanf` `sprintf` `fopen` `fclose` `fread`  `fwrite` 

我们也看到了文本文件的一些操作和二进制文件比较复杂的读写，而且你也不能直接从windows 上读我们到底以二进制的形式向文件内写了什么
>这样的二进制文件不具备可移植性，因为在int 为32为的机器上写成的数据文件无法直接在int为64位的机器上正确读出
>
>解决方案之一是放弃使用int，用typedef具有明确大小的类型
>
>更好的方案是用文本

时至今日，我们已经很少用c语言这种最底层的文件读写方式了，要么用数据库，要么用第三方库

*参考网站：https://zh.cppreference.com/*

