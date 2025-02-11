#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<sys/wait.h>
int main()
{
	pid_t child1,child2;
	// Parent creates one child
	child1=fork();
	
	
	if(child1==0) // Child 1 runs here
	{
		printf("I am Child 1 having id %d\n",getpid());
		printf("My parent's id is %d\n",getppid());
	}
	else // Parent runs here.
	{
	        // Parent creates a second child
		child2=fork();
		if(child2==0) // Child 2 runs here
		{
			printf("I am Child 2 having id %d\n",getpid());
			printf("My parent's id is %d\n",getppid());
		}
		else // Parent runs here.
		{
		        // One parent process waits for both children to finish.
			waitpid(child1,NULL,0);
			waitpid(child2,NULL,0);
			printf("I am parent having id %d\n",getpid());
			printf("Child 1's id is %d\n",child1);
			printf("Child 2's id is %d\n",child2);
			
		}
		
	}
	printf("\n");
}
