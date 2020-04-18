#include<stdio.h>
#include<stdlib.h>
#include"readline.h"

#define NAME_LEN 20

typedef struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
	struct part* next;
}part;


void menu();
part* find_part(part* head, int number);
void insert(part* head);
void search(part* head);
void update(part* head);
void print(part* head);


int main(void) {

	char code = 'a';
	part* head = (part*)malloc(sizeof(part));
	head->next = NULL;

	if (head == NULL) {
		printf("Database establish failed\n");
		exit(EXIT_SUCCESS);
	}

	menu();

	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n') // skips to end of line
			;
		switch (code) {
		case 'i': insert(head); break;
		case 's': search(head); break;
		case 'u': update(head); break;
		case 'p': print(head); break;
		case 'q': return 0;
		default: printf("Illegal code.\n"); break;
		}
	}




	return 0;
}

void menu() {

	printf("                        ==================================\n");
	printf("                        *                                *\n");
	printf("                        *            i:  insert          *\n");
	printf("                        *            s:  search          *\n");
	printf("                        *            u:  undate          *\n");
	printf("                        *            p:  print           *\n");
	printf("                        *            q:  quit            *\n");
	printf("                        *                                *\n");
	printf("                        ==================================\n");
}


/**********************************************************
*
*	find_part: Looks up a part number in the inventory
*			   array.Returns the array index if the part
*			   number is found;otherwise,return -1
*
***********************************************************/
part* find_part(part* head, int number) {

	part* cur;

	// 链表是按照编号升序排序的
	for (cur = head->next; cur != NULL && cur->number > number;
		cur = cur->next)
		;
	
	if (cur == NULL)
		return NULL;

	if (cur->number == number)
		return cur;

}


/**********************************************************
*
*	insert: Inserts the part into the database.Prints
*		    an error message and returns prematurely
*			if the part already exists or the database
*			is full.
*
***********************************************************/
void insert(part* head) {

	int part_number;
	part* cur, * prev, *new_part;
	

	printf("Enter part number: ");
	scanf("%d", &part_number);
	
	// 寻找 part_number 所应插入的位置，我们需要 cur 遍历链表，但是应该保留 cur 前面的结点 prev 
	// 退出循环条件：cur == NULL 说明是头插或尾插
	//				 cur->number > part_number 说明 输入的编号重复
	//												应该在 cur 和 prev 之间插入新的零件 或 头插
	for (cur = head->next, prev = NULL;cur != NULL && cur->number < part_number ;
		prev = cur, cur = cur->next)
		;
	
	// 判断输入的编号是否于数据库中的现有重复
	if (cur != NULL && cur->number == part_number) {
		printf("Part already exists.\n");
		return;
	}

	// 申请新结点
	new_part = (part*)malloc(sizeof(part));

	// 判断申请是否成功
	if (new_part == NULL) {
		printf("Database is full; can't add more parts.\n");
		return;
	}

	
	new_part->number = part_number;
	printf("Enter part name: ");
	read_line(new_part->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_part->on_hand);
	
	// 插入的方式：
	// 链表为空时：对 head 进行操作（prev == NULL, cur == NULL）
	// 链表不为空：
	//			  头插：对 head 操作 (prev == NULL, cur != NULL)
	//			  尾插：对 prev 操作 (prev != NULL, cur == NULL)
	//			  普通位置插入：对 prev 操作(prev,cur 都不为 NULL)
	new_part->next = cur;

	if (prev == NULL)
		head->next = new_part;
	else
		prev->next = new_part;

}


/************************************************************
*
*	search: Look up a part by the number user enters.
*			If the part exists, prints the name and quantity
*			on hand;if not, print an error message.
*
************************************************************/
void search(part* head) {

	int number;
	part* trg;

	printf("Enter part number: ");
	scanf("%d", &number);

	trg = find_part(head, number);

	if (trg == NULL) {
		printf("Part not found.\n");
		return;
	}

	printf("Part name: %s\n", trg->name);
	printf("Quantity on hand: %d\n", trg->on_hand);

}


/************************************************************
*
*	update: Prompts user to enter a number.
*			Print an error message if the part doesn't exist;
*			otherwise,prompts the user to enter change in
*			quantity on hand and updates the database.
*
************************************************************/

void update(part* head) {

	int number, change;
	part* trg;

	printf("Enter part number: ");
	scanf("%d", &number);

	trg = find_part(head, number);

	if (trg == NULL) {
		printf("Part not found.\n");
		return;
	}

	printf("Enter change in quantity on hand(- means minus): ");
	scanf("%d", &change);
	trg->on_hand += change;

}


/************************************************************
*
*	print: Print a listing of all parts in the database,
*		   showing the part number,part name and quantity
*		   on hand.Parts are printed in the order in which
*		   they were entered into the database.
*
************************************************************/

void print(part* head) {


	printf("Part Number      Part Name      Quantity on Hand\n");
	for (part* cur = head->next; cur != NULL; cur = cur->next) {
		printf("%6d%20s%15d\n", cur->number, cur->name, cur->on_hand);
	}
}
