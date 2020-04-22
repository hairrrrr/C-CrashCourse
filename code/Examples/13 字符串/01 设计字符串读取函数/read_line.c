int read_line(char str[], int read_num) {
	
	int ch, i = 0;

	while ((ch = getchar()) != '\n' && ch != EOF) {
		// i 大于 read_num 不执行操作，跳过后面的字符 
		if (i < read_num)
			str[i++] = ch;
	}
    
	str[i] = '\0';
	
	return i;
}

// ch 的类型是 int 而不是 char ，只是因为 getchar 把它读入的字符作为 int 类型的值返回。 
