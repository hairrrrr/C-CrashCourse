//#### 6. 猜凶手日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
//
//以下为4个嫌疑犯的供词:
//
//
//
//A说：不是我。
//
//B说：是C。
//
//C说：是D。
//
//D说：C在胡说
//
//已知3个人说了真话，1个人说的是假话。
//
//
//
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

#include<stdio.h>

int main(void) {

	int i, murder;
	
	//这种类型的问题思路是穷举——即遍历所有可能

	for (murder = 'A'; murder <= 'D'; murder++) {
		// 3 人说了真话， 1 人说了假话，说明这四个语句 3 真 1 假 ，相加为 3
		if (((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D')) == 3 )
			
			printf("murder is %c\n", murder);
	}

	return 0;
}
