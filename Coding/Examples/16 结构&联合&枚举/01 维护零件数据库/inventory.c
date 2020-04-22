#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include"readline.h"

#define NAME_LEN 20
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
}inventory[MAX_PARTS];

int num_parts = 0; //number of parts current stored

void menu();
int find_part(int number);
void insert();
void search();
void update();
void print();


int main(void) {
	
	char code = 'a';

	menu();

	for (;;) {
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n') // ships to end of line
			;
		switch (code) {
			case 'i': insert(); break;
			case 's': search(); break;
			case 'u': update(); break;
			case 'p': print(); break;
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
int find_part(int number) {

	int i;

	for (i = 0; i < num_parts; i++) {
		if (inventory[i].number == number)
			return i;
	}

	return -1;
}


/**********************************************************
*
*	insert: Inserts the part into the database.Prints
*		    an error message and returns prematurely
*			if the part already exists or the database
*			is full.
*
***********************************************************/
void insert() {
	
	int part_number;

	if (num_parts == MAX_PARTS) {
		printf("Database is full; can't add more parts.\n");
		return;
	}

	printf("Enter part number: ");
	scanf("%d", &part_number);

	if (find_part(part_number) >= 0) {
		printf("Part already exists.\n");
		return;
	}

	inventory[num_parts].number = part_number;
	printf("Enter part name: ");
	read_line(inventory[num_parts].name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &inventory[num_parts].on_hand);
	num_parts++;
}


/************************************************************
*
*	search: Look up a part by the number user enters.
*			If the part exists, prints the name and quantity
*			on hand;if not, print an error message.
*
************************************************************/
void search() {
	
	int index, number;

	printf("Enter part number: ");
	scanf("%d", &number);

	index = find_part(number);

	if (index == -1) {
		printf("Part not found.\n");
		return;
	}
	
	printf("Part name: %s\n", inventory[index].name);
	printf("Quantity on hand: %d\n", inventory[index].on_hand);
	
}


/************************************************************
*
*	update: Prompts user to enter a number.
*			Print an error message if the part doesn't exist;
*			otherwise,prompts the user to enter change in
*			quantity on hand and updates the database.
*
************************************************************/

void update() {
	
	int number, index, change;

	printf("Enter part number: ");
	scanf("%d", &number);

	index = find_part(number);

	if (index == -1) {
		printf("Part not found.\n");
		return;
	}

	printf("Enter change in quantity on hand(- means minus): ");
	scanf("%d", &change);
	inventory[index].on_hand += change;

}


/************************************************************
*
*	print: Print a listing of all parts in the database,
*		   showing the part number,part name and quantity
*		   on hand.Parts are printed in the order in which
*		   they were entered into the database.
*
************************************************************/

void print() {
	
	int i;

	printf("Part Number      Part Name      Quantity on Hand\n");
	for (i = 0; i < num_parts; i++) {
		printf("%6d%20s%15d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand);
	}
}
