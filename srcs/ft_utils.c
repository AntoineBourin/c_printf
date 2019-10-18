/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:57:00 by abourin           #+#    #+#             */
/*   Updated: 2019/10/18 15:39:00 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_fill_blanks(char *result, t_segment *seg, int is_zero)
{
	int i;

	i = 0;
	if (is_zero && seg->is_left_aligned)
		is_zero = 0;
	if (seg->min_width > (int)ft_strlen(result)
		|| (seg->min_width > seg->max_width && seg->max_width != -1))
	{
		while (seg->min_width > ((int)ft_strlen(result) + i)
		|| (seg->min_width > (seg->max_width + i) && seg->max_width != -1))
		{
			ft_buffer_fillin(is_zero ? '0' : ' ');
			i++;
		}
	}
}

intmax_t	ft_get_round_number(double f, long double after)
{
	intmax_t	n;

	n = (long double)f;
	if (n % 2 == 0 && after > 0.50)
		n = (long double)f >= 0 ? (intmax_t)(f + 0.50) : (intmax_t)(f - 0.50);
	else if (n % 2 == 0 && after < -0.50)
		n = (long double)f >= 0 ? (intmax_t)(f + 0.50) : (intmax_t)(f - 0.50);
	else if (n % 2 != 0)
		n = (long double)f >= 0 ? (intmax_t)(f + 0.50) : (intmax_t)(f - 0.50);
	else
		n = (long double)f;
	return (n);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putnbr(int n)
{
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb < 10)
	{
		ft_putchar('0' + nb);
	}
}
