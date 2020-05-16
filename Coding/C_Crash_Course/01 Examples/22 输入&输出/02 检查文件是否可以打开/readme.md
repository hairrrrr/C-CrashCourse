#### 程序：检查文件是否可以打开

下面程序判断文件是否存在，如果存在是否可以打开进行读入。在运行程序时，用户给出要检查的文件的名字：

```c
canopen file
```

然后程序将显示 ：

```
file can be opend.
或
file can't be opend.
```

如果在命令行中录入的实际参数的数量不对，那么程序将显示出消息：

```
usage: canopen filename
```

来提示用户 canopen 需要一个文件名。