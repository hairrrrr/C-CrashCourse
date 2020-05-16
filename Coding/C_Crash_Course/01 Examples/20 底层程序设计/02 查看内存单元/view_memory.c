#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<ctype.h>

typedef unsigned char BYTE;

int main(void) {

	unsigned int addr;
	int i, n;
	BYTE* ptr;

	printf("Address of main function: %x\n", (unsigned int)main);
	printf("Address of addr variable: %x\n", (unsigned int)&addr);
	printf("\nEnter a (hex)address: ");
	scanf("%x", &addr);
	printf("Enter number of bytes to view: ");
	scanf("%d", &n);
	
	printf("\n");
	printf("  Address             Bytes               Characters\n");
	printf("----------------------------------------------------\n");
	
	ptr = (BYTE*)addr;
	for (; n > 0; n -= 10) {
		printf("%8X  ", (unsigned int)ptr);
		// 考虑到最后一组不满 10 个字节
		for (i = 0; i < 10 && i < n; i++) {
			printf("%.2X ", *(ptr + i)); // 转换说明：%.2X 相当于 %02hhX 
		}
		// 最后一组不够 10 用空格凑满
		for (; i < 10; i++) {
			printf("   ");
		}
		printf("  ");
		for (i = 0; i < 10 && i < n; i++) {
			BYTE ch = *(ptr + i);
			if (!(isprint(ch)))
				ch = '.';
			printf("%c", ch);
		}
		printf("\n");
		ptr += 10;
	}

	return 0;
}

