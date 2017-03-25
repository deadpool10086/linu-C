#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char name[4];	
	int age;
}people;


int main(int argc, char ** argv)
{
	int shm_id, i;
	people* p_map;

	if(argc != 2)
	{
		printf("USAGE:atshm <identifier>");	
		exit(1);
	}
	shm_id = atoi(argv[1]);
	p_map = (people* )shmat(shm_id, NULL, 0);
	for(i=0; i<10; i++)
	{
		printf("name:%s  ",(*(p_map + i)).name);
		printf("age %d\n",(*(p_map + i)).age);
	}
	if(shmdt(p_map) == -1)
	{
		perror("detach error!\n");	
	}
	return 0;	
}
