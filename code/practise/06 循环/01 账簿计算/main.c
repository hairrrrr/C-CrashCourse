#include<stdio.h>

int main(void) {

	double balance = 0; // 余额
	double credit, debit;

	// 菜单，形式可以自己设计，尽量美观一点嘛，不过不用纠结这种界面，不要舍本逐末。

	printf("**** ACME checkbook-balancing program ****\n");
	printf("     Comands:                             \n");
	printf("             0 = clear                    \n");
	printf("             1 = credit                   \n");
	printf("             2 = debit                    \n");
	printf("             3 = balance                  \n");
	printf("             4 = exit                     \n");

	// 题目中已经规定了这些功能用 0，1，2，3，4 代替，其实是想让我们用 switch
	// 如果你想用 if else 也完全 ok

	// 死循环让用户可以重复选择
	while (1) {
		int choice;
		printf("Enter command: ");
		scanf("%d", &choice);
		
		switch (choice) {
					
					// 清除账户是一种很“危险”的举动，可以让用户确认一次

			case 0:	printf("Are you sure to clear your balance?\n");
					printf("1 = yes, 0 = no\n");
					int isClear;
					scanf("%d", &isClear);
					if (isClear == 1) {
						balance = 0;
						printf("clear successfully!\n");
					}					
					break;
			
			case 1: printf("Enter amount of credit: ");
					scanf("%lf", &credit);
					balance += credit;
					break;
			
			case 2: printf("Enter amount of debit : ");
					scanf("%lf", &debit);
					balance -= debit;
					break;

			case 3: printf("Current balance: %.2f\n", balance);
					break;
					
			case 4: printf("Are you sure to quit?\n");
					printf("1 = yes, 0 = no\n");
					int isQuit;
					scanf("%d", &isQuit);
					if (isQuit == 1) {
						printf("Goodbye~\n");
						return 0;
					}
					else {
						break;
					}
			default: printf("Illeagl option!\n");
					 break;
		}
	}
}

