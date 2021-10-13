#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	send_char(pid_t pid, char message)
{
	int		bit;
	int		i;
	// unsigned char	uc;

	// uc = (unsigned char)message;
	// if (uc > 127)
	// 	return ;
	i = 0;
	while (i < 7)
	{
		usleep(100);
		bit = (message >> i) & 1;
		if (bit == 1)
		{
			printf("%d", bit);
			kill(pid, SIGUSR1);
		}
		else
		{
			printf("%d", bit);
			kill(pid, SIGUSR2);
		}
		i++;
	}
}

int		ft_strlen(char *arr)
{
	int		i;

	i = 0;
	while (arr[i] != 0)
	{
		i++;
	}
	return (i);
}

int ft_atoi(char *arr)
{
	int		i;
	int		num;

	num = 0;
	i = 0;
	while (i < ft_strlen(arr))
	{
		num = num * 10 + arr[i] - 48;
		i++;
	}
	return num;
}

int	main(int argc, char *argv[])
{
	int		i;

	if (argc != 3)
		return (-1);
	i = 0;
	printf("start![%d][%d][%s]\n", ft_atoi(argv[1]), ft_strlen(argv[2]), argv[2]);
	while (i < ft_strlen(argv[2]))
	{
		printf("[%d][%d][%c]\n", i, ft_atoi(argv[1]), argv[2][i]);
		send_char(ft_atoi(argv[1]), argv[2][i]);
		i++;
	}
	return (0);
}
