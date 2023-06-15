/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printadr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:07:25 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/19 12:26:53 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

int	ft_printnbr_adr(unsigned long nbr, unsigned int len, char *base)
{
	unsigned long int	lnbr;
	int					count;

	count = 0;
	lnbr = nbr;
	if (lnbr >= len)
	{
		count = ft_printnbr_adr(lnbr / len, len, base) + 1;
	}
	ft_putchar(base[lnbr % len]);
	return (count);
}

int	ft_putnbr_base_adr(unsigned long nbr, int count, int b)
{
	int		len;
	char	*base;

	len = 0;
	if (b == 1)
		base = "0123456789abcdef";
	if (b == 2)
		base = "0123456789ABCDEF";
	while (base[len] != '\0')
	len ++;
	count = ft_printnbr_adr(nbr, len, base);
	return (count);
}

int	ft_printadr(va_list *args)
{
	int		count;

	count = 2;
	write(1, "0x", 2);
	count += ft_putnbr_base_adr(va_arg(*args, unsigned long), count, 1);
	return (count);
}
