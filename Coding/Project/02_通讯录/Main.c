#define _CRT_SECURE_NO_WARNINGS

#include"AddressBook.h"

int main(int argc, char* argv[]) {

	AddressBook address_book;

	//声明一个函数指针类型
	typedef void (*Func)(AddressBook*);
	Func func_table[] = {
		DestoryBook,
		AddPersonInfo,
		DelPersonInfo,
		FindPersonInfo,
		ModifyPersonInfo,
		PrintPersonInfo,
		ClearPersonInfo,
		SortPersonInfo,
	};
	//或者你也可以这么做：
	//声明一个函数类型：
	//typedef void (Func)(AddressBook*);
	//我们用的是指针数组，数组类型必须是指针类型，所以应该加上 * 
	//Func* func_table[] = {
	//NULL,
	//AddPersonInfo,
	//DelPersonInfo,
	//FindPersonInfo,
	//ModifyPersonInfo,
	//PrintPersonInfo,
	//ClearPersonInfo,
	//SortPersonInfo,
	//}; 

	InitBook(&address_book);
	

	while (1) {
		system("cls");
		int choice = Menu();

		if (choice < 0 || choice > 7) {
			printf("输入错误！\n");
			continue;
		}

		func_table[choice](&address_book);

		if (choice == 0) {
			printf("\n 再见！\n");
			break;
		}
	}

	return 0;
}
