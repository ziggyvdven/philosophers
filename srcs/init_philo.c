/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:28:44 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/29 21:27:21 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_data	*init_data(int argc, char **argv)
{
	t_data		*data;
	int			i;

	i = -1;
	data = (t_data *)malloc((sizeof(t_data)) + ((int)ft_atol(argv[1])
				* sizeof(t_philo)));
	if (!data)
		return (NULL);
	data->np = (int)ft_atol(argv[1]);
	data->ttd = (int)ft_atol(argv[2]);
	data->tte = (int)ft_atol(argv[3]);
	data->tts = (int)ft_atol(argv[4]);
	if (argc == 6)
		data->ntp = (int)ft_atol(argv[5]);
	else
		data->ntp = 0;
	while (++i < data->np)
		data->philo[i] = init_philo(data, i);
	data->forks = make_forks(data);
	data->start_time = get_time();
	data->dead = 0;
	data->end = 0;
	return (data);
}

t_philo	init_philo(t_data *data, int i)
{
	data->philo[i].id = 0;
	data->philo[i].n = i;
	data->philo[i].data = data;
	data->philo[i].state = 0;
	data->philo[i].start_eat = get_time();
	data->philo[i].ate = 0;
	data->philo[i].satisfied = 0;
	data->philo[i].is_dead = 0;
	return (data->philo[i]);
}

void	get_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->np)
	{
		pthread_create(&data->philo[i].id, NULL, philo_life,
			&data->philo[i]);
		i++;
	}
	return ;
}

pthread_mutex_t	*make_forks(t_data *data)
{
	pthread_mutex_t	*forks;
	int				i;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * data->np);
	if (!forks)
		putstr_exit("Unable to malloc forks", 1);
	while (++i < data->np)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}
