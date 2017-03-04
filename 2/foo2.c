int delete_string(char str[], char ch)
{
	int i,j;
	for(i=j=0; str[i]!='\0'; i++)
		if(str[i]!=ch)
			str[j++] = str[j];
	str[j] = '\0';
	return 0;	
}
