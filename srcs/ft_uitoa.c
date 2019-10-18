/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:34:59 by abourin           #+#    #+#             */
/*   Updated: 2019/10/18 15:42:19 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void			ft_fill_unsigned_result(char *result,
	unsigned int nb, int char_nb)
{
	result[char_nb + 1] = '\0';
	while (nb >= 10)
	{
		result[char_nb] = (nb % 10) + 48;
		nb = nb / 10;
		char_nb--;
	}
	result[char_nb] = (nb % 10) + 48;
}

char				*ft_uitoa(unsigned int n)
{
	int				char_nb;
	char			*result;
	unsigned int	nb;

	nb = n;
	char_nb = 0;
	while (nb >= 10)
	{
		nb = nb / 10;
		char_nb++;
	}
	if (!(result = malloc((char_nb + 1) * sizeof(char))))
		return (NULL);
	ft_fill_unsigned_result(result, n, char_nb);
	return (result);
}
