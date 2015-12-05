/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 01:20:54 by zcarde            #+#    #+#             */
/*   Updated: 2015/02/07 13:38:19 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_pile
{
	int				nb;
	struct s_pile	*next;
	struct s_pile	*previous;
}					t_pile;

typedef struct		s_opt
{
	int				v;
	int				c;
	int				b;
	int				l;
	int				r;
	int				pusha;
	int				pushb;
	int				swap;
	int				rrotate;
	int				rotate;
	int				end;
}					t_opt;

long				ft_atoi(const char *str);
void				ft_putnbr(int nb);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *str);
int					check_options(char c, t_opt *options);
void				init_options(t_opt *options);
int					go_option(char *str, t_opt *options);
int					fill_options(int ac, char **av, t_opt *options);
void				exit_error(int error);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
void				swap(t_pile **pile, int i, int space);
void				push(t_pile **first, t_pile **second, int i, int space);
void				rotate(t_pile **pile, int i, int space);
void				reverse_rotate(t_pile **pile, int i, int space);
t_pile				*push_front(t_pile *a, t_pile *to_add);
t_pile				*push_back(t_pile *a, t_pile *to_add);
t_pile				*new_int(char *nb);
t_pile				*new_int_cpy(t_pile *src);
int					get_nb_elem(t_pile *list);
int					is_ordereda(t_pile *a, int i);
int					check_error(char *str, t_pile *a);
void				exit_error(int error);
int					make_piles(int ints[2], char **av, t_pile **a, t_opt opts);
void				color(int low, int n_pile, t_pile *temp, t_opt opts);
void				print_pile(t_pile *pile, int n_pile, int low, t_opt opts);
void				print_piles(t_pile *a, t_pile *b, t_opt opts, int low);
t_pile				*remove_first(t_pile *src);
t_pile				*remove_last(t_pile *src);
int					get_lower(t_pile *a);
int					get_higher(t_pile *a);
int					algo(t_pile **a2, t_pile **b2, t_opt *opts, int first);
int					algo_reverse
						(t_pile **a2, t_pile **b2, t_opt *opts, int first);
void				putstr_nbr(const char *str, int nb, int space);
void				print_opts(int nb_instr, t_opt opts);

#endif
