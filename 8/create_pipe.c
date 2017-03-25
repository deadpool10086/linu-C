#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd[2];
	char str[256];
	if(pipe(fd) < 0) //创建一个管道 返回给fd两个文件描述符 fd[1]管道的写入端，fd[0]管道的读出端。
	{
		printf("create the pipe failed!\n");
		exit(1);
	}
	
	write(fd[1], "create the pipe successfully!\n",31);
	read(fd[0], str, sizeof(str));
	printf("%s",str);
	printf("pipe file descriptors are %d, %d \n",fd[0], fd[1]);

	close(fd[0]);
	close(fd[1]);
	return 0;	
}
