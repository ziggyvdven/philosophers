/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:09:49 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/19 12:22:13 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

int	ft_prspecifier(char c, va_list *args)
{
	int	count;

	count = 0;
	if (c == 'c')
		ft_putchar(va_arg(*args, int));
	else if (c == 's')
		count += (ft_putstr(va_arg(*args, char *)) - 1);
	else if (c == 'p')
		count += ft_printadr(&*args);
	else if (c == 'd' || c == 'i')
		count += ft_putnbr_pf(va_arg(*args, int), count);
	else if (c == 'u')
		count += ft_putunsing(va_arg(*args, unsigned int), count);
	else if (c == 'x')
		count += ft_putnbr_base_pf(va_arg(*args, unsigned int), count, 1);
	else if (c == 'X')
		count += ft_putnbr_base_pf(va_arg(*args, unsigned int), count, 2);
	else if (c == '%')
		ft_putchar('%');
	return (count);
}

int	ft_printf(const char *print_str, ...)
{
	int			i;
	va_list		args;
	int			count;

	i = 0;
	count = 0;
	va_start (args, print_str);
	while (print_str[i] != '\0')
	{	
		if (print_str[i] != '%')
		{
			write(1, &print_str[i], 1);
			count++;
		}
		else if (print_str[i] == '%')
		{
			count += ft_prspecifier(print_str[i + 1], &args);
			count++;
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
