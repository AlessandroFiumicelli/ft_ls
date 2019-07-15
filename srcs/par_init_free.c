#include "../includes/ft_ls.h"

void	flag_init(t_flag *flag)
{
	flag->hid = 0;
	flag->ord = 0;
	flag->rev = 0;
	flag->rec = 0;
	flag->l_f = 0;
	flag->f_n = 0;
	flag->d_n = 0;
	flag->args = NULL;
	flag->dirs = NULL;
}

void	args_init(t_flag *flag)
{
	int		i;

	flag->args = (char**)malloc(sizeof(char*) * (flag->f_n + 1));
	flag->dirs = (char**)malloc(sizeof(char*) * (flag->d_n + 1));
	i = -1;
	while (++i < (flag->f_n + 1))
		flag->args[i] = NULL;
	i = -1;
	while (++i < (flag->d_n + 1))
		flag->dirs[i] = NULL;
}

void	free_flag(t_flag *flag)
{
	int		i;

	i = -1;
	while (++i <= flag->f_n)
		free(flag->args[i]);
	i = -1;
	while (++i <= flag->d_n)
		free(flag->dirs[i]);
}

void	files_init_args(t_file *files, t_flag *flag)
{
	int		i;

	i = 0;
	files->name = (char**)malloc(sizeof(char*) * (flag->f_n + 1));
	files->path = (char**)malloc(sizeof(char*) * (flag->f_n + 1));
	files->s_lnk = (char**)malloc(sizeof(char*) * (flag->f_n + 1));
	while (i <= flag->f_n)
	{
		files->name[i] = NULL;
		files->path[i] = NULL;
		files->s_lnk[i] = NULL;
		i++;
	}
	files->l_len = 0;
	files->u_len = 0;
	files->g_len = 0;
	files->s_len = 0;
	files->time = time(&files->time);
}

void	free_files_args(t_file *files, t_flag *flag)
{
	int		i;

	i = 0;
	while (i <= flag->f_n)
	{
		free(files->name[i]);
		free(files->path[i]);
		free(files->s_lnk[i]);
		i++;
	}
	free(files->name);
	free(files->path);
	free(files->s_lnk);
}
