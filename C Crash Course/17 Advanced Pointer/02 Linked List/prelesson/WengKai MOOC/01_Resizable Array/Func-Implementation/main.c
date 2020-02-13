#define _CRT_SECURE_NO_WARNINGS 1

#include"Array.h"
#include<stdio.h>
#include<stdlib.h>
//typedef struct {
//	int* array;
//	int size;
//}Array;

Array array_creat(int init_size) {

	Array a;

	a.array = (int*)malloc(sizeof(int) * init_size);
	a.size = init_size;

	return a;
}
//为何不传入指针？
//比如：Array array_creat(Array* a, int init_size)
//问题如下：
//1.如果a == NULL？
//2.如果a指向的是已经malloc过的空间，那样还要再free一次

void array_free(Array* a) {

	free(a->array);
	a->array = NULL;//防止此函数被调用两次。free(NULL)是可以的
	a->size = 0;
}

int array_size(const Array* a) {

	return a->size;
}

int* array_at(Array* a, int index) {

	if (index >= a->size)
		array_inflate(&a, (index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size);
	//为什么不直接加上一个 BLOCK_SIZE？而是用 index / BLOCK_SIZE + 1) * BLOCK_SIZE - a->size) 这么复杂的公式？
	//这样加强了程序的可变性，如果某一次数组增加的大小你不清楚，比如从 100 增加到 150
	//直接加 BLOCL_SIZE 可能并不够用，用着个公式增加的大小一定 大于等于 需要增加的大小。
	//为什么引入 BLOCKJ_SIZE ？
	//一方面 增加了程序的扩展性（可以方便更改）和可读性，另一方面 
	//如果你设置的 BLICK_SIZE 过大，数组大小这时就增加 1，这样太浪费内存
	//如果设置的过小就不能数组满足大幅的更改
	//拿本题 BLOCK_SIZE = 20 为例，一次最多多增加 19 个 int 的大小，这也就意味着
	//这种方法浪费的内存最多只有 19*sizeof(int) 个字节

	return &(a->array[index]);
}

////输出数组元素
//int array_get(const Array a, int index) {
//
//	return a.array[index];
//}
////修改数组元素
//int array_set(Array* a, int index, int value) {
//	
//	return (a->array[index] = value);
//}

void array_inflate(Array* a, int more_size) {

	int* p = (int*)malloc(sizeof(int) * (a->size + more_size));
	int i = 0;

	//可换成memcpy
	for (i = 0; i < a->size; i++) {
		p[i] = a->array[i];
	}
	free(a->array);

	a->array = p;
	a->size += more_size;
}


int main(void) {

	Array a;
	int size = 0;

	printf("初始化数组大小,请输入：\n");
	scanf("%d", &size);

	a = array_creat(size);

	printf("%d members in array\n", array_size(&a));
	//为什么不直接用 a.size 输出数组的大小？
	//这样用函数来返回数组大小的方式就叫做 封装
	//日后如果有版本更新，算法优化等等，可以用函数来实现，将实现的代码保护起来

	//array_at(&a, 1) 返回 &(a.array[1]) 解引用即使这个变量 array[1]
	//当然这个函数可以拆开，实现在array_at 后
	*array_at(&a, 1) = 10;
	printf("a.array[1] = %d\n", *array_at(&a, 1));


	return 0;
}




