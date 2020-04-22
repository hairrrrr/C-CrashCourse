#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_NUMBER 100

int secret_number;// 要猜的数

void generate_secret_number();// 随机数生成
void read_guesses(); // 猜的实现

int main(void) {

	char command;

	printf("Guess the secret number between 1 and 100.\n");
	
	do {
		generate_secret_number();
		printf("A new number has been chosen.\n");
		read_guesses();
		printf("Play again?(Y/N)");
		scanf(" %c", &command);// 注意 %c 前的空格，这很重要
		printf("\n");
	} while (command == 'y' || command == 'Y');

	return 0;
}

// 可以用这样的注释将函数的功能写在函数的定义的上方
// 我个人比较喜欢将简单的注释写在函数原型处

/****************************************************************************
*
* generate_secret_number: Initilizes the random number generator using the  
*						 time of day.Randomly selects a number between     
*						 1 and MAX_NUMBER and stores it in secret_number  
*
*****************************************************************************/

void generate_secret_number() {

	srand((unsigned)time(NULL));

	secret_number = rand() % MAX_NUMBER + 1;
}

/*****************************************************************
*
* read_guesses：Repeatedly reads user guesses and gives hints
*               When guess is right,prints the total number of 
*				guesses and returns
*
******************************************************************/

void read_guesses() {

	int guess, count = 0;

	for (;;) {
		printf("Enter guess: ");
		scanf("%d", &guess);
		count++;
		if (guess > secret_number) {
			printf("Too high; try again\n");
		}
		else if (guess < secret_number) {
			printf("Too low; try again.\n");
		}
		else {
			printf("You won in %d guesses!\n\n", count);
			return;
		}
	}
