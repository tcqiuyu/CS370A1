#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int arg1=atoi(argv[1]);
	int arg2=atoi(argv[2]);
	int output=0;
	printf("Checker Process [%d]: Starting.\n", getpid());

	if (arg2 % arg1 !=0){
		printf("Checker Process [%d]: %d *IS NOT* divisible by %d.\n", getpid(), arg2, arg1);
		output = 0;
	}else if(arg2 % arg1==0){
		printf("Checker Process [%d]: %d *IS* divisible by %d.\n", getpid(), arg2, arg1);
		output = 1;
	}
	printf("Checker Process [%d]: Return %d.\n", getpid(), output);
	exit(output);
}
