/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:21:05 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/13 18:02:27 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_checkzero(long int a, int fd)
{
	if (a == 0)
	{
		write (fd, "0", 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	char		str[11];
	long int	tempn;
	int			i;

	i = 1;
	tempn = n;
	ft_checkzero(tempn, fd);
	if (tempn < 0)
	{
		write(fd, "-", 1);
		tempn = tempn * -1;
	}
	while (tempn > 0)
	{
		str[i] = tempn % 10 + 48;
		i++;
		tempn = tempn / 10;
	}
	i = i -1;
	while (i > 0)
	{
		write (fd, &str[i], 1);
		--i;
	}
}

// int main()
// {
// 	ft_putnbr_fd(50, 1);
// }
