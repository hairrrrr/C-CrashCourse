//这是我能理解的格式
int mystrcmp(char* str1, char* str2) {

	int ret = 0;

	while ((ret = ((unsigned char)*str1 - (unsigned char)*str2)) == 0 && *str1) {
		++str1, ++str2;
	}

	return ret;
}


//原版在这里
int __cdecl strcmp(
	const char* src,
	const char* dst
)
{
	int ret = 0;

	while ((ret = *(unsigned char*)src - *(unsigned char*)dst) == 0 && *dst)
	{
		++src, ++dst;
	}
	
	//这里不太理解，那个大神理解了可以给我讲一下，谢谢
	return ((-ret) < 0) - (ret < 0); // (if positive) - (if negative) generates branchless code
}