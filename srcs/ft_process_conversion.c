/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:59:47 by abourin           #+#    #+#             */
/*   Updated: 2019/10/15 11:31:16 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

void	ft_process_conversion(char conv, t_segment *seg, va_list ap)
{
	t_converter		*convert;

	if (!(convert = ft_get_converter(conv)))
		return ;
	if (convert->converter)
		convert->converter(seg, convert, ap);
	free(convert);
}
