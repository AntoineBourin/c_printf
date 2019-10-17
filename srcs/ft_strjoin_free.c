/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:37:31 by abourin           #+#    #+#             */
/*   Updated: 2019/10/16 15:05:26 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

static void		ft_free_before_exit(char const *s1, char const *s2)
{
	free((void *)s1);
	free((void *)s2);
}

char			*ft_strjoin_free(char const *s1, char sep, char const *s2)
{
	char	*result;
	size_t	len;
	int		i;
	int		j;

	j = -1;
	i = 0;
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	if (!(result = malloc((len + 2) * sizeof(char))))
	{
		ft_free_before_exit(s1, s2);
		return (NULL);
	}
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
