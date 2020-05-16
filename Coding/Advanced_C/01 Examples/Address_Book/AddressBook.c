#include<stdio.h>
#include<string.h>

#define Max_SIZE 50 //定义通讯录的大小

typedef struct PersonInfo {
	char name[100];
	char phone[100];
}PersonInfo;

typedef struct AddressBook {
	PersonInfo all_address[Max_SIZE];
	int size;
}AddressBook;
//size 的含义是：
//数组 all_address 下标范围在 [0,size) 内的元素是有意义的
//                            [size, 200) 是我们没有用到的

//初始化
void init(AddressBook* address_book) {
	
	address_book->size = 0;
	//尽量少用 magic number(不明含义的数字)
	for (int i = 0; i < Max_SIZE; i++) {
		strcpy(address_book->all_address->name, " ");
		strcpy(address_book->all_address->phone, " ");
	}

}

int Menu(void) {
	
	printf("======================\n");
	printf("***     0.退出     ***\n");
	printf("***  1.新增联系人  ***\n");
	printf("***  2.删除联系人  ***\n");
	printf("***  3.查找联系人  ***\n");
	printf("***  4.修改联系人  ***\n");
	printf("***  5.打印联系人  ***\n");
	printf("***  6.清除联系人  ***\n");
	printf("***  7.排序联系人  ***\n");
	printf("======================\n");

	printf("请输入你的选择：");
	int choice;
	scanf("%d", &choice);

	return choice;
}

void AddPersonInfo(AddressBook* address_book) {
	
	printf("新增联系人\n");

	if (address_book->size >= Max_SIZE) {
		printf("通讯录已满，请先清除！\n");
		return;
		//虽然函数类型是 void 但是也是可以用 return 滴
	}
	PersonInfo* info = &address_book->all_address[address_book->size];
	
	printf("请输入联系人姓名：");
	scanf("%s", info->name);
	printf("请输入联系人电话：");
	scanf("%s", info->phone);

	address_book->size++;
}

void DelPersonInfo(AddressBook* address_book) {
	
	//删除的方法很多，可以根据姓名，电话，序号等等来删除，
	//这里我们就用我个人比较常用的 搜索名字的删除方法

	char search_name[100] = { 0 };

	printf("删除联系人\n");
	printf("请输入联系人姓名：");
	scanf("%s", search_name);

	int name_exist = FindName(address_book, search_name);
	
	//这里注意 FindName 返回值设定，要被删除的元素下标可能是 0，这种情况下会返回 0 
	if (name_exist == -1) {
		printf("该联系人不存在！\n");
		return;
	}

	//删除了相同姓名的第一个后，继续寻找改名字，如果找到了，重复上面的操作，如果没找到，退出循环
	//相同的姓名的情况比较复杂，在修改，查找，排序等等场景都会带来麻烦，
	//而且平时你的通讯录中难道会将两个相同姓名的人的备注写成一样的吗？
	//所以，我仅仅在删除功能中实现一种针对相同姓名的情况的设计思路，后面的其他功能默认没有重复姓名的情况。
	while (name_exist != -1) {
		
		//将 all_address 数组的最后一个元素赋值给要删除的元素，完成删除
		//结构体类型是可以直接赋值的
		address_book->all_address[name_exist] = address_book->all_address[address_book->size - 1];
		address_book->size--;
		name_exist = FindName(address_book, search_name);
	}

	printf("删除成功！\n");
	
}

int FindName(AddressBook* address_book, char search_name[100]) {
	
	for (int i = 0; i < address_book->size; i++) {
		//找到返回数组下标
		if (strcmp(address_book->all_address->name, search_name) == 0) {
			return i;
		}
	}
	//没有找到，返回 -1
	return -1;
}

void FindPersonInfo(AddressBook* address_book) {

	char search_name[100] = { 0 };

	//搜索人的方式也很多，我们这里用搜索名字的方法
	printf("更新联系人\n");
	printf("请输入人名：");
	scanf("%s", search_name);

	for (int i = 0; i < address_book->size; i++) {
		PersonInfo* info = &address_book->all_address[i];// 创建一个 PersonInfo 类型的变量简化程序，不然下面的姓名访问就太长了
		if (strcmp(info->name, search_name) == 0) {
			printf("[%d] %s  %s\n", i, info->name, info->phone);
		}
	}
	

}

void ModifyPersonInfo(AddressBook* address_book) {
	
	char search_name[100] = { 0 };
	int isjump = 1;

	printf("删除联系人\n");
	printf("请输入联系人姓名：");
	scanf("%s", search_name);

	int name_exist = FindName(address_book, search_name);

	if (name_exist == -1) {
		printf("该联系人不存在！\n");
		return;
	}
	
	//优化以下用户的体验
	printf("请输入新的姓名，输入 0 跳过：");
	scanf("%d", &isjump);
	if (isjump) {
		scanf("%s", address_book->all_address[name_exist].name);
	}
	printf("请输入新的电话，输入 0 跳过：");
	scanf("%d", &isjump);
	if (isjump) {
		scanf("%s", address_book->all_address[name_exist].phone);
	}

	printf("更新成功！\n");

}

void PrintPersonInfo(AddressBook* address_book) {
	
	PersonInfo* info;

	if (address_book->size == 0) {
		printf("当前没有联系人！\n");
		return;
	}

	printf("所有联系人信息如下：\n");
	
	for (int i = 0; i < address_book->size; i++) {
		info = &address_book->all_address[i];
		printf("[%2d]%4s  %s\n", i, info->name, info->phone);
	}
}

void ClearPersonInfo(AddressBook* address_book) {
	
	//清除所有信息是一种 危险的行为，我们最好让用户确认一次
	//相比你应该在自己的手机上回复过出厂设置，系统应该会让你确认不止一次！
	int is_continue = 0;

	printf("清除所有联系人，你确定吗？输入 0 继续: ");
	scanf("%d", &is_continue);
	if(is_continue == 0) {
		//将 size 置为 0 即可，不过你也可以将数组的每个元素都进行重置
		address_book->size = 0;
	}
	printf("清除完成！\n");
}

void SortPersonInfo(AddressBook* address_book) {

	printf("排序通讯录\n");

	for (int i = 0; i < address_book->size - 1; i++) {
		for (int j = 0; j < address_book->size - 1 - i; j++) {
			PersonInfo* info = &address_book->all_address[j];
			PersonInfo* info_next = &address_book->all_address[j + 1];
			//简单的用 strcmp 进行排序，不过排序的行为感觉是“未定义”的，
			//看着有规律，但再多试试会发现很多情况并没有规律。
			//也还有很多可以排血的函数。比如：strcoll,wcsscoll,wcscmp 这些只要你能弄懂，我想你也可以用。
			//或者有其他更好的实现办法，但这并不是我们在这里的重点。
			if (strcmp(info->name, info_next) > 0) {
				PersonInfo tmp;
				tmp = *info;
				*info = *info_next;
				*info_next = tmp;
			}
		}
	}
	printf("排序成功！\n");
}

int main(int argc, char* argv[]) {
	
	AddressBook address_book;
	
	//声明一个函数指针类型
	typedef void (*Func)(AddressBook*);
	Func func_table[] = {
		NULL,
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
	
	init(&address_book);

	
	while (1) {
		int choice = Menu();
		
		if (choice < 0 || choice > 7) {
			printf("输入错误！\n");
			continue;
		}

		if (choice == 0) {
			printf("再见！\n");
			break;
		}
		
		func_table[choice](&address_book);

	}

	return 0;
}
