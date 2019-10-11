/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:12:08 by abourin           #+#    #+#             */
/*   Updated: 2019/10/11 15:42:33 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*void			ft_print_variable_adress(void *ptr)
{
	uintptr_t	k;
	char		*result;

	k = (uintptr_t)ptr;
	result = ft_itoa_hex(k);
	ft_putstr("0x");
	ft_putstr(result);
}

static int		ft_get_params(int i, char *str, va_list ap)
{
	char	c;
	char	*s;
	int		n;
	void	*ptr;

	while (str[i])
	{
		switch (str[i])
		{
			case 'c':
				c = va_arg(ap, int);
				ft_putchar(c);
				break ;
			case 's':
				s = va_arg(ap, char *);
				ft_putstr(s);
				break ;
			case 'p':
				ptr = va_arg(ap, void *);
				ft_print_variable_adress(ptr);
				break ;
			case 'd':
				n = va_arg(ap, int);
				ft_putnbr(n);
				break ;
			case ' ':
				break ;
			case '%':
				break ;
			default:
				ft_putchar(str[i]);
				return (i);
		}
		i++;
	}
	return (i);
}*/

t_segment	*ft_init_segment(void)
{
	t_segment	*seg;

	if (!(seg = malloc(1 * sizeof(t_segment))))
		return (0);
	seg->nb_modifiers = 0;
	seg->min_width = 0;
	seg->max_width = -1;
	seg->is_left_aligned = 0;
	seg->is_filled_by_zero = 0;
	return (seg);
}

int			ft_process_segment(char *str, va_list ap)
{
	t_segment	*seg;
	char		conv;
	int			size;
	int			r_size;

	size = 0;
	r_size = 0;
	seg = ft_init_segment();
	str++;
	while (*str == ' ')
	{
		r_size++;
		str++;
	}
	size = ft_get_segment_size(str);
	str = ft_replace_identifier(str, size - r_size, ap);
	printf("str after replace %s\n", str);
	ft_process_flags(str, seg, size - r_size);
	conv = ft_get_current_conv(str);
	printf("left align : %d\nis filled : %d\nmin_width : %d\nmax_width : %d\n", seg->is_left_aligned, seg->is_filled_by_zero, seg->min_width, seg->max_width);
	//seg->u_seg.ptr = va_arg(ap, void *);
	//ft_putnbr(seg->u_seg.n);
	free(str);
	free(seg);
	return (size + r_size);
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	char		*cs;
	int			i;

	cs = (char *)str;
	i = 0;
	va_start(ap, str);
	while (cs[i])
	{
		if (cs[i] == '%')
			i += ft_process_segment(cs + i, ap);
		else
			ft_putchar(cs[i]);
		i++;
	}
	va_end(ap);
	return (0);
}

int	main(void)
{
	void			*t;

	t = malloc(sizeof(int));
	ft_printf("%-0*.*s\n", 50, 5, "Hello");
	printf("%-*d\n", 5, 50);
	printf("\n\nTEST %25.2s\n", "Hello world");
//	printf("%-30s\n", "Hello world");
//	printf("%30s\n", "Hello world");
//	printf("%03d\n", 0);
//	printf("%04d\n", -10);
//	printf("%1.s\n", "Hey");
}
