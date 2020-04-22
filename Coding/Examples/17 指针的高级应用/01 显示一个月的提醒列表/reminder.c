#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_REMIND 50
#define MSG_LEN 100


int read_line(char str[], int read_num);

int main(void) {
	
	char* reminders[MAX_REMIND]; // 存放提示的数组 // change
	char day_str[3];//当前日期转换为字符串
	char msg_str[MSG_LEN + 1]; //当前输入的提示消息
	int day, num_remind = 0; // 日期和当前提示数
	int i, j;


	for (;;) {

		if (num_remind == MAX_REMIND) {
			printf("-- No space left --\n");
			break;
		}

		printf("Enter day and reminder:");

		scanf("%2d", &day); //每月的日期只用两个数表示即可，只读 2 个字段

		if (day == 0)
			break;

		sprintf(day_str, "%2d", day); // 将 day 以 "%2d" 的格式写入 day_str 字符数组中。"%2d" 保证小于10的天占两位右对齐
		read_line(msg_str, MSG_LEN);
		

		// 寻找当前输入的提示应该放到提示数组的那个位置
		for (i = 0; i < num_remind; i++) {
			// 说明当前输入的日期应该排在此行前
			if (strcmp(day_str, reminders[i]) < 0)
				break;
		}
		
		// 将当前输入的提示插入到正确的位置
		for (j = num_remind; j > i; j--) {
			reminders[j] = reminders[j - 1]; // change
		}

		reminders[i] = (char*)malloc(sizeof(msg_str) + sizeof(day_str) + 1); // change
		
		// change																	 
		if (reminders[i] == NULL) {
			printf("-- No space left --\n");
			break;
		}
	
		strcpy(reminders[i], day_str);
		strcat(reminders[i], msg_str);// 刚好将 day_str 复制进去的空字符覆盖掉了

		num_remind++;
	}

	printf("Day Reminder: \n");
	for (i = 0; i < num_remind; i++)
		printf("%s\n", reminders[i]);


	return 0;
}


int read_line(char str[], int read_num) {

	int ch, count = 0;

	while ((ch = getchar()) != '\n') {
		if (count < read_num) {
			str[count++] = ch;
		}
	}

	str[count] = '\0';

	return count;
}
