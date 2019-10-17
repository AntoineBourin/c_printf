/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:07:11 by abourin           #+#    #+#             */
/*   Updated: 2019/10/17 17:27:26 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

char	*ft_get_after_s(intmax_t after, int precision, int zero_to_add)
{
	char	*result;
	int		prec;

	prec = precision;
	if (!(result = malloc(sizeof(char) * prec + 2)))
		return (NULL);
	result[prec + 1] = '\0';
	while (zero_to_add--)
	{
		result[precision] = '0';
		precision--;
	}
	while (after >= 10)
	{
		result[precision] = (after % 10) + 48;
		after = after / 10;
		precision--;
	}
	result[precision] = after + 48;
	while ((precision - 1) >= 0)
	{
		result[precision - 1] = '0';
		precision--;
	}
	return (result);
}

char	*ft_get_after_dot(long double after, int precision)
{
	int					prec;
	uintmax_t			i;
	uintmax_t			index;
	uintmax_t			multiplier;

	prec = precision;
	multiplier = 1;
	index = 0;
	while (precision && index < 18)
	{
		multiplier *= 10;
		precision--;
		index++;
	}
	i = after > 0 ? (intmax_t)(after * multiplier + 0.5)
		: (intmax_t)(after * multiplier - 0.5) * -1;
	return (ft_get_after_s(i, prec - 1, precision));
}

void	ft_write_cbefore(char **cbefore, int len, intmax_t n)
{
	while (n >= 10)
	{
		(*cbefore)[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	(*cbefore)[len - 1] = (n % 10) + '0';
}

char	*ft_get_real(intmax_t n)
{
	char		*cbefore;
	intmax_t	len;
	intmax_t	nb;
	intmax_t	total_len;

	nb = n;
	len = 1;
	if (nb < 0)
		nb = nb * -1;
	while (nb >= 10)
	{
		len++;
		nb /= 10;
	}
	total_len = len;
	if (!(cbefore = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	cbefore[total_len] = '\0';
	if (n < 0)
		n *= -1;
	ft_write_cbefore(&cbefore, len, n);
	return (cbefore);
}

char	*ft_ftoa(double f, int precision)
{
	long double		after;
	intmax_t		n;
	char			*cbefore;
	char			*cafter;

	n = (long double)f;
	after = f - n;
	if (precision != 0)
	{
		if (!(cafter = ft_get_after_dot(after, precision)))
			return (NULL);
		if (!(cbefore = ft_get_real(n)))
			return (NULL);
		return (ft_strjoin_free(cbefore, '.', cafter));
	}
	else
	{
		if (n % 2 != 0)
			n = (long double)f >= 0 ? (intmax_t)(f + 0.50) : (intmax_t)(f - 0.50);
		if (!(cbefore = ft_get_real(n)))
			return (NULL);
		return (cbefore);
	}
}
