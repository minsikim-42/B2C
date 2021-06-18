#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	char	*line = 0;
	int		ret;
	int		fd;
	int		i;

	i = 0;
	fd = open("testfile", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s@@@@@ i = %d\n", line, i);
		free(line);
		i++;
	}
	printf("%s\n@@@@@ i = %d\n", line, i);
	return (0);
}
