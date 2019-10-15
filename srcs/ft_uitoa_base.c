/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:30:02 by abourin           #+#    #+#             */
/*   Updated: 2019/10/15 09:40:22 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

char	*ft_uitoa_base(unsigned int n, char *base)
{
	unsigned int	nb;
	int				char_count;
	char			*result;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	nb = n;
	char_count = 0;
	while (nb >= base_len)
	{
		nb = nb / base_len;
		char_count++;
	}
	if (!(result = malloc((char_count + 1) * sizeof(char))))
		return (NULL);
	result[char_count + 1] = '\0';
	while (n >= base_len)
	{
		result[char_count] = base[(n % base_len)];
		n = n / base_len;
		char_count--;
	}
	result[char_count] = base[(n % base_len)];
	return (result);
}
