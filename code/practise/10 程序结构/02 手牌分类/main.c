/*
 * 程序难点思路：
 *				1）为了判定手中的牌是否重复，我们需要一个布尔类型数组存储整副牌，初始化整个数组为 false。如果一张牌已经在我们手上，那么我们将数组对应的元素置为 true
 *				2）用两个分别数组来存储每个点数和花色的个数，这样方便我们后面判断牌的类型
 *				3）8 种牌的类型，我们可拆成 同花，顺子，4张，3张，对子（值为 0，1，2）这五种基础类型的组合。
 *
 * 程序结构：
 *			通过上面的分析，我们发现：这个程序需要 3 个数组和 5 个变量，如果都作为函数参数传参，显得有些笨。
 *			而且，前面我们说过，函数只能返回一个值，那如果要将函数分离， 5 种基础类型就得放进数组；或者使用指针，而指针我们没有学习，而且指针还是逃不开传参
 *			这样一分析，貌似使用全局变量是最好的做法了。对于初学者来说，这样可能确实是最好的。
 *			但是，使用大量的全局变量是很不好的习惯，我不能让自己去写这样的代码。我认为：宁可这道题不做，也不能有坏的代码风格去写！
 *			后面我们会学习自定义类型：结构体，它可能是这种问题最好的解决方法。
 *			
 *			下面是这个问题的 4 种解决方法：
 *			1)应用全局变量
 *			2）应用指针作为函数参数
 *			3）将判断卡牌类型的函数与打印函数合并
 *			4）使用结构体
 *
 *			在这里，我坚持使用结构体来解决这类问题。全局变量大家只要知道概念即可，对于这道题来说，比起方法，可能设计程序的模块化思路更值得学习。
 *			即使使用结构体，程序的主要逻辑也不会变。如果你非要用全局变量写，那你可以改写一下。
 */

#include<stdio.h>
#include<stdbool.h>

#define RANK 13
#define SUIT 4
#define CARD 5

typedef struct CardType {
	bool flush; //同花
	bool straight; //顺子
	bool four; //四张
	bool three; //三张
	int pair; // 对子
	// 0 表示不是 1 表示 1个对子 2 表示两个对子
	bool cardInHand[SUIT][RANK]; // 判断此牌是否已在手中
	int numRank[RANK]; // 每个点数的个数
	int numSuit[SUIT]; // 每个花色的个数
}CardType;


void initCardType(CardType* card); // 初始化
void readCard(CardType* card); // 读取输入
void analyseCard(CardType* card); // 分析手牌
void printResult(CardType* card); //打印结果

int main(void) {

	CardType card;
	
	for (; ;) {
		initCardType(&card);
		readCard(&card);
		analyseCard(&card);
		printResult(&card);
	}

	return 0;
}


void initCardType(CardType* card) {

	card->flush = false;
	card->straight = false;
	card->four = false;
	card->three = false;
	card->pair = 0;

	int i, j;

	for (i = 0; i < SUIT; i++) {
		card->numSuit[i] = 0;
		for (j = 0; j < RANK; j++) {
			card->cardInHand[i][j] = false;
		}
	}

	for (i = 0; i < RANK; i++) {
		card->numRank[i] = 0;
	}

}


void readCard(CardType* card) {

	int card_read = CARD, rank, suit;
	bool bad_card;
	char ch;

	while (card_read) {
		
		bad_card = false; // 不要忘记重置坏牌的标记

		printf("Enter a card : ");
		
		// 判断点数
		ch = getchar();
		switch (ch) {
			case '0':			exit(0); break;
			case '2':		   rank = 0; break;
			case '3':		   rank = 1; break;
			case '4':		   rank = 2; break;
			case '5':		   rank = 3; break;
			case '6':		   rank = 4; break;
			case '7':		   rank = 5; break;
			case '8':		   rank = 6; break;
			case '9':		   rank = 7; break;
			case 't':case 'T': rank = 8; break;
			case 'j':case 'J': rank = 9; break;
			case 'q':case 'Q': rank = 10; break;
			case 'k':case 'K': rank = 11; break;
			case 'a':case 'A': rank = 12; break;
			default:bad_card = true; break;
		}

		ch = getchar();
		switch (ch) {
			case 'c': case 'C': suit = 0; break;
			case 'd': case 'D': suit = 1; break;
			case 'h': case 'H': suit = 2; break;
			case 's': case 'S': suit = 3; break;
			default: bad_card = true; break;
		}
		
		// ！！！ 精华 1 
		// 检测输入是否多于两个字符
		while ((ch = getchar()) != '\n') {
			if (ch != ' ')
				bad_card = true;
		}

		if (bad_card)
			printf("Bad card; ignored.\n");
		else if (card->cardInHand[suit][rank])
			printf("Duplicated card; ignored.\n");
		else {
			++card->numRank[rank];
			++card->numSuit[suit];
			card->cardInHand[suit][rank] = true;
			card_read--;
		}
	}
}

void analyseCard(CardType* card) {

	int i, count;

	// 同花是五张牌相同花色
	for (i = 0; i < SUIT; i++) {
		if (card->numSuit[i] == 5)
			card->flush = true;
	}
	
	// ！！！ 精华 2 
	// 顺子是五张连续的牌，中间不能隔断
	
	i = 0;
	// 找到数组种第一张存在的牌
	while (card->numRank[i] == 0)
		i++;
	count = 0;
	for (; i < RANK && card->numRank[i] != 0; i++) {
		count++;
	}
	// 顺子必须是五张
	if (count == CARD) {
		card->straight = true;
		return; // 顺子肯定不是对子
	}

	for (i = 0; i < RANK; i++) {
		if (card->numRank[i] == 4)
			card->four = true;
		if (card->numRank[i] == 3)
			card->three = true;
		if (card->numRank[i] == 2)
			++card->pair;
	}
	
}

void printResult(CardType* card) {

	if (card->flush && card->straight)
		printf("Stright flush\n");
	else if (card->four)
		printf("Four of a kind\n");
	else if (card->three && card->pair == 1)
		printf("Full house\n");
	else if (card->flush)
		printf("flush\n");
	else if (card->straight)
		printf("straight\n");
	else if (card->three)
		printf("Three of a kind\n");
	else if (card->pair == 2)
		printf("Two pairs\n");
	else if (card->pair == 1)
		printf("pair\n");
	else
		printf("High card\n");
	
	printf("\n\n");
}
