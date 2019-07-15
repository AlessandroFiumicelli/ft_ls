#include "../includes/ft_ls.h"

char	*path_of_arg(char *name)
{
	char	*tmp;

	if (name[0] == '~' || name[0] == '/' || (name[0] == '.' && (name[1] == '/'
	|| !name[1])) || (name[0] == '.' && name[1] == '.' && (name[2] == '/' ||
	!name[2])))
		tmp = ft_strdup(name);
	else
		tmp = ft_strjoin("./", name);
	return (tmp);
}

void	args_check(t_flag *flag, char **args)
{
	t_stat	st;
	int		i;
	char	*path;

	i = 0;
	while (args[i])
	{
		path = path_of_arg(args[i]);
		if (lstat(path, &st) >= 0)
		{
			if (S_ISDIR(st.st_mode))
				flag->d_n++;
			else
				flag->f_n++;
		}
		else
			ft_error(path);
		free(path);
		i++;
	}
}

void	files(t_flag *flag, char **args)
{
	t_stat	st;
	char	*path;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (i < (flag->f_n))
	{
		path = path_of_arg(args[j]);
		if (lstat(path, &st) >= 0 && !(S_ISDIR(st.st_mode)))
		{
			flag->args[i] = ft_strdup(path);
			i++;
		}
		free(path);
		j++;
	}
}

void	dirs(t_flag *flag, char **args)
{
	t_stat	st;
	char	*path;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (i < (flag->d_n))
	{
		path = path_of_arg(args[j]);
		if (lstat(path, &st) >= 0 && S_ISDIR(st.st_mode))
		{
			flag->dirs[i] = ft_strdup(path);
			i++;
		}
		free(path);
		j++;
	}
}

void	get_args(t_flag *flag, char **args)
{
	sort_args(args);
	args_check(flag, args);
	args_init(flag);
	files(flag, args);
	dirs(flag, args);
	re_sort_args(flag);
}
