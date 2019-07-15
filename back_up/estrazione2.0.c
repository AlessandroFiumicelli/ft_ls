#include "../includes/ft_ls.h"
#include <stdio.h>
#include <errno.h>

void	name_init(t_file *files)
{
	int		i;

	i = 0;
	while (i < 8192)
	{
		files->name[i] = NULL;
		i++;
	}
}

t_file	*file_init(t_file *files)
{
	files->path = (char**)malloc(sizeof(char*) * 8192);
	files->name = (char**)malloc(sizeof(char*) * 8192);
	name_init(files);
	files->perm = (mode_t*)malloc(sizeof(mode_t) * 8192);
	files->prm = (char**)malloc(sizeof(char*) * 8192);
	files->link = (nlink_t*)malloc(sizeof(nlink_t) * 8192);
	files->us_id = (uid_t*)malloc(sizeof(uid_t) * 8192);
	files->gr_id = (gid_t*)malloc(sizeof(gid_t) * 8192);
	files->us_n = (char**)malloc(sizeof(char*) * 8192);
	files->gr_n = (char**)malloc(sizeof(char*) * 8192);
	files->l_acs = (time_t*)malloc(sizeof(time_t) * 8192);
	files->t_dif = (time_t*)malloc(sizeof(time_t) * 8192);
	files->a_time = time(&files->a_time);
	files->time = (char**)malloc(sizeof(char*) * 8192);
	files->size = (off_t*)malloc(sizeof(off_t) * 8192);
	files->blcks = (blkcnt_t*)malloc(sizeof(blkcnt_t) * 8192);
	files->t_blck = (int)malloc(sizeof(int));
	files->l_len = 1;
	files->u_len = 0;
	files->g_len = 0;
	files->s_len = 1;
	return (files);
}

