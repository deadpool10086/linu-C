#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define FLAGS O_WRONLY|O_CREAT|O_TRUNC
#define MODE S_IRWXU|S_IRGRP|S_IXGRP|S_IROTH|S_IXOTH

int main(void)
{
	const char * pathname;
	int fd;
	char pn[30];
	printf("Input the pathname[<30 strings]:");
	gets(pn);
	pathname = pn;
	if((fd = open(pathname, FLAGS, MODE)) == -1)
	{
		printf("error,open file failed!\n");
		exit(1);
	}
	printf("OK,open file successful\n");
	printf("fd = %d\n",fd);
	return 0;
}
