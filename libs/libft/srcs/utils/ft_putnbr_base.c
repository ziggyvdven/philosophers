/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:07:25 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/19 11:39:44 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_doublechar(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
		++j;
		}
	++i;
	}
	return (0);
}

void	ft_printnbr(int nbr, int len, char *base)
{
	long int	lnbr;

	lnbr = nbr;
	if (lnbr < 0)
	{
		lnbr *= -1;
		write (1, "-", 1);
	}
	if (lnbr >= len)
		ft_printnbr(lnbr / len, len, base);
	ft_putchar(base[lnbr % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = 0;
	while (base[len] != '\0')
	{
		if (((base[len] == '-') || (base[len] == '+'))
			|| ((base[len] <= 31)))
			return ;
	len ++;
	}
	if (len < 2)
		return ;
	if (ft_doublechar(base))
		return ;
	ft_printnbr(nbr, len, base);
}
