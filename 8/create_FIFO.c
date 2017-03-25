#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	mode_t mode = 0666;
	if(argc != 2)
	{
		printf("USEMSG: create_FIFO { FIFO name}\n");	
		exit(1);
	}
	if(mkfifo(argv[1], mode) < 0)
	{
		printf("failed to mikefifo!\n");
		exit(1);
	}
	else
	{
		printf("you successfully create a  FIFO name is: %s\n",argv[1]);	
	}
	return 0;
}
