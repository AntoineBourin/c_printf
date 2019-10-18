/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:06:37 by abourin           #+#    #+#             */
/*   Updated: 2019/10/18 15:39:57 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*ft_free_before_exit(char const *s1, char const *s2)
{
	if (s1)
		free((void *)s1);
	if (s2)
		free((void *)s2);
	return (NULL);
}

static void		ft_get_len(size_t *len, char const *s1, char const *s2)
{
	*len = ft_strlen(s1);
	*len += ft_strlen(s2);
}

char			*ft_strjoin_free(char const *s1, char sep, char const *s2)
{
	char	*result;
	size_t	len;
	int		i;
	int		j;

	j = -1;
	i = 0;
	ft_get_len(&len, s1, s2);
	if (!(result = malloc((len + 2) * sizeof(char))))
		return (ft_free_before_exit(s1, s2));
	while (s1[++j])
	{
		result[i] = s1[j];
		i++;
	}
	result[i++] = sep;
	j = -1;
	while (s2[++j])
	{
		result[i] = s2[j];
		i++;
	}
	result[i] = '\0';
	ft_free_before_exit(s1, s2);
	return (result);
}
