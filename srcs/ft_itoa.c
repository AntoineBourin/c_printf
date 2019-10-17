/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:34:59 by abourin           #+#    #+#             */
/*   Updated: 2019/10/17 15:54:01 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

static void		ft_fill_result(char *result, int nb, int is_minus, int char_nb)
{
	long long int		n;

	n = nb;
	if (is_minus)
	{
		result[0] = '-';
		n = n * -1;
	}
	result[char_nb + 1] = '\0';
	while (n >= 10)
	{
		result[char_nb] = (n % 10) + 48;
		n = n / 10;
		char_nb--;
	}
	result[char_nb] = (n % 10) + 48;
}

char			*ft_itoa(int n)
{
	int				char_nb;
	long long int	nb;
	int				is_minus;
	char			*result;

	char_nb = 0;
	nb = n;
	if (nb < 0)
	{
		is_minus = 1;
		char_nb++;
		nb = nb * -1;
	}
	else
		is_minus = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		char_nb++;
	}
	if (!(result = malloc((char_nb + 1) * sizeof(char))))
		return (NULL);
	ft_fill_result(result, n, is_minus, char_nb);
	return (result);
}