int		da_effettuare(t_file *files, t_flag *flag, int i)
{
	int		chk;

	if (files->name[i] && files->name[i - 1])
	{
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
	return (0);
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

void	permessi(t_file *files, int i)
{
	char	*buf;
	int		mode;

	mode = ((int)files->perm[i] & S_IFMT);
	files->prm[i] = (char*)malloc(sizeof(char) * 12);
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
}

void	uid_e_gid(t_file *files, int i)
{
	t_uid	*us;
	t_gid	*gr;

	us = getpwuid(files->us_id[i]);
	gr = getgrgid(files->gr_id[i]);
	if (us)
		files->us_n[i] = ft_strdup(us->pw_name);
	if (gr)
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

void	total_blcks(t_file *files, t_flag *flag, int i)
{
	if (flag->hid == 0 && files->name[i][0] == '.')
		return ;
	files->t_blck += files->blcks[i];
}

void	riempi_files(t_file *files, t_dir *entr, t_flag *flag, char *path)
{
	int		i;
	t_stat	*prm;
	char	*tmp;

	i = 0;
	while (files->name[i])
		i++;
	prm = (t_stat*)malloc(sizeof(t_stat));
	files->path[i] = ft_strjoin(path, entr->d_name);
	if (lstat(files->path[i], prm) < 0)
		return ;
	files->name[i] = ft_strdup(entr->d_name);
//	files->path[i] = ft_strjoin(path, files->name[i]);
	files->perm[i] = prm->st_mode;
	permessi(files, i);
	files->link[i] = prm->st_nlink;
	files->us_id[i] = prm->st_uid;
	files->gr_id[i] = prm->st_gid;
	files->l_acs[i] = prm->st_mtimespec.tv_sec;
	files->t_dif[i] = files->a_time - files->l_acs[i];
	tmp = ctime(&files->l_acs[i]); 
	files->time[i] = ft_strdup(tmp);
	files->size[i] = prm->st_size;
	files->blcks[i] = prm->st_blocks;
	total_blcks(files, flag, i);
	uid_e_gid(files, i);
	if (files->us_n[i] && files->gr_n[i])
		get_size(files, i, flag);
	ordina(files, flag, i);
	free(prm);
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
	buf = (char*)malloc(sizeof(char) * NAME_MAX);
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
		{
			free_single(files, i);
			i++;
		}
		else
		{
			if (flag->rec == 1 &&
			files->prm[i][0] == 'd' && (ft_strcmp(files->name[i], ".") &&
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
			free_single(files, i);
			i++;
		}
	}
	free_single(files, i);
	crt[j] = NULL;
}

void	free_single(t_file *files, int i)
{
	free(files->name[i]);
	free(files->path[i]);
	free(files->prm[i]);
	free(files->us_n[i]);
	free(files->gr_n[i]);
	free(files->time[i]);
}

void	free_rest(t_file *files)
{
	free(files->perm);
	free(files->link);
	free(files->us_id);
	free(files->gr_id);
	free(files->l_acs);
	free(files->t_dif);
	free(files->size);
	free(files->blcks);
}

void	free_a_lot(t_file *files, int i)
{
	while (i < 8192)
	{
		free_single(files, i);
		i++;
	}
}

void	stampa(t_file *files, t_flag *flag)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
//	if (flag->l_f == 1)
//	{
//		stampa_l(files, flag, crt);
//		free_rest(files);
//		return ;
//	}
	while (files->name[i])
	{
		if (flag->hid == 0 && files->name[i][0] == '.')
		{
			free_single(files, i);
			i++;
		}
		else
		{
//			if (flag->rec == 1 && files->prm[i][0] == 'd'
//			&& (ft_strcmp(files->name[i], ".") &&
//			ft_strcmp(files->name[i], "..")))
//			{
//				crt[j] = ft_strdup(files->path[i]);
//				j++;
//			}
			ft_putendl(files->name[i]);
			free_single(files, i);
			i++;
		}
	}
	free_a_lot(files, i);
	free_rest(files);
//	crt[j] = NULL;
}

int		crt_num(t_file *files, t_flag *flag)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while (files->prm[i])
	{
		if (flag->rec == 1 &&
		ft_strcmp(files->name[i], ".") && ft_strcmp(files->name[i], ".."))
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


void	recursion_2(char *crt, t_flag *flag, int len)
{
	char	tmp[len + 1];
	int		i;

	i = 0;
	while (crt[i])
	{
		tmp[i] = crt[i];
		i++;
	}
	tmp[i] = '\0';
	free(crt);
	estrazione(tmp, flag);
}

void	recursion(char **crt, t_flag *flag)
{
	int		i;

	i = 0;
	while (crt[i])
	{
		recursion_2(crt[i], flag, ft_strlen(crt[i]));
		i++;
	}
	free (crt);
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
	j = i;
	while (path[i] != '/')
		i--;
	name = (char*)malloc(sizeof(char) * (j - i));
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
		err = ft_strdup("directory causes a cycle");
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(err, 2);
	free(name);
}

/*void	free_files(t_file *files)
{
	int		i;

	i = 0;
	while (i < 8192)
	{
//		if (files->path[i])
//			ft_bzero(files->path[i], ft_strlen(files->path[i]));
		free(files->path[i]);
//		if (files->name[i])
//			ft_bzero(files->name[i], ft_strlen(files->name[i]));
		free(files->name[i]);
//		if (files->prm[i])
//			ft_bzero(files->prm[i], ft_strlen(files->prm[i]));
		free(files->prm[i]);
//		if (files->us_n[i])
//			ft_bzero(files->us_n[i], ft_strlen(files->us_n[i]));
//		if (files->us_n[i])
		free(files->us_n[i]);
//		if (files->gr_n[i])
//			ft_bzero(files->gr_n[i], ft_strlen(files->gr_n[i]));
//		if (files->gr_n[i])
		free(files->gr_n[i]);
//		if (files->time[i])
//			ft_bzero(files->time[i], ft_strlen(files->time[i]));
		i++;
	}
	if (files->size[0])
	{
		free(files->size);
	}
	if (files->blcks[0])
		free(files->blcks);
	if (files->gr_id[0])
		free(files->gr_id);
	if (files->l_acs[0])
		free(files->l_acs);
	if (files->t_dif[0])
		free(files->t_dif);
	if (files->link[0])
		free(files->link);
	if (files->us_id[0])
		free(files->us_id);
	if (files->perm[0])
		free(files->perm);
	free(files);
}*/

void	free_args(t_flag *flag)
{
	int		i;

	i = 0;
	while (flag->args[i])
	{
		free(flag->args[i]);
		i++;
	}
}

void	free_dirs(t_flag *flag)
{
	int		i;

	i = 0;
	while (flag->dirs[i])
	{
		free(flag->dirs[i]);
		i++;
	}
}

void	free_flag(t_flag *flag)
{
	if (flag->args)
		free_args(flag);
	if (flag->dirs)
		free_dirs(flag);
}

void		free_crt(char **crt, int c_n)
{
	int		i;

	i = 0;
	if (c_n > 1)
	{
		while (crt[i])
		{
			free(crt[i]);
			i++;
		}
	}
	free(crt[i]);
	free(crt);
}

void		estrazione(char *name, t_flag *flag)
{
	DIR		*dirp;
	t_file	*files;
	t_dir	*entr;
	char	*path;
	char	*tmp;
//	char	**crt;
	int		i;

	tmp = ft_strdup(name);
	if ((dirp = opendir(tmp)))
	{
		path = ft_strjoin(tmp, "/");
		free(tmp);
//		entr = NULL;
		files = (t_file*)malloc(sizeof(t_file));
		files = file_init(files);
		while ((entr = readdir(dirp)))
		{
			if (*entr->d_name)
				riempi_files(files, entr, flag, path);
		}
		free(path);
	}
//	else
//	{
//		free_flag(flag);
//		ft_error(path);
//		return ;
//	}
//	crt = (char**)malloc(sizeof(char*) * crt_num(files, flag));
	if (ft_strcmp(path, "."))
		ft_putchar('\n');
	if (ft_strcmp(name, "."))
	{
		ft_putstr(path);
		ft_putendl(":");
	}
//	stampa(files, flag);
	free_a_lot(files, 0);
	free_rest(files);
	closedir(dirp);
//	if (flag->rec == 1 && crt)
//		recursion(crt, flag);
//	else
//		free_crt(crt, crt_num(files, flag));
//	free_flag(flag);
//	free(flag);
//	return (files);
}

int		main(void)
{
	t_flag	flag;

	flag.ord = 0;
	flag.rev = 0;
	flag.rec = 0;
	flag.hid = 0;
	flag.l_f = 0;
	flag.args = NULL;
	flag.dirs = NULL;
	estrazione(".", &flag);
	return (0);
}
