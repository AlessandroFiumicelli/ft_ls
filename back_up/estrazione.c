#include "../includes/ft_ls.h"
#include <stdio.h>
#include <errno.h>

t_file	*file_init(t_file *files)
{
	files->path = malloc(sizeof(char**) * 8192);
	files->name = malloc(sizeof(char**) * 8192);
	files->perm = malloc(sizeof(mode_t*) * 8192);
	files->prm = malloc(sizeof(char**) * 8192);
	files->link = malloc(sizeof(nlink_t*) * 8192);
	files->us_id = malloc(sizeof(uid_t*) * 8192);
	files->gr_id = malloc(sizeof(gid_t*) * 8192);
	files->us_n = malloc(sizeof(char**) * 8192);
	files->gr_n = malloc(sizeof(char**) * 8192);
	files->l_acs = malloc(sizeof(time_t*) * 8192);
	files->t_dif = malloc(sizeof(time_t*) * 8192);
	files->a_time = time(&files->a_time);
	files->time = malloc(sizeof(char**) * 8192);
	files->size = malloc(sizeof(off_t*) * 8192);
	files->blcks = malloc(sizeof(blkcnt_t*) * 8192);
	files->t_blck = 0;
	files->l_len = 1;
	files->u_len = 0;
	files->g_len = 0;
	files->s_len = 1;
	return (files);
}

int		da_effettuare(t_file *files, t_flag *flag, int i)
{
	int		chk;

	if (flag->ord == 0)
	{
		chk = ft_strcmp(files->name[i - 1], files->name[i]);
		if ((chk > 0 && flag->rev == 1) || (chk < 0 && flag->rev == 0))
			return (0);
	}
	else if (flag->ord == 1)
	{
		if (files->l_acs[i] < files->l_acs[i - 1] && flag->rev == 0)
			return (0);
		else if (files->l_acs[i] > files->l_acs[i - 1] && flag->rev == 1)
			return (0);
	}
	return (1);
}

void	scambio_perm(t_file *files, int i)
{
	mode_t	tmp;

	tmp = files->perm[i - 1];
	files->perm[i - 1] = files->perm[i];
	files->perm[i] = tmp;
}

void	scambio_link(t_file *files, int i)
{
	nlink_t	tmp;

	tmp = files->link[i - 1];
	files->link[i - 1] = files->link[i];
	files->link[i] = tmp;
}

void	scambio_uidegid(t_file *files, int i)
{
	uid_t	tmp;
	gid_t	tmp1;
	char	*us;
	char	*gr;

	tmp = files->us_id[i - 1];
	files->us_id[i - 1] = files->us_id[i];
	files->us_id[i] = tmp;
	tmp1 = files->gr_id[i - 1];
	files->gr_id[i - 1] = files->gr_id[i];
	files->us_id[i] = tmp1;
	us = files->us_n[i - 1];
	files->us_n[i - 1] = files->us_n[i];
	files->us_n[i] = us;
	gr = files->gr_n[i - 1];
	files->gr_n[i - 1] = files->gr_n[i];
	files->gr_n[i] = gr;
}

void	scambio_acs_size(t_file *files, int i)
{
	time_t	tmp;
	off_t	tmp1;

	tmp = files->l_acs[i - 1];
	files->l_acs[i - 1] = files->l_acs[i];
	files->l_acs[i] = tmp;
	tmp1 = files->size[i - 1];
	files->size[i - 1] = files->size[i];
	files->size[i] = tmp1;
}

void	scambio_blcks(t_file *files, int i)
{
	blkcnt_t	tmp;

	tmp = files->blcks[i - 1];
	files->blcks[i - 1] = files->blcks[i];
	files->blcks[i] = tmp;
}

void	scambio_prm(t_file *files, int i)
{
	void	*tmp;

	tmp = files->prm[i];
	files->prm[i] = files->prm[i - 1];
	files->prm[i - 1] = tmp;
}

