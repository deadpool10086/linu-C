#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[], char *envp[])
{
	printf("###ARGC###\n%d\n",argc);
	while(*argv)
		printf("%s\n",*(argv++));
	printf("###ENVP###\n");
	while(*envp)
	{
		printf("%s\n",*(envp++));	
	}
	return 0;	
}
