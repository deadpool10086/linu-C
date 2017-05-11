#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>


#define PORT 80
#define REMOTE_IP "111.13.100.91"

int main(void)
{
	int sockfd;
	struct sockaddr_in addr;
	if( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
	{
		perror("socket created error!");
		exit(1);
	}
	else
	{
		printf("socket created successfully!\n");
		printf("socket is:%d\n",socket);
	}

	bzero(&addr, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(REMOTE_IP);

	if(connect (sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr)) < 0)
	{
		perror("connect error!");
		exit(1);
	}
	else
	{
		printf("connected successfully!\n");	
	}
	return 0;	
}
