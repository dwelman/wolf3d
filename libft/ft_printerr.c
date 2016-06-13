/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daviwel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 07:42:51 by daviwel           #+#    #+#             */
/*   Updated: 2016/06/13 09:21:19 by daviwel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printaux(char *cr, va_list args, t_flags flags)
{
	int	count;

	count = 0;
	if (*cr == 'p')
	{
		flags.address = 1;
		count += ft_padstr(ft_convert((UI)va_arg(args, void *), 16, 0), flags);
	}
	else if (*cr == 'c')
		count += ft_padchar(va_arg(args, int), flags);
	else if (*cr == 'C' || (*cr == 'c' && flags.is_long > 0))
		count += ft_padchar((char)va_arg(args, wchar_t), flags);
	return (count);
}

static int	ft_handleprint(va_list args, char *cr, t_flags flags)
{
	int			count;

	count = 0;
	if (*cr == 'o' || *cr == 'O')
		flags.use_hasho = 1;
	else if (*cr == 'x' || *cr == 'X')
		flags.use_hashx = 1;
	if (*cr == 's')
	{
		flags.is_string = 1;
		count += ft_padstr(va_arg(args, char *), flags);
	}
	else if (*cr == 'S')
	{
		flags.is_string = 1;
		flags.wide = 1;
		count += ft_padstrwide(va_arg(args, wchar_t *), flags);
	}
	count += ft_printaux(cr, args, flags);
	count += ft_di(cr, args, flags);
	count += ft_uox(cr, args, flags);
	return (count);
}

void		ft_printerr(const char *format_str, ...)
{
	char	*cr;
	va_list	args;
	t_flags	flags;
	int		ret;

	ret = 0;
	cr = (char *)format_str;
	va_start(args, format_str);
	while (*cr != '\0')
	{
		if (*cr != '%')
			ret += ft_putchar(*cr);
		if (*cr == '%' && *(cr + 1) != '%')
		{
			flags = ft_getflags(flags, cr);
			cr += flags.offset;
			ret += ft_handleprint(args, cr, flags);
		}
		else if (*cr == '%' && *(cr + 1) == '%')
			ret += ft_putchar('%');
		cr++;
	}
	va_end(args);
	exit(-1);
}
