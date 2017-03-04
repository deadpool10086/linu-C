#include  <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	if(lseek(0,0,SEEK_CUR) == -1)
	{
		printf("canot seek!\n");
	}
	else
	{
		printf("seek OK!\n");	
	}
	return 0;
}
