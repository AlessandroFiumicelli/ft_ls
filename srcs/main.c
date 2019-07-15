#include "../includes/ft_ls.h"

int		main(int argc, char **argv)
{
	t_flag	flag;

	flag_init(&flag);
	if (argc > 1)
		parser(&flag, argv);
	estrazione(".", &flag, 0);
	return (1);
}
