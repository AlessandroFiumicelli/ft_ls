#include "../includes/ft_ls.h"

int		lessico(t_file *files, t_flag *flag, int i)
{
if (flag->rev == 0 && ft_strcmp(files->name[i], files->name[i -1]) < 0)
		return (1);
	else if (flag->rev == 1 &&
	ft_strcmp(files->name[i], files->name[i - 1]) > 0)
		return (1);
	return (0);
}

int		tempo(t_file *files, t_flag *flag, int i)
{
	t_stat  st1;
	t_stat  st2;

	lstat(files->path[i], &st1);
	lstat(files->path[i - 1], &st2);
	if (flag->rev == 0 && (st1.st_mtimespec.tv_sec > st2.st_mtimespec.tv_sec))
		return (1);
	if (flag->rev == 1 && (st1.st_mtimespec.tv_sec < st2.st_mtimespec.tv_sec))
		return (1);
	return (0);
}

int		da_effettuare(t_file *files, t_flag *flag, int i)
{
	if (flag->ord == 0)
		return (lessico(files, flag, i));
	else
		return (tempo(files, flag, i));
}

void	scambio(t_file *files, int i)
{
	void    *tmp;

	tmp = files->name[i];
	files->name[i] = files->name[i - 1];
	files->name[i - 1] = tmp;
	tmp = files->path[i];
	files->path[i] = files->path[i - 1];
	files->path[i - 1] = tmp;
	tmp = files->s_lnk[i];
	files->s_lnk[i] = files->s_lnk[i - 1];
	files->s_lnk[i - 1] = tmp;
}
