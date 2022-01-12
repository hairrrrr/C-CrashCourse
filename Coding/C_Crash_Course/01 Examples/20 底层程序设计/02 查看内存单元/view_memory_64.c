//
//  main.c
//  view_memory
//
//

#include <stdio.h>
#include <ctype.h>
#include <stdint.h>

typedef unsigned char BYTE;

int main(void) {

    uint64_t addr;
    int i, n;
    BYTE *ptr;

    printf("Address of main function: %llx\n", (uint64_t)main);
    printf("Address of addr variable: %llx\n", (uint64_t)&addr);
    printf("\nEnter a (hex)address: ");
    scanf("%llx", &addr);
    printf("Enter number of bytes to view: ");
    scanf("%d", &n);
    
    printf("\n");
    printf("  Address             Bytes               Characters\n");
    printf("----------------------------------------------------\n");
    
    ptr = (BYTE*)addr;
    for (; n > 0; n -= 10) {
        printf("%8llX  ", (uint64_t)ptr);
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

