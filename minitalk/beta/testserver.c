#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	ft_putnbr(int i)
{
	char	c;
	if (i < 10)
	{
		c = i + '0';
		write(1, &c, 1);
		return ;
	}
	ft_putnbr(i / 10);
	c = (i % 10) + '0';
	write(1, &c, 1);
}

void	ft_putchar(int i)
{
	char	c;

	c = i;
	write(1, &c, 1);
}

void	my_handler(int signum, siginfo_t *siginfo, void *unused)
{
	static int	ascii = 0;
	static int	power = 0;

	(void)unused;
	if (signum == SIGUSR1)
		ascii += 1 << power;
	power += 1;
	if (power == 7)
	{
		ft_putchar(ascii);
		power = 0;
		ascii = 0;
	}
}

int		main(int argc, char *argv[])
{
	struct sigaction	catch;

	(void)argv;

	if (argc != 1)
	{
		printf("error");
		exit(0);
	}
	write(1, "server started\nPID: ", 20);
	ft_putnbr(getpid());
	printf("\n");

	catch.sa_flags = SA_SIGINFO;

	catch.sa_sigaction = my_handler;

	if ((sigaction(SIGUSR1, &catch, 0)) == -1)
	{
		printf("error sigaction");
		exit(1);
	}
	if ((sigaction(SIGUSR2, &catch, 0)) == -1)
	{
		printf("error sigaction");
		exit(1);
	}
	while (1)
	{
		pause(); // continue ;
	}
	return (0);
}
