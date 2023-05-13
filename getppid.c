#include "main.h"
/**
 * main - entry point
 *
 * Return: 0 on success
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	pid_t ppid;
	pid_t pid;

	ppid = getppid();
	pid = getpid();

	printf(" The parent process ID%u\n", ppid);
	printf("The current process ID%u\n",pid);
	return (0);
}
