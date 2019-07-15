#include "../includes/ft_ls.h"

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
		else if (args[i] != '-' || (args[i] == '-' && i > 1))
			ls_error("ILLEGAL", args[i]);
		i++;
	}
}

void	parser(t_flag *flag, char **args)
{
	int		i;
	int		j;

	i = 1;
	while (args[i] && args[i][0] == '-')
	{
		j = 1;
		if (args[i][j] == '-' && args[i][j + 1])
			ls_error("ILLEGAL", args[i][j + 1]);
		flag_parser(flag, args[i]);
		i++;
	}
	if (args[i])
		get_args(flag, &args[i]);
	else
		return ;
	if (flag->args[0] || flag->dirs[0])
		ls_args(flag);
}
