/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:31:18 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/28 20:46:23 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long	get_time(void)
{
	struct timeval		tv;
	long				milliseconds;

	gettimeofday(&tv, NULL);
	milliseconds = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (milliseconds);
}

void	ft_eat(t_data *data, t_philo *philo)
{
	philo->state = 1;
	pthread_mutex_lock(&data->forks[philo->n]);
	printf("%lu Philo %d has taken his left fork!\n",
		get_time() - data->start_time, philo->n + 1);
	if (data->np > 1)
		pthread_mutex_lock(&data->forks[(philo->n + 1) % data->np]);
	printf("%lu Philo %d has taken a right fork!\n",
		get_time() - data->start_time, philo->n + 1);
	printf("%lu Philo %d is eating!\n", 
		get_time() - data->start_time, philo->n + 1);
	philo->start_eat = get_time();
	while ((get_time() - philo->start_eat) >= data->tte);
	philo->ate++;
	pthread_mutex_unlock(&data->forks[philo->n]);
	pthread_mutex_unlock(&data->forks[(philo->n + 1) % data->np]);
}

long	ft_sleep(t_data *data, t_philo *philo)
{
	(void) data;
	philo->state = 2;
	printf("%lu Philo %d is sleeping!\n", get_time() - data->start_time, 
		philo->n + 1);
	return (get_time());
}

void	ft_think(t_philo *philo)
{
	philo->state = 0;
	printf("%lu Philo %d is thinking!\n", get_time() - philo->data->start_time,
		philo->n + 1);
}

void	*philo_funtion(void *param)
{
	t_philo			*philo;
	t_data			*data;
	long			start_sleep;

	philo = param;
	data = philo->data;
	start_sleep = 0;
	while (1 && philo->is_dead == 0)
	{
		if (philo->is_dead || (philo->ate >= data->ntp && data->ntp))
			break ;
		if (data->philo[(philo->n + (data->np - 1)) % data->np].state != 1
			&& data->philo[(philo->n + 1) % data->np].state != 1
			&& data->philo[philo->n].state == 0)
			ft_eat(data, philo);
		if (philo->state == 1 && !philo->is_dead)
			start_sleep = ft_sleep(data, philo);
		if (get_time() - start_sleep >= data->tts
			&& data->philo[philo->n].state == 2 && !philo->is_dead)
			ft_think(philo);
	}
	return (NULL);
}
