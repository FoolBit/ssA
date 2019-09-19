## 1:多项式加法

- [查看](http://dsa.openjudge.cn/linearlists19/1/)

- 描述

  ​    我们经常遇到两多项式相加的情况，在这里，我们就需要用程序来模拟实现把两个多项式相加到一起。首先，我们会有两个多项式，每个多项式是独立的一行，每个多项式由系数、幂数这样的多个整数对来表示。如多项式2x20- x17+ 5x9- 7x7+ 16x5+ 10x4 + 22x2- 15对应的表达式为：2 20 -1 17 5 9 - 7 7 16 5 10 4 22 2 -15 0。  **为了标记每行多项式的结束，在表达式后面加上了一个幂数为负数的整数对。**同时输入表达式的幂数大小顺序是随机的。我们需要做的就是把所给的两个多项式加起来。

- 输入

  输入包括多行。 第一行整数n,表示有多少组的多项式需要求和。(1 < n < 100) 下面为2n行整数，每一行都是一个多项式的表达式。表示n组需要相加的多项式。 每行长度小于300。

- 输出

  输出包括n行，每行为1组多项式相加的结果。 在每一行的输出结果中，多项式的每一项用“[x y]”形式的字符串表示，x是该项的系数、y 是该项的幂数。要求按照每一项的幂从高到低排列，即先输出幂数高的项、再输出幂数低的项。 系数为零的项不要输出。

- 样例输入

  `2 -1 17 2 20 5 9 -7 7 10 4 22 2 -15 0 16 5 0 -1 2 19 7 7 3 17 4 4 15 10 -10 5 13 2 -7 0 8 -8 -1 17 2 23 22 2 6 8 -4 7 -18 0 1 5 21 4 0 -1 12 7 -7 5 3 17 23 4 15 10 -10 5 13 5 2 19 9 -7`

- 样例输出

  `[ 2 20 ] [ 2 19 ] [ 2 17 ] [ 15 10 ] [ 5 9 ] [ 6 5 ] [ 14 4 ] [ 35 2 ] [ -22 0 ] [ 2 23 ] [ 2 19 ] [ 2 17 ] [ 15 10 ] [ 6 8 ] [ 8 7 ] [ -3 5 ] [ 44 4 ] [ 22 2 ] [ -18 0 ]`



## 2:放苹果

- [查看](http://dsa.openjudge.cn/linearlists19/2/)

- 描述

  把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问共有多少种不同的分法？（用K表示）5，1，1和1，5，1 是同一种分法。

- 输入

  第一行是测试数据的数目t（0 <= t <= 20）。以下每行均包含二个整数M和N，以空格分开。1<=M，N<=10。

- 输出

  对输入的每组数据M和N，用一行输出相应的K。

- 样例输入

  `1 7 3 `

- 样例输出

  `8`



## 3:位查询

- [查看](http://dsa.openjudge.cn/linearlists19/3/)
- [提交](http://dsa.openjudge.cn/linearlists19/3/submit/)
- [统计](http://dsa.openjudge.cn/linearlists19/3/statistics/)
- [提问](http://dsa.openjudge.cn/linearlists19/clarify/3/)

- 总时间限制: 

  5000ms

- 内存限制: 

  65536kB

- 描述

  ​    给出N个范围在[0, 65535]的整数，编程支持以下的操作： （1）修改操作：C d，所有的数都增加d。如果超过65535，把结果模65536。 0 <= d <= 65535  （2）查询操作：Q i，统计在N个正整数中有多少个整数其对应的二进制形式的第i位二进制位为非0。0 <= i <= 15。并且最低位i为0。 　　最后，输出所有查询操作的统计值。

- 输入

  输入的第一行为两个正整数N,M,其中N为操作的整数的个数，而M为具体有多少个操作。 输入的第二行为N个正整数，为进行操作的N个正整数。 下面有M行，分别表示M个操作。  N<=100000,M<=200000

- 输出

  输出所有查询操作Q的统计值，每一个查询操作统计结果输出为一行。

- 样例输入

  `3 5 1 2 4 Q 1 Q 2 C 1 Q 1 Q 2`

- 样例输出

  `1 1 2 1 `



### 思路

转换成区间覆盖+前缀和





## 4:大整数乘法

- [查看](http://dsa.openjudge.cn/linearlists19/4/)

- 描述

  求两个不超过200位的非负整数的积。

- 输入

  有两行，每行是一个不超过200位的非负整数，没有多余的前导0。

- 输出

  一行，即相乘后的结果。结果里不能有多余的前导0，即如果结果是342，那么就不能输出为0342。

- 样例输入

  `12345678900 98765432100`

- 样例输出

  `1219326311126352690000`
