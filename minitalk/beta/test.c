#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *arr)
{
	int		i;

	i = 0;
	while (arr[i] != 0)
	{
		i++;
	}
	return i;
}

int main(int argc, char *argv[])
{
	int	pid;
	
	if (argc != 3)
		return (0);
	pid = atoi(argv[1]);
	printf("send to pid:%d", pid);
	if (argv[2][0] < 'a')
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			printf("Error");
			exit(0);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			printf("Error");
			exit(0);
		}
	}
	return (0);
}	
