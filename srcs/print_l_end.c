#include "../includes/ft_ls.h"

void	stampa_size(t_file *files, int i)
{
	t_stat	st;
	int		len;

	lstat(files->path[i], &st);
	len = sze_len(files, st.st_size, 1);
	while (len < files->s_len)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putmax(st.st_size);
	ft_putchar(' ');
}

void	ora(char *tmp)
{
	ft_putchar(tmp[11]);
	ft_putchar(tmp[12]);
	ft_putchar(tmp[13]);
	ft_putchar(tmp[14]);
	ft_putchar(tmp[15]);
}

void	anno(char *tmp)
{
	ft_putchar(tmp[19]);
	ft_putchar(tmp[20]);
	ft_putchar(tmp[21]);
	ft_putchar(tmp[22]);
	ft_putchar(tmp[23]);
}

void	stampa_tempo(t_file *files, int i)
{
	t_stat	st;
	char	*tmp;

	lstat(files->path[i], &st);
	tmp = ctime(&st.st_mtimespec.tv_sec);
	ft_putchar(tmp[8]);
	ft_putchar(tmp[9]);
	ft_putchar(tmp[3]);
	ft_putchar(tmp[4]);
	ft_putchar(tmp[5]);
	ft_putchar(tmp[6]);
	ft_putchar(tmp[10]);
	if ((files->time - st.st_mtimespec.tv_sec) >= 15768000)
		anno(tmp);
	else
		ora(tmp);
	ft_putchar(' ');
}

void	stampa_slink(t_file *files, int i)
{
	ft_putstr(" -> ");
	ft_putendl(files->s_lnk[i]);
}
