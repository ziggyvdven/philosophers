/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 10:03:59 by zvandeven         #+#    #+#             */
/*   Updated: 2023/04/27 16:37:08 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long int	ft_atol(const char *nptr)
{
	int			i;
	int			sign;
	long int	nb;
	char		*str;

	sign = 1;
	nb = 0;
	i = 0;
	if (!nptr || (nptr[0] == '-' && (nptr[1] == '\0' || nptr[1] == '-')))
		return (LLONG_MAX);
	str = (char *)nptr;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}
