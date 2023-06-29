/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:31:18 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/28 19:26:18 by zvan-de-         ###   ########.fr       */
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

long	ft_eat(t_data *data, t_philo *philo)
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
	usleep(data->tte);
	philo->ate++;
	pthread_mutex_unlock(&data->forks[philo->n]);
	pthread_mutex_unlock(&data->forks[(philo->n + 1) % data->np]);
	return (get_time());
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
	printf("%lu Philo %d is thinking!\n", get_time() - philo->data->start_time,
		philo->n + 1);
	philo->state = 0;
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
		// if ((get_time() - philo->time_ate) >= data->ttd)
		// 	break ;
		if (data->philo[(philo->n + (data->np - 1)) % data->np].state != 1
			&& data->philo[(philo->n + 1) % data->np].state != 1
			&& data->philo[philo->n].state == 0)
			philo->time_ate = ft_eat(data, philo);
		if (philo->state == 1)
			start_sleep = ft_sleep(data, philo);
		if (get_time() - start_sleep >= data->tts
			&& data->philo[philo->n].state == 2)
			ft_think(philo);
	}
	// printf("%lu  Philosopher %d died\n", get_time() - data->start_time,
	// 	philo->n + 1);
	return (NULL);
}
