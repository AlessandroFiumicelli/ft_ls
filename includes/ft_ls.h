/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfiumic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:40:12 by alfiumic          #+#    #+#             */
/*   Updated: 2019/10/12 15:16:34 by alfiumic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H
# include <sys/errno.h>
# include <limits.h>
# include <time.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <sys/dir.h>
# include "../libft/includes/libft.h"

typedef struct		s_flag
{
	int		hid;
	int		ord;
	int		rev;
	int		rec;
	int		l_f;
	int		f_n;
	int		d_n;
	char	**args;
	char	**dirs;
}			t_flag;

typedef struct		s_file
{
	char		*d_pth;
	char		**name;
	char		**s_lnk;
	char		**path;
	char		*tmp;
	char		**crt;
	int			d_n;
	int			t_blck;
	int			l_len;
	int			u_len;
	int			g_len;
	int			s_len;
	time_t		time;
}			t_file;

typedef struct dirent	t_dir;
typedef struct stat	t_stat;
typedef struct passwd	t_uid;
typedef struct group	t_gid;

/*
** init_free_info.c
*/
t_file			*free_all(t_file *files, int f_c);
void			nullifica(t_file *files, int f_c);
void			files_init(t_file *files, int f_c);
int			files_count(DIR *dirp, t_flag *flag);

/*
** len_info.c
*/
int			usr_len(t_file *files, uid_t uid);
int			grp_len(t_file *files, gid_t gid);
int			sze_len(t_file *files, off_t size, int chk);
int			lnk_len(t_file *files, nlink_t lnks, int chk);

/*
** sort_info.c
*/
int			lessico(t_file *files, t_flag *flag, int i);
int			tempo(t_file *files, t_flag *flag, int i);
int			da_effettuare(t_file *files, t_flag *flag, int i);
void			scambio(t_file *files, int i);

/*
** get_info.c
*/
void			ordina(t_file *files, t_flag *flag, int i);
void			sizes(t_file *files, t_stat *st);
void			riempi_files_2(t_file *files, t_stat *st, int i);
void			riempi_files(t_file *files, t_flag *flag, char *name);

/*
** start.c
*/
void			estrazione(char *name, t_flag *flag, int i);
void			estrazione_2(DIR *dirp, t_flag *flag, t_file *files, int *f_c);

/*
** recursion.c
*/
void			get_crt(t_file *files);
void			recursion(char **dirs, t_flag *flag);

/*
** print_start.c
*/
void			stampa(t_file *files, t_flag *flag, int i, int rec);

/*
** print_l_start.c
*/
void			type(mode_t mode);
void			stampa_permessi(t_file *files, int i);
void			stampa_lnk(t_file *files, int i);
void			stampa_user(t_file *files, int i);
void			stampa_group(t_file *files, int i);

/*
** print_l_end.c
*/
void			stampa_size(t_file *files, int i);
void			stampa_tempo(t_file *files, int i);
void			ora(char *tmp);
void			anno(char *tmp);
void			stampa_slink(t_file *files, int i);

/*
** utils.c
*/
void			ft_putmax(uintmax_t n);
char			*itoa_usr_grp(uintmax_t n);
void			print_path(char *path);
void			add_slash(t_file *files);
void			get_path(t_file *files, char *name);

/*
** errors.c hgdfuigcshcshalkcdsjhcbjkshifhujkhkb
*/
void			ft_error(char *name);
void			ls_error(char *str, char opt);

/*
** par_init_free.c
*/
void			flag_init(t_flag *flag);
void			args_init(t_flag *flag);
void			free_flag(t_flag *flag);
void			files_init_args(t_file *files, t_flag *flag);
void			free_files_args(t_file *files, t_flag *flag);

/*
** ls_args.c
*/
void			riempi_files_arg(t_file *files, char *path);
void			stampa_files_l(t_flag *flag);
void			stampa_files(t_flag *flag);
void			ls_args(t_flag *flag);

/*
** parser.c
*/
void			flag_parser(t_flag *flag, char *args);
void			parser(t_flag *flag, char **args);

/*
** parser_utils.c
*/
char			*path_of_arg(char *name);
void			args_check(t_flag *flag, char **args);
void			files(t_flag *flag, char **args);
void			dirs(t_flag *flag, char **args);
void			get_args(t_flag *flag, char **args);

/*
** parser_sorter.c
*/
void			sort_args(char **args);
void			reverse_files(t_flag *flag);
void			reverse_dirs(t_flag *flag);

/*
** parser_re_sorter.c
*/
void			re_sort_args(t_flag *flag);
void			re_sort_files(t_flag *flag);
void			re_sort_dirs(t_flag *flag);

#endif