void	scambio_path(t_file *files, int i)
{
	void	*tmp;

	tmp = files->path[i - 1];
	files->path[i - 1] = files->path[i];
	files->path[i] = tmp;
}

void	scambio_time(t_file *files, int i)
{
	void	*tmp;
	time_t	tmp2;

	tmp = files->time[i - 1];
	files->time[i - 1] = files->time[i];
	files->time[i] = tmp;
	tmp2 = files->t_dif[i - 1];
	files->t_dif[i - 1] = files->t_dif[i];
	files->t_dif[i] = tmp2;
}

void	scambio(t_file *files, int i)
{
	void	*tmp;

	tmp = files->name[i - 1];
	files->name[i - 1] = files->name[i];
	files->name[i] = tmp;
	scambio_path(files, i);
	scambio_perm(files, i);
	scambio_prm(files, i);
	scambio_link(files, i);
	scambio_uidegid(files, i);
	scambio_acs_size(files, i);
	scambio_time(files, i);
	scambio_blcks(files, i);
}

void	ordina(t_file *files, t_flag *flag, int i)
{
	while (i > 0 && da_effettuare(files, flag, i))
	{
		scambio(files, i);
		i--;
	}
}

char	type(mode_t mode)
{
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	return ('-');
}

char	*permessi(t_file *files, t_stat *prm, int i)
{
	char	*buf;
	int		mode;

	mode = ((int)files->perm[i] & S_IFMT);
	buf = malloc(sizeof(char*) * 10);
	ft_bzero(buf, 10);
	files->prm[i] = malloc(sizeof(char*) * 12);
	ft_bzero(files->prm[i], 12);
	files->prm[i][0] = type(files->perm[i]);
	files->prm[i][1] = (S_IRUSR & files->perm[i]) ?'r' : '-';
	files->prm[i][2] = (S_IWUSR & files->perm[i]) ? 'w' : '-';
	files->prm[i][3] = (S_IXUSR & files->perm[i]) ? 'x' : '-';
	files->prm[i][4] = (S_IRGRP & files->perm[i]) ? 'r' : '-';
	files->prm[i][5] = (S_IWGRP & files->perm[i]) ? 'w' : '-';
	files->prm[i][6] = (S_IXGRP & files->perm[i]) ? 'x' : '-';
	files->prm[i][7] = (S_IROTH & files->perm[i]) ? 'r' : '-';
	files->prm[i][8] = (S_IWOTH & files->perm[i]) ? 'w' : '-';
	files->prm[i][9] = (S_IXOTH & files->perm[i]) ? 'x' : '-';
	files->prm[i][10] = ' ';
	return (files->prm[i]);
}

void	uid_e_gid(t_file *files, int i)
{
	t_uid	*us;
	t_gid	*gr;

	us = getpwuid(files->us_id[i]);
	gr = getgrgid(files->gr_id[i]);
	files->us_n[i] = ft_strdup(us->pw_name);
	files->gr_n[i] = ft_strdup(gr->gr_name);
}

void	l_len_e_s_len(t_file *files, int i)
{
	int		tmp;
	int		tmp2;
	int		len;
	int		len2;

	tmp = files->link[i];
	tmp2 = files->size[i];
	len2 = 0;
	len = 0;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	while (tmp2 > 0)
	{
		tmp2 = tmp2 / 10;
		len2++;
	}
	len > files->l_len ? files->l_len = len : files->l_len;
	len2 > files->s_len ? files->s_len = len2 : files->s_len;
}

void	size_len(t_file *files, int i)
{
	int		tmp;
	int		len;

	tmp = files->size[i];
	len = 0;
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	len > files->s_len ? files->s_len = len : files->s_len;
}

void	get_size(t_file *files, int i, t_flag *flag)
{
	int		chk;
	int		chk2;

	if (flag->hid == 0 && files->name[i][0] == '.')
		return ;
	l_len_e_s_len(files, i);
	chk = ft_strlen(files->us_n[i]);
	chk2 = ft_strlen(files->gr_n[i]);
	chk > files->u_len ? files->u_len = chk : files->u_len;
	chk2 > files->g_len ? files->g_len = chk2 : files->g_len;
	size_len(files, i);
}

