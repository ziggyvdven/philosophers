/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:21:05 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/19 12:22:39 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/libft.h"

void	ft_checkzero_pf(long int a)
{
	if (a == 0)
	{
		write (1, "0", 1);
	}
}

int	ft_dcount(int n)
{
	long int		tempn;
	unsigned int	count;

	tempn = n;
	count = 0;
	if (n == 0)
		count++;
	if (n < 0)
	{
		count++;
		tempn = tempn * -1;
	}
	while (tempn > 0)
	{
		tempn = tempn / 10;
		count++;
	}
	return (count - 1);
}

int	ft_putnbr_pf(int n, int count)
{
	char		str[11];
	long int	tempn;
	int			i;

	i = 1;
	tempn = n;
	ft_checkzero_pf(tempn);
	if (tempn < 0)
	{
		write(1, "-", 1);
		tempn = tempn * -1;
	}
	while (tempn > 0)
	{
		str[i++] = tempn % 10 + 48;
		tempn = tempn / 10;
	}
	i = i -1;
	while (i > 0)
	{
		write (1, &str[i], 1);
		--i;
	}
	count = ft_dcount(n);
	return (count);
}
