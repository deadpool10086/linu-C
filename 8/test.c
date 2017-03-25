#include <stdio.h>
#include <limits.h>

int main(int argc,char ** argv)
{
	printf("sizeof(int) is %d, INT_MAX is %d\n",sizeof(int),INT_MAX);
	printf("sizoef(long) is %d, LONG_MAX is %ld\n",sizeof(long),LONG_MAX);
	return 0;	
}
