## 结构体作为函数参数
**明天的日期**
*写一个程序:输入今天的日期,求明天的日期*

看着这个问题简单,实际上稍微有点技巧.

给出下面四个特殊日期,大家可以思考一下:

>2020 - 1 -31
>
>2020 - 11 - 31
>
>2020 - 12 - 31
>
>2000 - 2 - 28

## Use sturcture itself as a function's parameter
it's not an efficient way

>K & R said （p.131 ）
>"if a large structure is to be passed to a function,
>in is generally more efficent to pass a pointer than to copy the whole structure"
