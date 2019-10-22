/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:11:01 by abourin           #+#    #+#             */
/*   Updated: 2019/10/22 10:22:01 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BUFFER_SIZE 4096
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <math.h>

typedef struct		s_segment
{
	int				index;
	int				nb_modifiers;
	int				min_width;
	int				max_width;
	int				is_left_aligned;
	int				is_filled_by_zero;
	int				is_spaced;
}					t_segment;

typedef struct		s_converter
{
	char			conversion;
	void			(*converter)(t_segment *, struct s_converter *, va_list ap);
}					t_converter;

static char			g_buff[BUFFER_SIZE];

int					ft_is_conversion_specifier(char c);
intmax_t			ft_get_round_number(double f, long double after);
char				*ft_strdup(char const *s1);
char				*ft_strjoin_free(char const *s1, char sep, char const *s2);
char				*ft_get_real(intmax_t n);
char				*ft_ftoa(double f, int precision);
char				*ft_uitoa_base(unsigned int n, char *base);
char				*ft_uitoa(unsigned int n);
char				*ft_itoa(int n);
void				ft_process_max_width(char *str, t_segment *seg);
void				ft_fill_int_blanks(char *str, t_segment *seg);
void				ft_fill_blanks(char *result, t_segment *seg, int is_zero);
void				ft_convert_percent(t_segment *seg,
							t_converter *convert, va_list ap);
void				ft_convert_n(t_segment *seg,
							t_converter *convert, va_list ap);
void				ft_convert_f(t_segment *seg,
							t_converter *convert, va_list ap);
void				ft_convert_x(t_segment *seg,
							t_converter *convert, va_list ap);
void				ft_convert_u(t_segment *seg,
							t_converter *convert, va_list ap);
void				ft_convert_d_i(t_segment *seg,
							t_converter *convert, va_list ap);
void				ft_convert_s(t_segment *seg,
							t_converter *convert, va_list ap);
void				ft_convert_c(t_segment *seg,
							t_converter *convert, va_list ap);
void				ft_convert_p(t_segment *seg,
							t_converter *convert, va_list ap);
t_converter			*ft_get_converter(char conv);
void				ft_process_conversion(char conv,
							t_segment *seg, va_list ap);
void				ft_reset_buffer(void);
int					ft_fillout_buffer(int reset, int add_one);
void				ft_buffer_str_fillin(char *str);
void				ft_buffer_fillin(char c);
int					ft_is_valid_char(char c);
size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
int					ft_get_segment_size(char *str);
char				ft_get_current_conv(char *str);
void				ft_putchar(char c);
void				ft_putnbr(int n);
char				*ft_replace_identifier(char *str, va_list ap);
int					ft_printf(const char *str, ...);
char				*ft_itoa_hex(unsigned long int n);
void				ft_process_flags(char *str, t_segment *seg, int max_size);

#endif
