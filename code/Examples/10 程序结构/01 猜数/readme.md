#### 程序：猜数

程序产生一个 1 ~ 100 的随机数，用户尝试用尽可能少的次数猜出这个数。程序运行如下：

```c
Guess the secret number between 1 and 100.
    
A new number has been chosen.
Enter guess:55
Too low; try again.
Enter guess:65
Too high; try again.
Enter guess: 60
You won in 3 guesses!
 
Play again?(Y/N) n
```

使用两种方法：使用全局变量/不使用全局变量