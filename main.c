#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

void ft_putstr(char *str)
{
	char back = '\n';
	write(1, str, (strlen(str) + 1));
	write(1, &back, 1);
}

int main(int argc, char **argv)
{
	int fd;
	char *line = 0;
	int ligne;
	int i;
	(void)argc;
	ligne = 1;
	if (argv[1])
		fd = open(argv[1], O_RDONLY);
	else
		fd = open("text.txt", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		free(line);
		ligne++;
	}
	printf("line = %s\n", line);
	printf(" i = %d\n", i);
	free(line);
	close(fd);
	// while (1) {}
}
