#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char *argv[]){

	int i= 0;
	int status;
	for(i=0;i<4;i++){
	pid_t childpid = fork();
		if(childpid > 0){
			printf("Coordinator: forked process with ID %d.\n",childpid);
			printf("Coordinator: waiting for process [%d].\n", childpid);
			waitpid(childpid, &status,0);
			if(status != 0){
			  printf("Coordinator: child process %d returns %d.\n", childpid, WEXITSTATUS(status));
			}
			else{
			  printf("Coordinator: child process %d returns %d.\n",childpid, WEXITSTATUS(status));
			}
	
			   
			}
		else if(childpid==0){
			execlp("checker", "checker", argv[1], argv[i+2], (char*)NULL);
		}

		else{
			printf("fork fail\n");
			exit(0);
		}
	}
	printf("Coordinator: exiting.\n");
	exit(1);
}
