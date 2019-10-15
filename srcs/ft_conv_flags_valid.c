/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_flags_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 08:51:37 by abourin           #+#    #+#             */
/*   Updated: 2019/10/15 15:55:13 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_conversion_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'n'
		|| c == '%')
		return (1);
	return (0);
}

int		ft_is_valid_char(char c)
{
	if (ft_is_conversion_specifier(c))
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '-' || c == '.' || c == '*')
		return (1);
	return (0);
}

int		ft_get_segment_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_is_valid_char(str[i]))
	{
		if (ft_is_conversion_specifier(str[i]))
			return (i + 1);
		i++;
	}
	return (i);
}

char	ft_get_current_conv(char *str)
{
	while (*str)
	{
		if (!ft_is_valid_char(*str))
			return (0);
		if (*str == 'c' || *str == 's' || *str == 'p' || *str == 'd'
			|| *str == 'i' || *str == 'u' || *str == 'x' || *str == 'X'
			|| *str == 'n' || *str == '%')
			return (*str);
		str++;
	}
	return (0);
}
