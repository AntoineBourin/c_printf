/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abourin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 10:12:08 by abourin           #+#    #+#             */
/*   Updated: 2019/10/17 13:45:02 by abourin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/printf.h"

t_segment	*ft_init_segment(int index)
{
	t_segment	*seg;

	if (!(seg = malloc(1 * sizeof(t_segment))))
		return (0);
	seg->nb_modifiers = 0;
	seg->min_width = 0;
	seg->max_width = -1;
	seg->is_spaced = 0;
	seg->is_left_aligned = 0;
	seg->is_filled_by_zero = 0;
	seg->index = index;
	return (seg);
}

int			ft_process_segment(char *str, va_list ap, int index)
{
	t_segment	*seg;
	char		conv;
	int			size;

	size = 0;
	if (!(seg = ft_init_segment(index)))
		return (-1);
	str++;
	size = ft_get_segment_size(str);
	if (size <= 0)
		return (-1);
	if (!(str = ft_replace_identifier(str, ap)))
		return (-1);
	ft_process_flags(str, seg, size);
	if (!(conv = ft_get_current_conv(str)))
		return (-1);
	if (seg->is_spaced && conv != 's' && conv != '%')
		ft_buffer_fillin(' ');
	ft_process_conversion(conv, seg, ap);
	//printf("left align : %d\nis filled : %d\nmin_width : %d\nmax_width : %d\n", seg->is_left_aligned, seg->is_filled_by_zero, seg->min_width, seg->max_width);
	free(seg);
	free(str);
	return (size);
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	char		*cs;
	int			i;
	int			seg_size;

	cs = (char *)str;
	i = 0;
	va_start(ap, str);
	while (cs[i])
	{
		if (cs[i] == '%')
		{
			seg_size = ft_process_segment(cs + i, ap, i);
			if (seg_size > 0)
				i += seg_size;
		}
		else
			ft_buffer_fillin(cs[i]);
		i++;
	}
	va_end(ap);
	return (ft_fillout_buffer(1, 0));
}

int	main(void)
{
	int	t;

	t = 50;
	ft_printf("%4y\n");
	//ft_printf("%030c %n\n", '\0', &t);
	//ft_printf("%d\n", t);
	//printf("%030c %n\n", '\0', &t);
	//ft_printf("%d\n", t);
	//ft_printf("%lls\n", 1.554879784);
	//printf("%rs\n", 0);
	//ft_printf("%*p | %*d | %-*c\n", 6, NULL, 0, 100, 4, 65);
	//printf("%*p | %*d | %-*c\n", 6, NULL, 0, 100, 4, 65);
	//ft_printf("%-20.0d\n", -0);
	//printf("%-20.0d\n", -0);
	//printf("%f\n", -1.0 / 0.0);
	//ft_printf("%f\n", -1.0 / 0.0);
	//ft_printf("hello ca%----4c\n", '\0', '\n', (char)564, 0);
	//printf("hello ca%-----4c\n", '\0', '\n', (char)564, 0);
	//printf("%12%\n");
	//ft_printf("%12%\n");
	//printf("%-4%\n");
	//ft_printf("%-4%\n");
	//printf("% 017%\n");
	//ft_printf("% 017%\n");
	//printf("%.0%\n");
	//ft_printf("%.0%\n");
	//printf("%-0*.*f\n", 20, 19, 5.500946755555555555555555555);
	//ft_printf("%-0*.*f\n", 20, 19, 5.500946755555555555555555555);
	//ft_printf("%.2s\n", NULL);
	//printf("%.2s\n", NULL);
	//ft_printf("%10s\n", NULL);
	//printf("%10s\n", NULL);
	//printf("%d\n", t);
	//printf("%s.5%n\n", "Coucou", &t);
	//printf("%d\n", t);
	//printf("%050p\n", &t);
	//ft_printf("%050p\n", &t);
	//printf("%%\n");
	//ft_printf("%%\n", 100);
	//printf("Test %s%n\n", "Ok google", &t);
	//ft_printf("Test %s%n\n", "Ok google", &t);
	//printf("%d\n", t);
	//ft_printf("Test %10.10s%n\n", "Ok google", &t);
	//printf("%d\n", t);
	//printf("Test %40.0s\n", "Ok google");
	//ft_printf("Test %40.0s\n", "Ok google");
	//printf("Test %1.50s\n", "Ok google");
	//ft_printf("Test %1.50s\n", "Ok google");
	//ft_printf("%-*.*d\n", 50, 1, 4687);
	//printf("%-*.*d\n", 50, 1, 4687);
	//ft_printf("%d\n", t);
	//printf("%-55.50X\n", -55);
	//ft_printf("%-55.50X\n", -55);
	//printf("%0*.*x\n", 20, 20, -55);
	//ft_printf("%0*.*x\n", 20, 20, -55);
	/*printf("%18.5d\n", 500);
	ft_printf("my printf : \n%18.5d\n", 500);
	printf("%-10.3i\n", 500);
	ft_printf("%-10.3i\n", 500);
	printf("%18.5d\n", 500);
	ft_printf("%18.5d\n", 500);
	ft_printf("%*.*s\n", 5, 2, "Coucou");
	printf("%*.*s\n", 5, 2, "Coucou");
	ft_printf("%-.*s\n", 1, "Coucou");
	printf("%-.*s\n", 1, "Coucou");
	ft_printf("%c\n", '\200');
	printf("%c\n", '\200');
	printf("%-*p\n", 50, t);
	ft_printf("%-*p\n", 50, t);
	printf("%i\n", -50);
	ft_printf("%i\n", -50);
	printf("\n\nTEST %25.2s\n", "Hello world");
	ft_printf("\n\nTEST %25.2s\n", "Hello world");
	ft_printf("%-030s\n", "Hello world");
	printf("%030s\n", "Hello world");
	printf("%03d\n", 0);
	ft_printf("%03d\n", 0);
	printf("%010d\n", -10);
	ft_printf("%010d\n", -10);
	printf("%1.40d\n", -10);
	ft_printf("%1.40d\n", -10);*/
//	printf("%1.s\n", "Hey");
}
