#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct PersonInfo {
	char name[100];
	char phone[100];
}PersonInfo;

typedef struct AddressBook {
	PersonInfo* all_address;
	int size;
	int capacity;
}AddressBook;
// size 的含义是：
// 数组 all_address 下标范围在 [0,size) 内的元素是有意义的
//                            [size, 200) 是我们没有用到的
// capacity 可用的空间大小 


int Menu(void);

void InitBook(AddressBook* address_book);

void AddPersonInfo(AddressBook* address_book);

void DelPersonInfo(AddressBook* address_book);

void FindPersonInfo(AddressBook* address_book);

void ModifyPersonInfo(AddressBook* address_book);

void PrintPersonInfo(AddressBook* address_book);

void ClearPersonInfo(AddressBook* address_book);

void SortPersonInfo(AddressBook* address_book);

void DestoryBook(AddressBook* address_book);
