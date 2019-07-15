#ifndef FT_LS_H

# define FT_LS_H
# include <limits.h>
# include <time.h>
# include <sys/stat.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/dir.h>
# include "../libft/includes/libft.h"

typedef struct		s_size
{
	int				l_len;
	int				u_len;
	int				g_len;
	int				s_len;
}					t_size;

typedef struct		s_file
{
//	struct s_file	*prev;
	char			**path;
	char			**name;
	mode_t			*perm;
	char			**prm;
	nlink_t			*link;
	uid_t			*us_id;
	char			**us_n;
	gid_t			*gr_id;
	char			**gr_n;
	time_t			*l_acs;
	time_t			*t_dif;
	time_t			a_time;
	char			**time;
	off_t			*size;
	blkcnt_t		*blcks;
	blkcnt_t		t_blck;
	int				l_len;
	int				u_len;
	int				g_len;
	int				s_len;
//	struct s_file	*next;
}					t_file;

/*typedef struct		s_dir
{
//	struct s_dir	*prev;
	char			*path;
	char			**crt;
	struct dirent	*entr;
	struct s_size	*size;
	struct s_file	*prev;
	struct s_file	*cont;
	struct s_file	*next;
//	struct s_dir	*next;
}					t_dir;*/

typedef struct		s_flag
{
	int				hid;
	int				ord;
	int				rev;
	int				rec;
	int				l_f;
	char			**args;
	char			**dirs;
}					t_flag;

typedef struct dirent	t_dir;
typedef struct stat		t_stat;
typedef struct passwd	t_uid;
typedef struct group	t_gid;

void	ls_error(char *str, char *opt);
void	flag_init(t_flag *flag);
void	flag_parser(t_flag *flag, char *args);
void	parser(t_flag *flag, char **args, int argc);

void	free_rest(t_file *files);
void	free_single(t_file *files, int i);
void	free_flag(t_flag *flag);
void	free_files(t_file *files);
void	total_blcks(t_file *files, t_flag *flag, int i);
void	stampa_slink(t_file *files, int i);
void	stampa_l_2(t_file *files, int i);
void	ordina(t_file *files, t_flag *flag, int i);
void	permessi(t_file *files, int i);
void	size_len(t_file *files, int i);
void	l_len_e_s_len(t_file *files, int i);
t_file	*file_init(t_file *files);
void	ft_error(char *path);
void	estrazione(char *name, t_flag *flag);
void	size_init(t_dir *curr);
t_dir	*parte_2(t_dir *curr, t_flag *flag, int i);
void	parte_2_aiuto(t_dir *curr, t_stat *prm, t_flag *flag);
t_dir	*lessico(t_dir *curr, t_file *tmp, t_flag *flag);
int		less_okay(t_file *lk1, t_file *lk2, t_flag *flag);
void	uid_e_gid(t_file *files, int i);
void	dimensioni(t_dir *curr);
t_dir	*dir_init(t_dir *curr, char *name);
#endif
