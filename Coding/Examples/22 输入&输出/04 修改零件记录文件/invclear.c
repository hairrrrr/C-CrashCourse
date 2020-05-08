#include<stdio.h>
#include<stdlib.h>

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
	int number;
	char name[NAME_LEN + 1];
	int on_hand;
}inventory[MAX_PARTS];

int num_part;

int main() {

	FILE* fp;
	int i;

	if ((fp = fopen("inventory.dat", "rb+")) == NULL) {
		fprintf(stderr, "Can't open inventory file.\n");
		exit(EXIT_FAILURE);
	}

	num_part = fread(inventory, sizeof(struct part), MAX_PARTS, fp);

	for (i = 0; i < num_part; i++)
		inventory[i].on_hand = 0;

	rewind(fp);
	// 这里调用 rewind 函数是很关键的。在调用完 fread 函数之后，文件位置是在文件的末尾。如果不调用 rewind 就调用 fwrite ，那么 fwrite 将会在文件末尾添加新数据，而不会覆盖旧数据。
	fwrite(inventory, sizeof(struct part), num_part, fp);

	fclose(fp);
	
	return 0;
}
