#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 21
#define REMOTE_IP "208.118.235.20"

int main(void)
{
	int sockfd;
	struct sockaddr_in addr;
	char buf[256];
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("socket created error!");	
		exit(1);
	}
	else
	{
		printf("socket created successfully!\n");
		printf("socked id:%d\n");
	}
	
	bzero(&addr, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = inet_addr(REMOTE_IP);

	if(connect(sockfd, (struct sockaddr *)(&addr), sizeof(struct sockaddr)) < 0 )
	{
		perror("connect error");
		exit(1);
	}
	else
	{
		printf("connected successfully!\n");
		printf("remote ip:%d\n");
		printf("remote port:%d\n");
	}

	recv(sockfd, buf, sizeof(buf), 0);
	printf("%s\n",buf);
	return 0;
}
