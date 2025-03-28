#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <signal.h>

void handler(int signum);

int main()
{
	int pid, i;
	/*
	 * Set the signal handler, Child will inherit this also
	 */

	printf("\nmy pid = %d\n", getpid());
	pid = fork();

	if (pid == -1)
		perror("error in fork");

	else if (pid == 0)
	{
		signal(SIGINT, handler);
		printf("\nI am the child, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
		while (1)
		{
		}
	}
	else
	{
		printf("\nI am the parent, my pid = %d and my parent's pid = %d\n\n", getpid(), getppid());
		while (1)
		{
		}
	}

	printf("\nPID %d terminated\n\n", getpid());
	return 0;
}
/*
 * This the the signal handler
 */

void handler(int signum)
{

	printf("Process [%d] received signal #%d\n", getpid(), signum);
}
