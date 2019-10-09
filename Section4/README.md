## 1:合格的字符串

- [查看](http://dsa.openjudge.cn/string19/1/)

- 描述

  ​     老师给小学生门布置了一些作业，让它们按照一个模版写一些字符串交上来，同学们把作业交上来了，问题来了，这么多的作业老师批改不过来，现在请你帮老师写一个程序，帮助老师确定各个字符串是否合格。    首先老师有一个匹配模版，比如是“aa[123]bb”这一个字符串，同学们交的各种作业字符串如aa1bb、aa2bb、aa3bb都算是正确匹配看，而aacbb就是错误的字符串。（即待查字符串对应于模版方括号内的部分，应该为方括号内字符串的一个子字符）。    我们需要做的就是按照模版，找出正确的字符串和所在的行。

- 输入

  输入的第一行为一个整数n，表示有多少个学生的作业，即有多少行需要检查的字符串。（1<=n<=50) 中间为n行字符串，代表着n个学生们写的作业。每个字符串长度小于50。 最后一行为1行字符串，代表着老师给的匹配模板。

- 输出

  输出合格的字符串的行号和该字符串。（中间以空格隔开）

- 样例输入

  ```
  4
  Aab
  a2B
  ab
  ABB
  a[a2b]b
  ```

  

- 样例输出

  ```
  1 Aab
  2 a2B
  4 ABB
  ```

  

---

## 2:去除C程序中的注释

- [查看](http://dsa.openjudge.cn/string19/2/)

- 描述

  C程序的注释用/*...*/来表示。请写一个程序，将输入的C程序源代码中的注释去掉，输出去掉注释之后的源代码。用于测试的C代码保证符合语法，不使用C++的//注释语法。注意，C语言不允许出现嵌套注释。具体来说，对于/*/**/"*/"，如果不允许嵌套注释，那么它表示字符串"*/"；如果允许嵌套注释，它表示一个引号"。还请注意，字符串中出现的注释符/*属于字符串的一部分，注释中出现的双引号"属于注释的一部分。

- 输入

  符合语法的C代码文本文件。代码每行不超过200个字符。

- 输出

  去掉注释后的C代码。要求只能去掉注释，不可以做其他的修改，比如调整缩进,去除注释之外的换行符等。

- 样例输入

  ```c++
  #include 
  #include 
  #include 
  
  /*Hash Search: 
  Hash function: division method; 
  handling collisions: open addressing's linear probing. 
  In this exercise, M is the basic area's length, all keys are non negative integers.*/
  
  #define M 11
  
  int hash(int key)
  {
  	return key % M;
  }
  
  void init_hash(int* hashtable)
  {
  	int i;
  	for(i = 0; i < M; ++i)
  	{
  		hashtable[i] = -1;
  	}
  }
  
  /*return value: 
  1:found, *position is the key's index; 
  0:not found, *position is where to insert the key; 
  -1:overflow. */
  int search_hash(int* hashtable, int key, int* position)
  {
  	int i, h = hash(key);
  	for(i = 0; i < M; ++i)
  	{
  		if(key == hashtable[h])
  		{
  			*position = h;
  			return 1;
  		}
  		if(-1 == hashtable[h])
  		{
  			*position = h;
  			return 0;
  		}
  		h = (h+1) % M;
  	}
  	*position = -1;
  	return -1;
  }
  
  /*return value: 1:inserted, 0:overflow*/
  int insert_hash(int* hashtable, int key)
  {
  	int position, result;
  	result = search_hash(hashtable, key, &position);
  	if(-1 == result)
  		return 0;
  	hashtable[position] = key;
  	return 1;
  }
  
  void main()
  {
  	int hashtable[M];
  	init_hash(hashtable);
  	srand(time(NULL));
  	int i, j, key;
  	for(i = 0; i < 8; ++i) 	/*make a hash table with 8 elements*/
  	{
  		key = rand() % 50;
  		insert_hash(hashtable, key);
  		printf("Insert %d\n", key);
  		for(j = 0; j < M; ++j)
  			printf("%3d", hashtable[j]);
  		printf("\n");
  	}
  
  	printf("Please input the key to search:\n");
  	scanf("%d", &key);
  	i = search_hash(hashtable, key, &j);
  	if(1 == i)
  		printf("Found!Its index is %d\n", j);
  	else
  		printf("Not found!\n");
  }
  ```

  

- 样例输出

  ```c++
  #include 
  #include 
  #include 
  
  
  
  #define M 11
  
  int hash(int key)
  {
  	return key % M;
  }
  
  void init_hash(int* hashtable)
  {
  	int i;
  	for(i = 0; i < M; ++i)
  	{
  		hashtable[i] = -1;
  	}
  }
  
  
  int search_hash(int* hashtable, int key, int* position)
  {
  	int i, h = hash(key);
  	for(i = 0; i < M; ++i)
  	{
  		if(key == hashtable[h])
  		{
  			*position = h;
  			return 1;
  		}
  		if(-1 == hashtable[h])
  		{
  			*position = h;
  			return 0;
  		}
  		h = (h+1) % M;
  	}
  	*position = -1;
  	return -1;
  }
  
  
  int insert_hash(int* hashtable, int key)
  {
  	int position, result;
  	result = search_hash(hashtable, key, &position);
  	if(-1 == result)
  		return 0;
  	hashtable[position] = key;
  	return 1;
  }
  
  void main()
  {
  	int hashtable[M];
  	init_hash(hashtable);
  	srand(time(NULL));
  	int i, j, key;
  	for(i = 0; i < 8; ++i) 	
  	{
  		key = rand() % 50;
  		insert_hash(hashtable, key);
  		printf("Insert %d\n", key);
  		for(j = 0; j < M; ++j)
  			printf("%3d", hashtable[j]);
  		printf("\n");
  	}
  
  	printf("Please input the key to search:\n");
  	scanf("%d", &key);
  	i = search_hash(hashtable, key, &j);
  	if(1 == i)
  		printf("Found!Its index is %d\n", j);
  	else
  		printf("Not found!\n");
  }
  ```

  

- 提示

  注意字符串，字符，转义字符的情况。 看看自己有没有考虑 "a\"/*ccc*/" 这种情况。

  

## 3:前缀中的周期

- [查看](http://dsa.openjudge.cn/string19/3/)

- 描述

  一个字符串的前缀是从第一个字符开始的连续若干个字符，例如"abaab"共有5个前缀，分别是a, ab, aba, abaa,  abaab。 我们希望知道一个N位字符串S的前缀是否具有循环节。换言之，对于每一个从头开始的长度为 i （i 大于1）的前缀，是否由重复出现的子串A组成，即 AAA...A （A重复出现K次,K 大于 1）。如果存在，请找出最短的循环节对应的K值（也就是这个前缀串的所有可能重复节中，最大的K值）。

- 输入

  输入包括多组测试数据。每组测试数据包括两行。 第一行包括字符串S的长度N（2 <= N <= 1 000 000）。 第二行包括字符串S。 输入数据以只包括一个0的行作为结尾。

- 输出

  对于每组测试数据，第一行输出 "Test case #“ 和测试数据的编号。 接下来的每一行，输出前缀长度i和重复测数K，中间用一个空格隔开。前缀长度需要升序排列。 在每组测试数据的最后输出一个空行。

- 样例输入

  ```
  3
  aaa
  12
  aabaabaabaab
  0
  ```

  

- 样例输出

  ```
  Test case #1
  2 2
  3 3
  
  Test case #2
  2 2
  6 2
  9 3
  12 4
  ```

### Hint

直觉