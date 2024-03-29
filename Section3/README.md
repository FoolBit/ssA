## 1:中缀表达式的值

- [查看](http://dsa.openjudge.cn/stack19/1/)

- 描述

  人们熟悉的四则运算表达式称为中缀表达式，例如(23+34*45/(5+6+7))。在程序设计语言中，可以利用堆栈的方法把中缀表达式转换成保值的后缀表达式（又称逆波兰表示法），并最终变为计算机可以直接执行的指令，得到表达式的值。  给定一个中缀表达式，编写程序，利用堆栈的方法，计算表达式的值。

- 输入

  第一行为测试数据的组数N 接下来的N行，每行是一个中缀表达式。表达式中只含数字、四则运算符和圆括号，操作数都是正整数，数和运算符、括号之间没有空格。中缀表达式的字符串长度不超过600。

- 输出

  对每一组测试数据输出一行，为表达式的值

- 样例输入

  `3 3+5*8 (3+5)*8 (23+34*45/(5+6+7)) `

- 样例输出

  `43 64 108 `

- 提示

  注意：运算过程均为整数运算（除法运算'/'即按照C++定义的int除以int的结果，测试数据不会出现除数为0的情况），输出结果也为整数（可能为负）。 中间计算结果可能为负。



---



## 2:滑动窗口

- [查看](http://dsa.openjudge.cn/stack19/2/)

- 描述

  给定一个长度为n（n<=10^6）的数组。有一个大小为k的滑动窗口从数组的最左端移动到最右端。你可以看到窗口中的k个数字。窗口每次向右滑动一个数字的距离。下面是一个例子：数组是 [1 3 -1 -3 5 3 6 7]， k = 3。 窗口位置最小值最大值[1  3  -1] -3  5  3  6  7 -13 1 [3  -1  -3] 5  3  6  7 -33 1  3 [-1  -3  5] 3  6  7 -35 1  3  -1 [-3  5  3] 6  7 -35 1  3  -1  -3 [5  3  6] 7 36 1  3  -1  -3  5 [3  6  7]37  你的任务是得到滑动窗口在每个位置时的最大值和最小值。 

- 输入

  输入包括两行。 第一行包括n和k，分别表示数组的长度和窗口的大小。 第二行包括n个数字。

- 输出

  输出包括两行。 第一行包括窗口从左至右移动的每个位置的最小值。 第二行包括窗口从左至右移动的每个位置的最大值。

- 样例输入

  `8 3 1 3 -1 -3 5 3 6 7`

- 样例输出

  `-1 -3 -3 -3 3 3 3 3 5 5 6 7`

### Hint

单调队列

---

## 3:栈的基本操作

- [查看](http://dsa.openjudge.cn/stack19/3/)

- 描述

  栈是一种重要的数据结构，它具有push k和pop操作。push k是将数字k加入到栈中，pop则是从栈中取一个数出来。 栈是后进先出的：把栈也看成横向的一个通道，则push k是将k放到栈的最右边，而pop也是从栈的最右边取出一个数。 假设栈当前从左至右含有1和2两个数，则执行push 5和pop操作示例图如下：           push 5          pop 栈   1 2  ------->  1 2 5 ------>  1 2现在，假设栈是空的。给定一系列push k和pop操作之后，输出栈中存储的数字。若栈已经空了，仍然接收到pop操作，则输出error。

- 输入

  第一行为m，表示有m组测试输入，m<100。 每组第一行为n，表示下列有n行push k或pop操作。（n<150） 接下来n行，每行是push k或者pop，其中k是一个整数。 （输入保证同时在栈中的数不会超过100个）

- 输出

  对每组测试数据输出一行。该行内容在正常情况下，是栈中从左到右存储的数字，数字直接以一个空格分隔，如果栈空，则不作输出；但若操作过程中出现栈已空仍然收到pop，则输出error。

- 样例输入

  `2 4 push 1 push 3 pop push 5 1 pop`

- 样例输出

  `1 5 error`