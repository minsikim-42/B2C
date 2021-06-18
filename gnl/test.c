#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
	int fd;
	char buf[20];
	int n;
	//char **p;
	//char swap[10];
	//static 

	fd = open("test.txt", O_RDONLY);
	n = read(fd, buf, 10);

	printf("fd = %d, read = %d", fd, n);
	n = read(fd, buf, 10);
	//p[i] = malloc(swap + strlen); // until

	printf("read = %d", n);
	n = 0;
	while (buf[n])
	{
		write(1, &buf[n], 1);
		n++;
	}
	close(fd);
}
