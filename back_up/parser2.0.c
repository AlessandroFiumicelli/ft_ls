#include "../includes/ft_ls.h"
#include <stdio.h>

void	ls_error(char *str, char *opt)
{
	if (!(ft_strcmp(str, "ILLEGAL")))
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putendl_fd(opt, 2);
		ft_putendl_fd("usage: ls [-Ralrt] [file ...]", 2);
		exit (1);
	}
}

void	flag_init(t_flag *flag)
{
	flag->hid = 0;
	flag->ord = 0;
	flag->rev = 0;
	flag->rec = 0;
	flag->l_f = 0;
	flag->args = NULL;
	flag->dirs = NULL;
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

int		valid_path(char *arg)
{
	if (arg[0] == '/' || (arg[0] == '.' &&
	(!arg[1] || arg[1] == '/')))
		return (1);
	return (0);
}

void	get_dir(t_flag *flag, char **args, int *valid, int n_d)
{
	int		j;
	int		i;
	char	*path;
	t_stat	st;

	flag->dirs = malloc(sizeof(char**) * (n_d + 1));
	i = 0;
	j = 0;
	while (args[i])
	{
		if (valid[i] == 1)
		{
			path = valid_path(args[i]) ? ft_strdup(args[i]) :
			ft_strjoin("./", args[i]);
			lstat(path, &st);
			if (S_ISDIR(st.st_mode))
			{
				flag->dirs[j] = ft_strdup(path);
				j++;
			}
		}
		i++;
	}
	flag->dirs[j] = NULL;
}

void	get_file(t_flag *flag, char **args, int *valid, int n_f)
{
	int		i;
	int		j;
	char	*path;
	t_stat	st;

	flag->args = malloc(sizeof(char**) * (n_f + 1));
	i = 0;
	j = 0;
	while (args[i])
	{
		if (valid[i] == 1)
		{
			path = valid_path(args[i]) ? ft_strdup(args[i]) :
			ft_strjoin("./", args[i]);
			lstat(path, &st);
			if (!S_ISDIR(st.st_mode))
			{
				flag->args[j] = ft_strdup(path);
				j++;
			}
		}
		i++;
	}
	flag->args[j] = NULL;
}

void	reverse_dirs(t_flag *flag)
{
	int		i;
	int		j;
	void	*tmp;

	i = 0;
	while (flag->dirs[i + 1])
		i++;
	if (i > 0)
	{
		j = 0;
		while (j < i)
		{
			tmp = flag->dirs[i];
			flag->dirs[i] = flag->dirs[j];
			flag->dirs[j] = tmp;
			j++;
			i--;
		}
	}
}

void	reverse(t_flag *flag)
{
	int		i;
	int		j;
	void	*tmp;

	if (flag->args)
	{
		i = 0;
		while (flag->args[i + 1])
			i++;
		if (i > 0)
		{
			j = 0;
			while (j < i)
			{
				tmp = flag->args[i];
				flag->args[i] = flag->args[j];
				flag->args[j] = tmp;
				j++;
				i--;
			}
		}
	}
	if (flag->dirs)
		reverse_dirs(flag);
}

void	time_dirs(t_flag *flag)
{
	t_stat	st2;
	t_stat	st;
	char	*tmp;
	int		i;

	i = 0;
	while (flag->dirs[i + 1])
	{
		lstat(flag->dirs[i], &st);
		lstat(flag->dirs[i + 1], &st2);
		if (st.st_mtimespec.tv_sec < st2.st_mtimespec.tv_sec)
		{
			tmp = flag->dirs[i];
			flag->dirs[i] = flag->dirs[i + 1];
			flag->dirs[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	by_tyme(t_flag *flag)
{
	t_stat	st2;
	t_stat	st;
	char	*tmp;
	int		i;

	i = 0;
	while (flag->args[i + 1])
	{
		lstat(flag->args[i], &st);
		lstat(flag->args[i + 1], &st2);
		if (st.st_mtimespec.tv_sec < st2.st_mtimespec.tv_sec)
		{
			tmp = flag->args[i];
			flag->args[i] = flag->args[i + 1];
			flag->args[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	if (flag->dirs)
		time_dirs(flag);
}

void	re_sort(t_flag *flag)
{
	int		i;

	if (flag->ord == 1)
		by_tyme(flag);
	if (flag->rev == 1)
		reverse(flag);
}

void	get_args_2(t_flag *flag, char **args, int *valid)
{
	int		i;
	int		n_f;
	int		n_d;
	char	*path;
	t_stat	st;

	i = 0;
	n_f = 0;
	n_d = 0;
	while (args[i])
	{
		if (valid[i] == 1)
		{
			path = valid_path(args[i]) ? ft_strdup(args[i]) :
			ft_strjoin("./", args[i]);
			lstat(path, &st);
			S_ISDIR(st.st_mode) ? n_d++ : n_f++;
		}
		i++;
	}
	if (n_d > 0)
		get_dir(flag, args, valid, n_d);
	else
		flag->dirs = NULL;
	if (n_f > 0)
		get_file(flag, args, valid, n_f);
	re_sort(flag);
}

void	sort(char **args, t_flag *flag)
{
	int		i;
	void	*tmp;

	i = 0;
	while (args[i + 1])
	{
		if (ft_strcmp(args[i], args[i + 1]) > 0)
		{
			tmp = args[i + 1];
			args[i + 1] = args[i];
			args[i] = tmp;
			i = -1;
		}
		i++;
	}
}

void	get_args(t_flag *flag, char **args, int n_ar)
{
	t_stat	st;
	int		i;
	int		valid[n_ar];
	char	*path;
	int		err;

	sort(args, flag);
	i = 0;
	while (args[i])
	{
		path = valid_path(args[i]) ? ft_strdup(args[i]) :
		ft_strjoin("./", args[i]);
		err = lstat(path, &st);
		valid[i] = err != -1 ? 1 : 0;
		if (err == -1)
			ft_error(args[i]);
		i++;
		free (path);
	}
	get_args_2(flag, args, valid);
}

t_file	*arg_file_init(t_file *files, int cnt)
{
	files->name = malloc(sizeof(char**) * (cnt + 1));
	files->perm = malloc(sizeof(mode_t*) * (cnt + 1));
	files->prm = malloc(sizeof(char**) * (cnt + 1));
	files->link = malloc(sizeof(nlink_t*) * (cnt + 1));
	files->us_id = malloc(sizeof(uid_t*) * (cnt + 1));
	files->us_n = malloc(sizeof(char**) * (cnt + 1));
	files->gr_id = malloc(sizeof(gid_t*) * (cnt + 1));
	files->gr_n = malloc(sizeof(char**) * (cnt + 1));
	files->l_acs = malloc(sizeof(time_t*) * (cnt + 1));
	files->t_dif = malloc(sizeof(time_t*) * (cnt + 1));
	files->a_time = time(&files->a_time);
	files->time = malloc(sizeof(char**) * (cnt + 1));
	files->size = malloc(sizeof(off_t*) * (cnt + 1));
	files->l_len = 1;
	files->u_len = 0;
	files->g_len = 0;
	files->s_len = 1;
	return (files);
}

void	get_size_arg(t_file *files, int i)
{
	int		chk;
	int		chk2;

	l_len_e_s_len(files, i);
	chk = ft_strlen(files->us_n[i]);
	chk2 = ft_strlen(files->gr_n[i]);
	chk > files->u_len ? files->u_len = chk : files->u_len;
	chk2 > files->g_len ? files->g_len = chk2 : files->g_len;
	size_len(files, i);
}

/*void	ft_time(t_file *files, char *tmp, int i)
{
	int		len;
	int		j;

	len = ft_strlen(tmp + 1);
	files->time[i] = malloc(sizeof(char*) * len);
	j = 0;
	while (tmp[j])
	{
		files->time[i][j] = tmp[j];
		j++;
	}
	files->time[i][j] = '\0';
}*/

char	*uid(uid_t uid)
{
	t_uid	*us;

	us = getpwuid(uid);
	if (us)
		return (ft_strdup(us->pw_name));
	return (NULL);
}

char	*gid(gid_t gid)
{
	t_gid	*gr;

	gr = getgrgid(gid);
	if (gr)
		return (ft_strdup(gr->gr_name));
	return (NULL);
}

t_file	*riempi_args(t_file *files, t_flag *flag, int cnt)
{
	char	*tmp;
	t_stat	*st;
	int		i;

	st = malloc(sizeof(t_stat));
	i = 0;
	while (flag->args[i])
	{
		lstat(flag->args[i], st);
		files->name[i] = ft_strdup(flag->args[i]);
		files->perm[i] = st->st_mode;
		permessi(files, i);
		files->link[i] = st->st_nlink;
		files->us_id[i] = st->st_uid;
		files->gr_id[i] = st->st_gid;
		files->l_acs[i] = st->st_mtimespec.tv_sec;
		files->t_dif[i] = files->a_time - files->l_acs[i];
		tmp = ctime(&st->st_mtimespec.tv_sec);
		files->time[i] = ft_strdup(tmp);
		files->size[i] = st->st_size;
		files->us_n[i] = uid(files->us_id[i]);
		files->gr_n[i] = gid(files->gr_id[i]);
		get_size_arg(files, i);
		i++;
	}
	files->name[i] = NULL;
	free (st);
	return (files);
}

void	stampa_args_l(t_file *files)
{
	int		i;

	i = 0;
	while (files->name[i])
	{
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

void	files(t_flag *flag)
{
	int		cnt;
	int		i;
	t_file	*files;

	cnt = 0;
	i = -1;
	while (flag->args[++i])
		cnt++;
	files = malloc(sizeof(t_file));
	files = arg_file_init(files, cnt);
	files = riempi_args(files, flag, cnt);
	stampa_args_l(files);
//	free_files(files);
}

void	ls_args(t_flag *flag)
{
	int		i;

	if (flag->args && !flag->l_f)
	{
		i = 0;
		while (flag->args[i])
		{
			ft_putendl(flag->args[i]);
			i++;
		}
	}
	else if (flag->args)
		files(flag);
	if (flag->dirs)
	{
		i = -1;
		while (flag->dirs[++i])
			estrazione(flag->dirs[i], flag);
	}
	free_flag(flag);
	exit (1);
}

void	parser(t_flag *flag, char **args, int argc)
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
	if (args[i])
		get_args(flag, &args[i], (argc - i));
	if (flag->args || flag->dirs)
		ls_args(flag);
}

/*int		sort_args(t_flag *flag, int i)
{
	void	*tmp;

	if (flag->args[i] && flag->args[i + 1]
	&& ft_strcmp(flag->args[i], flag->args[i + 1]) <= 0)
		return (0);
	tmp = flag->args[i + 1];
	flag->args[i + 1] = flag->args[i];
	flag->args[i] = tmp;
	return (1);
}

void	rm_args(t_flag *flag, int i)
{
	while (flag->args[i + 1])
	{
		flag->args[i] = flag->args[i + 1];
		i++;
	}
	flag->args[i] = NULL;
}

void	get_size_arg(t_file *files, int i)
{
	int		chk;
	int		chk2;

	l_len_e_s_len(files, i);
	chk = ft_strlen(files->us_n[i]);
	chk2 = ft_strlen(files->gr_n[i]);
	chk > files->u_len ? files->u_len = chk : files->u_len;
	chk2 > files->g_len ? files->g_len = chk : files->g_len;
	size_len(files, i);
}

void	get_stat(t_file *files, char *name, t_stat *st, t_flag *flag)
{
	int		i;
	char	*tmp;

	i = 0;
	while (files->name[i])
		i++;
	files->name[i] = ft_strdup(name);
	files->perm[i] = st->st_mode;
	files->prm[i] = permessi(files, i);
	files->link[i] = st->st_nlink;
	files->us_id[i] = st->st_uid;
	files->gr_id[i] = st->st_gid;
	files->l_acs[i] = st->st_mtimespec.tv_sec;
	files->t_dif[i] = files->a_time - files->l_acs[i];
	tmp = ctime(&files->l_acs[i]);
	files->time[i] = ft_strdup(tmp);
	files->size[i] = st->st_size;
	files->blcks[i] = st->st_blocks;
	uid_e_gid(files, i);
	if (files->us_n[i] && files->gr_n[i])
		get_size_arg(files, i);
	ordina(files, flag, i);
}

int		there(char *name, t_file *files)
{
	int		i;

	i = 0;
	while (files->name[i])
	{
		if (!ft_strcmp(name, files->name[i]))
			return (1);
		i++;
	}
	return (0);
}

char	**create_crt(t_file *files, t_flag *flag, int c_cnt)
{
	char	**crt;
	int		i;
	int		j;

	crt = malloc(sizeof(char**) * (c_cnt + 1));
	i = 0;
	j = 0;
	while (flag->args[i])
	{
		if (there(flag->args[i], files))
			i++;
		else
		{
			if (flag->args[i][ft_strlen(flag->args[i]) - 1] == '/' &&
			ft_strcmp(flag->args[i], "/"))
				flag->args[i][ft_strlen(flag->args[i]) - 1] = '\0';
			crt[j] = ft_strdup(flag->args[i]);
			j++;
			i++;
		}
	}
	return (crt);
}

void	stampa_args_l(t_file *files)
{
	int		i;

	i = 0;
	while (files->name[i])
	{
		ft_putstr(files->prm[i]);
		stampa_l_2(files, i);
		ft_putstr(files->name[i]);
		if (files->prm[i][0] == 'l')
			stampa_slink(files, i);
		else
			ft_putchar('\n');
	}
}

void	stampa_args(t_file *files, t_flag *flag)
{
	int		i;

	i = 0;
	if (flag->l_f == 0)
	{
		while (files->name[i])
		{
			ft_putendl(files->name[i]);
			i++;
		}
	}
	else
		stampa_args_l(files);
}

char	*get_path(char *name)
{
	int		i;
	char	*tmp;

	if (name[0] == '/')
		return (name);
	else if (name[0] == '.' && name[1] == '/')
		return (name);
	tmp = malloc(sizeof(char*) * 100);
	ft_bzero(tmp, ft_strlen(name) + 3);
	tmp[0] = '.';
	tmp[1] = '/';
	return (ft_strjoin(tmp, name));
}

void	ls_args_2(t_flag *flag)
{
	t_file	*files;
	t_stat	*prm;
	char	**crt;
	int		c_cnt;
	int		i;

	files = malloc(sizeof(t_file*));
	files = file_init(files);
//	prm = malloc(sizeof(t_stat));
	i = 0;
	c_cnt = 0;
	while (flag->args[i])
	{
		files->path[i] = get_path(flag->args[i]);
		if (lstat(files->path[i], prm) >= 0)
		{
			ft_putendl("QUI");
			if (S_ISDIR(prm->st_mode))
				c_cnt++;
			else
				get_stat(files, flag->args[i], prm, flag);
		}
		else
			ft_error(flag->args[i]);
		i++;
	}
	stampa_args(files, flag);
//	crt = create_crt(files, flag, c_cnt);
}

void	ls_args(t_flag *flag)
{
	t_stat	*st;
	int		i;
	char	*path;

	i = 0;
	while (flag->args[i + 1])
	{
		if (sort_args(flag, i) == 1)
			i = 0;
		else
			i++;
	}
	st = malloc(sizeof(t_stat*));
	i = 0;
	while (flag->args[i])
	{
		path = get_path(flag->args[i]);
		ft_putendl(path);
		if (lstat(path, st) == -1)
		{
			ft_putendl("QUI");
			ft_error(flag->args[i]);
			rm_args(flag, i);
		}
		free (path);
		i++;
	}
	free (st);
	ls_args_2(flag);
}*/

int		main(int argc, char **argv)
{
	t_flag	*flag;

	flag = (t_flag*)malloc(sizeof(t_flag));
	flag_init(flag);
	if (argc > 1)
		parser(flag, argv, argc);
	estrazione(".", flag);
	return (1);
}
