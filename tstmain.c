#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get-next-line/get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_num;

	line_num = 1;
	if (argc < 2)
	{
		printf("Error! Too few arguments.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line %d: [%s]", line_num++, line);
		free(line);
	}
	printf("Line %d: [%s]", line_num++, line);
	close(fd);
	return (0);
}
