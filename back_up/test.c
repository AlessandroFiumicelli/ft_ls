#include "../includes/ft_ls.h"
#include <stdio.h>
#include <errno.h>

int		main(void)
{
	int		i;
	t_stat *st;
/*	buf = malloc(sizeof(char*) * 10);
	lstat("./ciao/parser.c", st);
	if (S_ISREG(st->st_mode))
		ft_putendl("Regular");
	if (S_ISLNK(st->st_mode))
	{
		readlink("test", buf, 10);
		ft_putendl("Link");
		ft_putendl(buf);
	}*/
	i = lstat("4", st);
	printf("%s\n", strerror(errno));
	return (0);
}
