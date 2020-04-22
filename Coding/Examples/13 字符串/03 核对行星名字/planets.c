#include<stdio.h>
#include<string.h>

#define NUM_PLANETS 9

int main(int argc, char* argv[]) {

	int i, j;
	char* planets[NUM_PLANETS] = {
	"Mercury", "Venus", "Earth",
	"Mars", "Jupiter", "Saturn",
	"Uranus", "Neptune", "Pluto"
	};

	for (i = 1; i < argc; i++) {
		for (j = 0; j < NUM_PLANETS; j++)
			if (strcmp(argv[i], planets[j]) == 0) {
				printf("%s is a planet %d\n", argv[i], j + 1);
				break;
			}
		if (j == NUM_PLANETS)
			printf("%s is not a planet\n", argv[i]);
	}

	return 0;
}
// 程序会依次访问每个命令行参数，把它与 planets 中的字符串进行比较，直到找到匹配的名字或到了数组末尾才停止。