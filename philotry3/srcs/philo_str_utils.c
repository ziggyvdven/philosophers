/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_str_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:10:49 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/08/18 14:56:30 by zvan-de-         ###   ########.fr       */
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

long	get_time(void)
{
	struct timeval		tv;
	long				milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}

void	print_state(char *str, t_philo *philo)
{
	unsigned long	timestamp;

	pthread_mutex_lock(&philo->env->print_lock);
	timestamp = get_time() - philo->env->start_t;
	printf("%lu %d %s\n", timestamp, philo->id, str);
	pthread_mutex_unlock(&philo->env->print_lock);
}
