#include <stdio.h>

int max(int i, int j)
{
	if(i>j)
		return(i);
	else
		return(j);
}

int main()
{
	int num1,num2;
	printf("Input two nummbers");
	scanf("%d%d",&num1,&num2);
	max(num1,num2);
	return 0;	
}