void	riempi_files(t_file *files, t_dir *entr, t_flag *flag, char *path)
{
	int		i;
	t_stat	*prm;
	char	*tmp;

	i = 0;
	while (files->name[i])
		i++;
	files->name[i] = ft_strdup(entr->d_name);
	files->path[i] = ft_strjoin(path, files->name[i]);
	prm = malloc(sizeof(t_stat));
	lstat(files->path[i], prm);
	files->perm[i] = prm->st_mode;
	files->prm[i] = permessi(files, prm, i);
	files->link[i] = prm->st_nlink;
	files->us_id[i] = prm->st_uid;
	files->gr_id[i] = prm->st_gid;
	files->l_acs[i] = prm->st_mtimespec.tv_sec;
	files->t_dif[i] = files->a_time - files->l_acs[i];
	tmp = ctime(&files->l_acs[i]); 
	files->time[i] = ft_strdup(tmp);
	files->size[i] = prm->st_size;
	files->blcks[i] = prm->st_blocks;
	files->t_blck += files->blcks[i];
	uid_e_gid(files, i);
	get_size(files, i, flag);
	ordina(files, flag, i);
}

void	ora(t_file *files, int i)
{
	ft_putchar(files->time[i][11]);
	ft_putchar(files->time[i][12]);
	ft_putchar(files->time[i][13]);
	ft_putchar(files->time[i][14]);
	ft_putchar(files->time[i][15]);
}

void	anno(t_file *files, int i)
{
	ft_putchar(files->time[i][19]);
	ft_putchar(files->time[i][20]);
	ft_putchar(files->time[i][21]);
	ft_putchar(files->time[i][22]);
	ft_putchar(files->time[i][23]);
}

void	stampa_tempo(t_file *files, int i)
{
	ft_putchar(files->time[i][8]);
	ft_putchar(files->time[i][9]);
	ft_putchar(files->time[i][3]);
	ft_putchar(files->time[i][4]);
	ft_putchar(files->time[i][5]);
	ft_putchar(files->time[i][6]);
	ft_putchar(files->time[i][10]);
	if (files->t_dif[i] >= 15768000)
		anno(files, i);
	else
		ora(files, i);
	ft_putchar(' ');
}

void	stampa_l_4(t_file *files, int i)
{
	int		tmp;
	int		len;

	ft_putchar(' ');
	files->size[i] == 0 ? (len = 1) : (len = 0);
	tmp = files->size[i];
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	while (len != files->s_len)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putnbr(files->size[i]);
	ft_putchar(' ');
	stampa_tempo(files, i);
}

void	stampa_l_3(t_file *files, int i)
{
	int		len;

	ft_putchar(' ');
	len = ft_strlen(files->us_n[i]);
	while (len != files->u_len)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putstr(files->us_n[i]);
	ft_putchar(' ');
	ft_putchar(' ');
	len = ft_strlen(files->gr_n[i]);
	while (len != files->g_len)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putstr(files->gr_n[i]);
	ft_putchar(' ');
	stampa_l_4(files, i);
}

void	stampa_l_2(t_file *files, int i)
{
	int		tmp;
	int		len;

	ft_putchar(' ');
	files->link[i] == 0 ? (len = 1) : (len = 0);
	tmp = files->link[i];
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	while (len != files->l_len)
	{
		ft_putchar(' ');
		len++;
	}
	ft_putnbr(files->link[i]);
	stampa_l_3(files, i);
}

void	stampa_slink(t_file *files, int i)
{
	char	*buf;

	ft_putstr(" -> ");
	buf = malloc(sizeof(char*) * NAME_MAX);
	ft_bzero(buf, NAME_MAX);
	readlink(files->path[i], buf, NAME_MAX);
	ft_putendl(buf);
	free (buf);
}

