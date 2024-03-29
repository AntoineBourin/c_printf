/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_identifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:54:18 by abourin           #+#    #+#             */
/*   Updated: 2019/10/22 10:53:55 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_get_int_char_size(int n)
{
	int			count;
	long int	nb;

	nb = n;
	count = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int		ft_rewrite_asterix(char **result, int to_allow, long int n, int *j)
{
	int		x;
	int		is_min;

	x = to_allow;
	is_min = 0;
	if (n < 0)
	{
		n = n * -1;
		is_min = 1;
	}
	while (n >= 10)
	{
		(*result)[*j + x - 1] = (n % 10) + 48;
		n = n / 10;
		x--;
	}
	(*result)[*j + x - 1] = (n % 10) + 48;
	if (is_min)
	{
		x--;
		(*result)[*j + x - 1] = '-';
	}
	*j = *j + to_allow;
	return (1);
}

char	*ft_rewrite_str_value(char *str, long int n, int to_allow)
{
	char	*result;
	int		i;
	int		j;
	int		replaced;

	replaced = 0;
	i = 0;
	j = 0;
	if (!(result = malloc((ft_strlen(str) + to_allow + 1) * sizeof(char))))
		return (NULL);
	while (str[i])
	{
		if (str[i] == '*' && !replaced)
			replaced = ft_rewrite_asterix(&result, to_allow, n, &j);
		else
		{
			result[j] = str[i];
			j++;
		}
		i++;
	}
	result[j] = '\0';
	free(str);
	return (result);
}

char	*ft_replace_identifier(char *str, va_list ap)
{
	int						i;
	int						n;
	int						to_allow;
	char					*with_identifiers;

	if (!(with_identifiers = ft_strdup(str)))
		return (NULL);
	i = 0;
	while (with_identifiers[i] && ft_is_valid_char(with_identifiers[i]))
	{
		if (ft_is_conversion_specifier(with_identifiers[i]))
			return (with_identifiers);
		if (with_identifiers[i] == '*')
		{
			i = 0;
			n = va_arg(ap, int);
			to_allow = ft_get_int_char_size(n);
			if (!(with_identifiers =
			ft_rewrite_str_value(with_identifiers, n, to_allow)))
				return (NULL);
		}
		i++;
	}
	return (with_identifiers);
}
