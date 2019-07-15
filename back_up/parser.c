#include "../includes/ft_ls.h"
#include <stdio.h>

void	ls_error(char *str, char *opt)
{
	if (!(ft_strcmp(str, "ILLEGAL")))
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putendl_fd(opt, 2);
		ft_putendl_fd("usage: ls [-Ralrt] [file ...]", 2);
		exit (0);
	}
}

void	flag_init(t_flag *flag)
{
	flag->hid = 0;
	flag->ord = 0;
	flag->rev = 0;
	flag->rec = 0;
	flag->l_f = 0;
}

void	flag_parser(t_flag *flag, char *args)
{
	int		i;

	i = 1;
	while (args[i])
	{
		if (args[i] == 'a')
			flag->hid = 1;
		else if (args[i] == 't')
			flag->ord = 1;
		else if (args[i] == 'r')
			flag->rev = 1;
		else if (args[i] == 'R')
			flag->rec = 1;
		else if (args[i] == 'l')
			flag->l_f = 1;
		else if (args[i] != '-')
			ls_error("ILLEGAL", &args[i]);
		i++;
	}
}

t_flag	*parser(t_flag *flag, char **args)
{
	int		i;
	int		j;

	i = 1;
	while (args[i] && args[i][0] == '-')
	{
		j = 1;
		if (args[i][j] == '-' && args[i][j + 1])
			ls_error("ILLEGAL", &args[i][j + 1]);
		flag_parser(flag, args[i]);
		i++;
	}
	return (flag);
}

int		main(int argc, char **argv)
{
	t_flag	*flag;
	t_dir	*curr;

	flag = malloc(sizeof(t_flag));
	flag_init(flag);
	if (argc > 1)
		flag = parser(flag, argv);
	estrazione(".", flag);
	return (0);
}