void	stampa_l(t_file *files, t_flag *flag, char **crt)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_putstr("total ");
	ft_putnbr(files->t_blck);
	ft_putchar('\n');
	while (files->name[i])
	{
		if (flag->hid == 0 && files->name[i][0] == '.')
			i++;
		else
		{
			if (files->prm[i][0] == 'd' && (ft_strcmp(files->name[i], ".") &&
			ft_strcmp(files->name[i], "..")))
			{
				crt[j] = ft_strdup(files->path[i]);
				j++;
			}
			ft_putstr(files->prm[i]);
			stampa_l_2(files, i);
			ft_putstr(files->name[i]);
			if (files->prm[i][0] == 'l')
				stampa_slink(files, i);
			else
				ft_putchar('\n');
			i++;
		}
	}
	crt[j] = NULL;
}

void	stampa(t_file *files, t_flag *flag, char **crt)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (flag->l_f == 1)
	{
		stampa_l(files, flag, crt);
		return ;
	}
	while (files->name[i])
	{
		if (flag->hid == 0 && files->name[i][0] == '.')
			i++;
		else
		{
			if (files->prm[i][0] == 'd' && (ft_strcmp(files->name[i], ".") &&
			ft_strcmp(files->name[i], "..")))
			{
				crt[j] = ft_strdup(files->path[i]);
				j++;
			}
			ft_putendl(files->name[i]);
			i++;
		}
	}
	crt[j] = NULL;
}

int		crt_num(t_file *files, t_flag *flag)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (files->prm[i])
	{
		if (ft_strcmp(files->name[i], ".") && ft_strcmp(files->name[i], ".."))
		{
			if (files->prm[i][0] == 'd')
			{
				if (files->name[i][0] == '.' && flag->hid == 1)
					ret++;
				else if (files->name[i][0] != '.')
					ret++;
			}
		}
		i++;
	}
	return (ret + 1);
}

void	recursion(char **crt, t_flag *flag)
{
	int		i;

	i = 0;
	while (crt[i])
	{
		estrazione(crt[i], flag);
		i++;
	}
}

char	*get_name(char *path)
{
	int		i;
	int		j;
	int		k;
	char	*name;

	i = 0;
	while (path[i])
		i++;
	i -= 2;
	j = i + 1;
	while (path[i] != '/')
		i--;
	name = malloc(sizeof(char*) * (j - i));
	ft_bzero(name, (j - i));
	k = 0;
	i++;
	while (i < j)
	{
		name[k] = path[i];
		i++;
		k++;
	}
	return (name);
}

void	ft_error(char *path)
{
	char	*err;
	char	*name;

	err = strerror(errno);
	name = get_name(path);
	if (ft_strcmp(err, "Bad file descriptor") == 0)
	{
		err = ft_strdup("directory causes a cycle");
	}
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
}

int		fd_check(char *path)
{
	t_stat	*st;

	if (lstat(path, st) < 0)
		return (-1);
	return (0);
}

void	estrazione(char *name, t_flag *flag)
{
	DIR		*dirp;
	t_file	*files;
	t_dir	*entr;
	char	*path;
	char	**crt;

	path = ft_strjoin(name, "/");
//	if (ft_strcmp(path, "./"))
//		ft_putchar('\n');
	if ((dirp = opendir(path)))
	{
		files = malloc(sizeof(t_file));
		files = file_init(files);
		while ((entr = readdir(dirp)))
			riempi_files(files, entr, flag, path);
	}
	else
	{
	//	if (fd_check(path) < 0)
	//	{
	//		ft_error(path);
	//		return ;
	//	}
		ft_error(path);
		return ;
	}
	crt = malloc(sizeof(char**) * crt_num(files, flag));
	if (ft_strcmp(path, "./"))
		ft_putchar('\n');
	if (ft_strcmp(name, "."))
		ft_putendl(path);
	stampa(files, flag, crt);
	free(files);
	free(path);
	closedir(dirp);
	if (flag->rec == 1 && crt)
		recursion(crt, flag);
	free(entr);
	free(crt);
}
