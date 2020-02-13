#ifndef _ARRAY_H_
#define _ARRAY_H_

#define BLOCK_SIZE 20

typedef struct {
	int* array;
	int size;
}Array;

Array array_creat(int init_size);//初始化数组
void array_free(Array* a);//释放堆上空间
int array_size(const Array* a);//查看数组的大小
int* array_at(Array* a, int index);
void array_inflate(Array* a, int more_size);

#endif