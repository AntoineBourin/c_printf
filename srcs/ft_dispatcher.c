/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 08:35:18 by abourin           #+#    #+#             */
/*   Updated: 2019/10/15 15:54:31 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

t_converter		*ft_get_converter(char conv)
{
	t_converter		*convert;

	if (!(convert = malloc(sizeof(t_converter))))
		return (NULL);
	convert->conversion = conv;
	if (conv == 'n')
		convert->converter = &ft_convert_n;
	if (conv == 'c')
		convert->converter = &ft_convert_c;
	if (conv == 's')
		convert->converter = &ft_convert_s;
	if (conv == 'p')
		convert->converter = &ft_convert_p;
	if (conv == 'd' || conv == 'i')
		convert->converter = &ft_convert_d_i;
	if (conv == 'u')
		convert->converter = &ft_convert_u;
	if (conv == 'x' || conv == 'X')
		convert->converter = &ft_convert_x_X;
	if (conv == '%')
	{
		ft_buffer_fillin('%');
		return (NULL);
	}
	return (convert);
}
