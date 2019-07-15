#include "../includes/ft_ls.h"

void	sizes(t_file *files, t_stat *st)
{
	lnk_len(files, st->st_nlink, 1);
	usr_len(files, st->st_uid);
	grp_len(files, st->st_gid);
	sze_len(files, st->st_size, 1);
}

void	ordina(t_file *files, t_flag *flag, int i)
{
	while (i > 0 && da_effettuare(files, flag, i))
	{
		scambio(files, i);
		i--;
	}
}

void	riempi_files_2(t_file *files, t_stat *st , int i)
{
	char	buf[NAME_MAX + 1];

	if (S_ISLNK(st->st_mode))
	{
		ft_bzero(&buf, (NAME_MAX + 1));
		readlink(files->path[i], buf, NAME_MAX);
		files->s_lnk[i] = ft_strdup(buf);
	}
}

void	riempi_files(t_file *files, t_flag *flag, char *name)
{
	char	*tmp;
	t_stat	st;
	int		i;

	if (flag->hid == 0 && name[0] == '.')
		return ;
	i = 0;
	while (files->name[i])
		i++;
	tmp = ft_strjoin(files->d_pth, name);
	if (lstat(tmp, &st) < 0)
	{
		ft_error(tmp);
		free(tmp);
		return ;
	}
	files->path[i] = ft_strdup(tmp);
	free(tmp);
	files->name[i] = ft_strdup(name);
	riempi_files_2(files, &st, i);
	files->t_blck += st.st_blocks;
	sizes(files, &st);
	ordina(files, flag, i);
}
