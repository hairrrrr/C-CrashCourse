#### 程序：核对行星的名字

设计一个程序检查一系列字符串，从而找出那些字符串是行星的名字。执行程序时，用户把待测试的字符串放置在命令行中：

```c
planet Mercury Aotoman Pluto Thebug  Earth
```

程序会指出每个字符串是否为行星名。如果是，程序还将显示行星的编号：

```c
Mercury is a planet 1
Aotoman is not a planet
Pluto is a planet 9
Thebug is not a planet
Earth is a planet 3
```

**注意：**命令行输入的第一个参数 planet 是 c 程序编译出的可执行程序名。一般一个叫 x.c 的程序编译后的可执行程序就叫做 x 。

我们命名这个 c 程序为 planet.c 所以编译后的可执行文件应该叫做 planet （在 Windows 上后缀应该为 .exe）