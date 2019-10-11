/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_identifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:54:18 by abourin           #+#    #+#             */
/*   Updated: 2019/10/11 15:12:06 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_get_int_char_size(unsigned long int n)
{
	int		count;

	count = 1;
	while (n > 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_rewrite_str_value(char *str, unsigned long int n, int to_allow)
{
	char	*result;
	int		i;
	int		j;
	int		x;
	int		replaced;

	replaced = 0;
	i = 0;
	j = 0;
	if (!(result = malloc((ft_strlen(str) + to_allow + 1) * sizeof(char))))
		return (NULL);
	while (str[i])
	{
		if (str[i] == '*' && !replaced)
		{
			x = to_allow;
			while (n > 10)
			{
				result[j + x - 1] = (n % 10) + 48;
				n = n / 10;
				x--;
			}
			result[j + x - 1] = (n % 10) + 48;
			replaced = 1;
			j = j + to_allow;
		}
		else
		{
			result[j] = str[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	return (result);
}

char	*ft_replace_identifier(char *str, int size_max, va_list ap)
{
	int						i;
	unsigned long int		n;
	int						to_allow;

	i = 0;
	while (str[i] && i < size_max)
	{
		if (str[i] == '*')
		{
			i = 0;
			n = va_arg(ap, long int);
			to_allow = ft_get_int_char_size(n);
			str = ft_rewrite_str_value(str, n, to_allow);
		}
		i++;
	}
	return (str);
}
