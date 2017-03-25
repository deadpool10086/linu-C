#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	char name[4];
	int age;
}people;

int main(int argc, char **argv)
{
	int shm_id;
	int i;
	char temp;

	people *p_map;
	if( argc != 2)
	{
		printf("USAGE:atshm <identifier>");	
		exit(1);
	}


	shm_id = atoi(argv[1]);
	p_map = (people *)shmat(shm_id, NULL, 0);
	temp = 'a';
	
	for( i=0; i<10; i++)
	{
		temp += 1;
		memcpy((*(p_map + i)).name, &temp, 1);
		(*(p_map + i)).age = 20 + i;
	}

	if(shmdt(p_map) == -1)
	{
		perror("detach error!\n");	
	}
	return 0;
		
}
