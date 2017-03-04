#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char c;
	char str[20];
	enter_string(str);
	printf("The delete atring is: ");
	scanf("%c",&c);
	delete_string(str,c);
	print_string(str);
	return 0;	
}
