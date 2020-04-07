#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_NUMBER 100

int generate_secret_number();// 随机数生成
void read_guesses(int secret_number); // 猜的实现

int main(void) {

	char command;
	int secret_number;

	printf("Guess the secret number between 1 and 100.\n");
	
	do {
		secret_number = generate_secret_number();
		printf("A new number has been chosen.\n");
		read_guesses(secret_number);
		printf("Play again?(Y/N)");
		scanf(" %c", &command);
		printf("\n");
	} while (command == 'y' || command == 'Y');

	return 0;
}


int generate_secret_number() {

	srand((unsigned)time(NULL));

	int secret_number = rand() % MAX_NUMBER + 1;

	return secret_number;
}

void read_guesses(int secret_number) {

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
}

