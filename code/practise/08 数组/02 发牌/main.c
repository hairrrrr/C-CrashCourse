#include<stdio.h>
#include<time.h>
#include<stdbool.h>
#include<stdlib.h>

#define NUM_SUIT 4
#define NUM_RANK 13

int main(void) {
	
	int suit, rank, num_cards;

	const char suit_code[] = {'H', 'D', 'C', 'S'}; // heartºìÌÒ diamand·½Æ¬ clubÃ·»¨ spadeºÚÌÒ
	const char rank_code[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
	bool in_hand[NUM_SUIT][NUM_RANK] = { false };

	srand((unsigned)time(NULL));

	printf("Enter number of cards in hand: ");
	scanf("%d", &num_cards);


	printf("Your card(s): ");
	while (num_cards > 0) {
		suit = rand() % NUM_SUIT;
		rank = rand() % NUM_RANK;

		if (!in_hand[suit][rank]) {
			in_hand[suit][rank] = true;
			num_cards--;
			printf("%c%c  ", suit_code[suit], rank_code[rank]);
		}
	}
	printf("\n");

	return 0;
}
