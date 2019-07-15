#include "../includes/ft_ls.h"

void	re_sort_files(t_flag *flag)
{
	t_stat	st1;
	t_stat	st2;
	char	*tmp;
	int		i;

	i = 0;
	while (flag->args[i + 1])
	{
		lstat(flag->args[i], &st1);
		lstat(flag->args[i + 1], & st2);
		if (st1.st_mtimespec.tv_sec < st2.st_mtimespec.tv_sec)
		{
			tmp = flag->args[i];
			flag->args[i] = flag->args[i + 1];
			flag->args[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	re_sort_dirs(t_flag *flag)
{
	t_stat	st1;
	t_stat	st2;
	char	*tmp;
	int		i;

	i = 0;
	while (flag->dirs[i + 1])
	{
		lstat(flag->dirs[i], &st1);
		lstat(flag->dirs[i + 1], & st2);
		if (st1.st_mtimespec.tv_sec < st2.st_mtimespec.tv_sec)
		{
			tmp = flag->dirs[i];
			flag->dirs[i] = flag->dirs[i + 1];
			flag->dirs[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	re_sort_args(t_flag *flag)
{
	if (flag->args[0] && flag->ord == 1)
		re_sort_files(flag);
	if (flag->dirs[0] && flag->ord == 1)
		re_sort_dirs(flag);
	if (flag->args[0] && flag->rev == 1)
		reverse_files(flag);
	if (flag->dirs[0] && flag->rev == 1)
		reverse_dirs(flag);
}
