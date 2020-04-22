#### 程序：维护零件数据库

此程序用来维护仓库存储的零件信息的数据库。程序围绕一个结构数组构建，且每个结构包含以下信息：零件编号，名称和数量。程序将支持下列操作：

- **添加新零件信息**。如果零件已经存在，或数据库已满，显示出错信息。
- **给定零件编号，显示零件的名称，数量信息**。如果零件编号不存在，那么给出出错信息。
- **给定零件编号，改变零件的数量**。如果零件编号不存在，给出出错消息。
- **显示列出数据库中的全部信息**。零件必须按照录入顺序显示。
- **终止程序的执行**

使用：

- `i`:插入
- `s`:搜索
- `u`:更新
- `p`:显示
- `q`:退出

分表表示这种操作，与程序得到会话如下：

```c
Enter operation code: i
Enter part number: 833
Enter part name: Disk Drive
Enter quantity on hand: 90
Enter operation code: i
Enter part number: 788
Enter part name: USB 3.0
Enter quantity on hand: 67
Enter operation code: s
Enter part number: 832
Part not found.
Enter operation code: 833
Illegal code.
Enter operation code: s
Enter part number: 833
Part name: Disk Drive
Quantity on hand: 90
Enter operation code: u
Enter part number: 788
Enter change in quantity on hand(- means minus): 3
Enter operation code: p
Part Number      Part Name      Quantity on Hand
   833          Disk Drive             90
   788             USB 3.0             70
Enter operation code: q
```

注意：菜单可以没有

因为 readline 函数和这个程序的主干没有太大关系，我们用单独的头文件和源文件包含它。