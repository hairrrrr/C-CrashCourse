#### 程序：手牌分类

编写程序对手牌进行读取和分类。手中的每张牌都有花色（方块，梅花，红桃和黑桃）和等级（2，3，4，5，6，7，8，9，T，J，Q，K 和 A）。不允许使用王牌，并且假设 A 是最高等级的。一手 5 张牌，然后把手中的牌分为下列某一类（列出的顺序从好到坏）。

- 同花顺（顺序连续且同花色）
- 四张（4 张牌等级相同）
- 葫芦（3 张牌等级一样，另外2 张等级一样）
- 同花（5 张牌同花色）
- 顺子（5 张牌等级顺序连续）
- 三张（3 张牌等级连续）
- 两对
- 一对（2 张牌等级一样）
- 其他牌

如果一手牌可以分为两种或多种类别，程序将选择最好的一种。

为了便于输入，将牌的等级和花色简化如下：

- 等级： 2，3，4，5，6，7，8，9，T，J，Q，K ，A
- 花色：c d h  s

如果用户输入非法牌或者输入同一张牌两次，程序将此牌忽略掉，产生错误信息，然后要求输入另一张牌。如果输入为 0 而不是一张牌，就会导致程序终止。

与程序的会话如下：

```c
Enter a card : 2s
Enter a card : 5s
Enter a card : 4s
Enter a card : 3s
Enter a card : 6s
Straight flush

Enter a card : 8c
Enter a card : as
Enter a card : 8c
Duplicated card; ignored.
Enter a card : 7c
Enter a card : ad
Enter a card : 3h
Pair

Enter a card : 6s
Enter a card : d2
Bad card; ignored.
Enter a card : 2d
Enter a card : 9c
Enter a card : 4h
Enter a card : ts
High card

Enter a card: 0
```



