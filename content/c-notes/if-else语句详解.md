
**关于 if else 选择结构 的两种写法：**
```c
if () {
	;
}
if () {
	;
}
if () {
	;
}
else {
	;
}


if () {
	;
}
else if () {
	;
}
else if () {
	;
}
else {
	;
}
```
上面两种写法有区别吗？

直接看程序吧：
####  多个if 直接并列
```c
int main() {

	int a = 5;
	
	if (a > 0)
		printf("a > 0\n");
	if (a > 2)
		printf("a > 2\n");
	if (a > 4)
		printf("a > 4\n");
	if (a > 5)
		printf("a > 5\n");
	else
		printf("a < 5\n");

	return 0;
}
```
输出：
```c
a > 0
a > 2
a > 4
a < 5
```
#### 多个else if 并列
```c
int main() {

	int a = 0;
	
	if (a > 0)
		printf("a > 0\n");
	else if (a > 2)
		printf("a > 2\n");
	else if (a > 4)
		printf("a > 4\n");
	else if (a > 5)
		printf("a > 5\n");
	else
		printf("a < 5\n");

	return 0;
}
```
输出：
```c
a > 0
```

### 总结
- 多个if 并列 程序会遍历所有的 if 条件。最后一个 else 与最后一个 if 配对，两者必有一个为真
- 多个 else if 并列 程序只要找到一个 真，就会退出整个 “条件体”。最后一个else 与 前面的任意一个语句 必有一个为真。
- 关于else：
    * 第一种：else 与 最后一个 if 形成对立
    * 第二种：else 与 除 else 外的整体形成对立