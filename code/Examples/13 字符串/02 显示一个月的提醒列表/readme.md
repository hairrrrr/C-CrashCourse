#### 程序：显示一个月的提醒列表

此程序会显示每一个月的每日提醒列表。用户需要输入一系列提醒，每条提醒都要有一个前缀来说明是那一个月中的那一天。当用户输入的是 0 而不是有效日期时，程序会显示出录入的全部提醒列表（按日期排序）。下面是会话示例：

```c
Enter day and reminder: 24 Suan's birstday
Enter day and reminder: 5 6:00 - Dinner with Marge
Enter day and reminder: 7 10:30 - Movie - "Chinatown"
Enter day and reminder: 0
Day Reminder:
 5 6:00 - Dinner with Marge
 7 10:30 - Movie - "Chinatown"
24 Suan's birstday
```

- 读入提醒使用我们写的 read_line 函数
- 将提醒存放在二维数组中，数组的每一行看作一个字符串。日期和提示消息都要放进去 。
- 日期我们用整型输入，然后转换为字符串放入二维数组的前面。
- 每次读入新的日期和提示消息后，将转为字符串的当前日期和二维数组每行前面表示日期的部分比较。如果当前日期字符串小于二维数组当前行的字符串，说明当前日期较小，应当插入到当前数组的行前一行。我们可以将二维数组从当前行到存放提示的最后一行每行依次向后移动一行，从而使得当前日期和提示可以插入二维数组的当前行。
- 打印二维数组