#include <stdio.h>

int main(void)
{
	int input = 0;
	printf("Input an integer\n");
	scanf("%d",&input); //This is the mistake
	printf("The integer you input is %d\n",input);
	return 0;
}
