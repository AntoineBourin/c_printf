/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:11:01 by abourin           #+#    #+#             */
/*   Updated: 2019/10/11 14:06:39 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

union				u_segment
{
	int				n;
	char			c;
	void			*ptr;
	char			*str;
}					ut_segment;

typedef struct		s_segment
{
	int				nb_modifiers;
	union u_segment	u_seg;
	int				min_width;
	int				max_width;
	int				is_left_aligned;
	int				is_filled_by_zero;
}					t_segment;

size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
int					ft_get_segment_size(char *str);
char				ft_get_current_conv(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int n);
char				*ft_replace_identifier(char *str, int size_max, va_list ap);
int					ft_printf(const char *str, ...);
char				*ft_itoa_hex(unsigned long int n);
void				ft_process_flags(char *str, t_segment *seg, int max_size);

#endif
