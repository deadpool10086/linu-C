#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5566

int main(void)
{
	int sockfd, newsockfd;
	struct sockaddr_in addr;
	int addr_len = sizeof(struct sockaddr_in);
	char msgbuf[256];
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("soclet created error!");
		exit(1);
	}
	else
	{
		printf("socket created sucessfully!\n");
		printf("socked id:%d \n",sockfd);
	}

	bzero(&addr, sizeof(struct sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(bind(sockfd, (struct sockaddr *)(&addr),sizeof(struct sockaddr)) < 0)
	{
		perror("bind error");
		exit(1);
	}
	else
	{
		printf("bind port successfully!\n");
		printf("local port:%d\n",PORT);
	}
	
	if(listen(sockfd, 5) < 0)
	{
		perror("accept error!");	
		exit(1);
	}
	else
	{
		printf("listening......\n");
	}

	if((newsockfd = accept(sockfd, (struct sockaddr *)(&addr),(socklen_t *)&addr_len)) < 0)
	{
		perror("accept error");	
	}
	else
	{
		printf("connect from %s\n",inet_ntoa(addr.sin_addr));
		if(read(newsockfd, msgbuf, sizeof(msgbuf)) <= 0)
		{
			perror("read error!");
		}
		else
		{
			printf("message:\n%s\n",msgbuf);	
		}
	}
	return 0;	
}
