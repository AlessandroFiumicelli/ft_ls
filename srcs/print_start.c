#include "../includes/ft_ls.h"

void	stampa(t_file *files, t_flag *flag, int i, int rec)
{
	if (rec != 0)
		print_path(files->d_pth);
	if (flag->l_f == 0)
	{
		while (files->name[++i])
			ft_putendl(files->name[i]);
		return ;
	}
	ft_putstr("total: ");
	ft_putmax(files->t_blck);
	ft_putchar('\n');
	while (files->name[++i])
	{
		stampa_permessi(files, i);
		stampa_lnk(files, i);
		stampa_user(files, i);
		stampa_group(files, i);
		stampa_size(files, i);
		stampa_tempo(files, i);
		ft_putstr(files->name[i]);
		if (files->s_lnk[i])
			stampa_slink(files, i);
		else
			ft_putchar('\n');
	}
}

