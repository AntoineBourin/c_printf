/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:48:28 by abourin           #+#    #+#             */
/*   Updated: 2019/10/12 13:23:32 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		size;
	int			i;

	i = 0;
	size = ft_strlen(s1);
	if (!(s2 = malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
