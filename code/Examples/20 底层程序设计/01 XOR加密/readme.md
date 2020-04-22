#### 程序：XOR 加密

对数据加密的一种最简单的方法就是，将每个字符与一个密钥进行异或（XOR）运算。假设密钥时一个 & 字符。如果将它与字符 z 异或，我们会得到 \ 字符（假定字符集位 ACSII 字符集）。具体计算如下：

```c
	00100110 (& 的 ASCII 码)
XOR 01111010 (z 的 ASCII 码)
    01011100 (\ 的 ASCII 码)
```

要将消息解密，只需要采用相同的算法。例如，如果将 & 与 \ 异或就可以得到 &：

```c
	00100110 (& 的 ASCII 码)
XOR 01011100 (\ 的 ASCII 码)
    01111010 (z 的 ASCII 码)
```

下面的程序 xor.c 通过每个字符于 & 字符进行异或来加密消息。原始消息可以由用户输入也可以输入重定向从文件读入。加密后的消息可以在屏幕上显示也可以通过输出重定向存入到文件中。例如 msg 文件包含以下内容：

```
If two people write exactly the same program, each should be put in
micro-code and then they certainly won't be the same.
					-- epigrams-on-programming
					Time:4/21/2020
```

为了对文件 msg 加密并将加密后的消息存入文件 newmsg 中，输入以下命令：

```c
xor <msg >newmsg
```

文件 newmsg 将包含下面的内容：

```
o@ RQI VCIVJC QTORC C^GERJ_ RNC UGKC VTIATGK, CGEN UNISJB DC VSR OH
KOETI-EIBC GHB RNCH RNC_ ECTRGOHJ_ QIH'R DC RNC UGKC.
					-- CVOATGKU-IH-VTIATGKKOHA
					rOKC:4/21/2020
```

要恢复原始消息，需要命令：

```c
xor <newmsg
```

将原始消息显示在屏幕上。

正如例子中看到的那样，程序不会改变一些字符，包括数字。将这些字符于 & 异或会产生不可见的控制字符，这在一些操作系统中会引发问题。在这里，为了安全起见，我们使用 `isprint`函数来确保原始字符和新字符都是可打印字符（即不是控制字符）。如果不满足，让程序写原始字符，而不是新字符。