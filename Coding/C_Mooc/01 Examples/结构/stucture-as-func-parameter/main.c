#include<stdbool.h>

struct date {
	int month;
	int day;
	int year;
	//月 - 日 - 年 咱得国际化！
};

bool isleap(struct date d);//判断是否为闰年
int NumberOfDays(struct date d);//判断天数
bool ErrorInputCheck(struct date d);//检查是否是合法输入

int main(void) {
	
	struct date today, tomorrow;
	int flag = 0;

	printf("Input today's date:(format: month day year)\n");
	scanf("%d %d %d", &today.month, &today.day, &today.year);

	if (ErrorInputCheck(today))
		return 0;

	if (today.day != NumberOfDays(today)) {

		tomorrow = today;
		tomorrow.day++;

	}
	else if (today.month != 12) {

		tomorrow.day = 1;
		tomorrow.month = today.month + 1;
		tomorrow.year = today.year;

	}
	else {

		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year = today.year + 1;

	}

	printf("%d - %d - %d\n", tomorrow.month, tomorrow.day, tomorrow.year);

	return 0;
}

bool ErrorInputCheck(struct date d) {
	
	bool flag = false;

	if (d.day <= 0 || d.day > 31) {

		printf("illegal input of day!\n");
		flag = true;

	}
	if (d.month <= 0 || d.month > 12) {

		printf("illegal input of month!\n");
		flag = true;

	}
	if (d.year < 0) {

		printf("illegal year!\n");
		flag = true;

	}

	return flag;
}

int NumberOfDays(struct date d) {

	int day = 0;
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (d.month == 2 && isleap)
		day = 29;
	else
		day = days[d.month - 1];

	return day;
}

bool isleap(struct date d) {

	bool leap = false;
	int year = d.year;

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		leap = true;

	return leap;
}