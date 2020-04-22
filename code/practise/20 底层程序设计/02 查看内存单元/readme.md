#### 程序：查看内存单元

这个程序允许用户查看计算机内存段，这主要得益于 C 允许把整数用作指针。大多数 CPU 执行程序时都是处于“保护模式”，这就意味着程序只能访问那些分配给它的内存。这种方式还可以阻止对其他应用程序和操作系统本身所占用的内存的访问。因此我们只能看到程序本身分配到的内存，如果要对其他内存地址进行访问将导致程序崩溃。

程序 veiw_memory.c 先显示了该程序主函数和主函数中第一个变量的地址，这样可以给用户一个线索去了解那个内存可以被探测。程序接下来提示用户输入地址（16 进制格式）和需要查看的字节数，然后从指定地址开始显示指定字节内存块的内容。

字节按 10 个一组的方式显示（最后一组可能达不到 10 个）。每组字节的首地址显示在一行的开头，然后是该组的字节（16 进制格式），再后面为该组字节的字符显示。只有打印字符（使用 `isprint`函数判断）会被显示，其余的被显示为 `.`。

假设 int 类型大小为 32 位，地址也是 32 位长。

格式如下：

```
Address of main function: 5712bc
Address of addr variable: bcf784

Enter a (hex)address: 5712bc
Enter number of bytes to view: 40

  Address             Bytes               Characters
----------------------------------------------------
  5712BC  E9 6F 06 00 00 E9 EA 04 00 00   .o........
  5712C6  E9 45 22 00 00 E9 50 3F 00 00   .E"...P?..
  5712D0  E9 FB 0C 00 00 E9 A6 27 00 00   .......'..
  5712DA  E9 14 3E 00 00 E9 AC 1E 00 00   ..>.......
```

.

```
Address of main function: 5712bc
Address of addr variable: effbc8

Enter a (hex)address: effbc8
Enter number of bytes to view: 64

  Address             Bytes               Characters
----------------------------------------------------
  EFFBC8  C8 FB EF 00 CC CC CC CC 99 76   .........v
  EFFBD2  90 86 F4 FB EF 00 63 24 57 00   ......c$W.
  EFFBDC  01 00 00 00 F8 4F 2E 01 B0 70   .....O...p
  EFFBE6  2E 01 01 00 00 00 F8 4F 2E 01   .......O..
  EFFBF0  B0 70 2E 01 50 FC EF 00 B7 22   .p..P...."
  EFFBFA  57 00 1D 71 90 86 48 13 57 00   W..q..H.W.
  EFFC04  48 13 57 00                     H.W.

```

（前 4 个字节是我们输入的表示地址的整数，注意它的每个字节存储顺序）