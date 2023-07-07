/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_str_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:10:49 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/07/07 15:24:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	putstr_exit(char *str, int fd)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		write(fd, &str[i], 1);
	exit(fd);
}

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
