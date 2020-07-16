/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 22:19:07 by hbespin           #+#    #+#             */
/*   Updated: 2020/07/09 00:33:40 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define FLAG_ALL		(1 << 0)
# define FLAG_RECURSION (1 << 1)
# define FLAG_REVERSE	(1 << 2)
# define FLAG_LONG		(1 << 3)
# define FLAG_TIME		(1 << 4)
# define FLAG_S			(1 << 5)
# define FLAG_BIG_S		(1 << 6)
# define FLAG_LA		(1 << 7)
# define FLAG_FC		(1 << 8)
# define FLAG_XATTR		(1 << 9)
# define ILLEGAL_OPTION (-1)
# define PATH_MAX		(1 << 12)
# define XATTR_SIZE		(4096)
# define USAGE "usage: ./ft_ls [-@URSalurst] [file ...]"
# include <unistd.h>
# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <stdlib.h>
# include <stdio.h>
# include <time.h>
# include "libft/libft.h"
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct		s_file
{
	char			*name;
	char			*path;
	char			xattr_lst[XATTR_SIZE];
	ssize_t			xattr_len;
	char			rights[12];
	struct stat		s_stat;
	struct s_file	*sub;
	struct s_file	*next;
}					t_file;

typedef struct		s_matr
{
	int				w;
	int				h;
}					t_matr;

/*
** merge_sort.c contents
*/

void				merge_sort(t_file **head,
		int (*compare)(t_file *, t_file *, int), int flags);

/*
** comparison.c contents
*/

int					compare(t_file *a, t_file *b, int flags);
int					compare_lex(t_file *a, t_file *b);

/*
** list_util.c contents
*/

void				unlink_pointers(t_file **head);
void				link_pointers(t_file **head);
size_t				max_list_name(t_file *head);
void				push_front(t_file **head, t_file *cur);
int					block_len(t_file *head, blkcnt_t *total);

/*
** list_util2.c contents
*/

void				free_node(t_file *node);
void				free_list(t_file *head);
char				*append_to_path(char *path, const char *entry);
void				print_insides(t_file *head, int flags);
void				fill_struct(char *d_name, t_file **object);

/*
** parse_args.c contents
*/

int					parse_args(int ac, char **av, int *flags);

/*
** display.c contents
*/

void				print_list(t_file *head, int flags);

/*
** ft_time.c contents
*/

void				ft_puttime(time_t t);

/*
** prep_display.c contents
*/

void				get_size(t_file *lst, unsigned int *size, blkcnt_t *blocks);
void				ft_padding(char *s, int n);
void				disp_name(t_file *node, int flags, int h);
void				ft_output_alloc(int x, unsigned int len);

/*
** parse_rights.c contents
*/

char				*get_rights_template(struct stat s_stat);
void				parse_rights(mode_t st_mode,
		char *buf, const char *template);

/*
** main.c contents
*/

void				traverse_dirs(t_file **head, int flags, int state);

/*
** dir.c contents
*/

void				open_and_read_dir(t_file *head, int flags);

/*
** prep_display2.c contents
*/

void				print_num(long long value,
						unsigned int *size, unsigned int num);
void				print_user_group(char *name,
						unsigned int *size, unsigned int num);
void				disp_name_l(t_file *list, int flags);
void				check_any_acl(t_file *node);

/*
** comparison2.c contents
*/

int					lm_comparison(t_file *a, t_file *b);
int					la_comparison(t_file *a, t_file *b);
int					fc_comparison(t_file *a, t_file *b);

#endif
