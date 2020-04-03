#### 程序：账薄结算

这个程序帮你理解一种简单的交互式程序设计，我们可以通过这种方式设计菜单。

题目：

开发一个程序用来维护账簿的余额。程序将为用户提供选择菜单：清空余额账户，向账户存钱，从账户取钱，显示当前余额，退出程序。选项用 0，1，2，3，4表示。程序的会话类似这样：

```c
**** ACME checkbook-balancing program ****
Comands: 0 = clear, 1 = credit, 2 = debit, 3 = balance, 4 = exit

Enter command: 1
Enter amount of credit: 1042.56
Enter command: 2
Enter amount of debit : 133.56
Enter command: 3
Current balance: 909
Ener command: 4
Goodbye~
```

