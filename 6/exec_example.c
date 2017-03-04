#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *envp[] = {"PATH=/temp","USER=root","STATUS=testing",NULL};
	char *argv_execv[] = {"echo","executed by execv",NULL};
	char *argv_execvp[] = {"echo","executed by execvp",NULL};
	char *argv_execve[] = {"env",NULL};

	if(fork() == 0)
	{
		if(execl("/bin/echo","echo","executed by execle",NULL))
		{
			perror("Err on execl");
		}
	}
	if(fork() == 0)
	{
		if(execlp("echo","echo","executed by execlp",NULL))
		{
			perror("Err on execlp");
		}
	}
	if(fork() == 0)
	{
		if(execle("/usr/bin/env","env",NULL,envp))
		{
			perror("Err on execle");
		}
	}
	if(fork() == 0)
	{
		if(execv("/bin/echo",argv_execv))
		{
			perror("Err on execv");
		}
	}
	if(fork() == 0)
	{
		if(execvp("echo",argv_execvp))
		{
			perror("Err on execvp");
		}
	}
	if(fork() == 0)
	{
		if(execve("/usr/bin/env",argv_execve,envp))
		{
			perror("Err on execve");
		}
	}
	return 0;	
}
