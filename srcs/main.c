/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:48:44 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/28 21:20:08 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	args_valid(int argc, char **argv)
{
	int				i;
	long int		a;

	i = 0;
	(void) argc;
	while (argv[++i])
	{
		if (ft_strisdigit(argv[i]) != 1)
			putstr_exit("ERROR ARG NOT DIGIT\n", 1);
		a = ft_atol(argv[i]);
		if (a > INT_MAX || a < INT_MIN)
			putstr_exit("ERROR ARG TOO BIG/SMALL\n", 1);
		if (a < 0)
			putstr_exit("ERROR NEGATIVE VALUE\n", 1);
	}
	if (ft_atol(argv[1]) < 1)
		putstr_exit("ERROR NOT ENOUGH PHILOSOPHERS\n", 1);
	return ;
}

static void	wait_philo(t_data *d)
{
	int	i;
	int	ate_enough;

	ate_enough = 0;
	while (ate_enough <= d->np)
	{
		i = -1;
		while (++i < d->np)
		{
			if ((get_time() - d->philo[i].start_eat) >= d->ttd
				&& !d->philo[i].is_dead)
			{
				d->philo[i].is_dead = 1;
				printf("%lu  Philosopher %d died\n", get_time() - d->start_time,
					d->philo[i].n + 1);
				return ;
			}
			if (d->philo[i].ate == d->ntp && d->ntp && !d->philo[i].satisfied)
			{
				d->philo[i].satisfied = 1;
				ate_enough++;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	if (argc < 5 || argc > 6)
		putstr_exit("INVALID ARGUMENTS\n", 1);
	args_valid(argc, argv);
	data = init_data(argc, argv);
	get_philosophers(data);
	wait_philo(data);
	i = -1;
	printf("times they need to eat = %d\n", data->ntp);
	while (++i < data->np)
		printf("Philosopher %d ate %d times\n", data->philo[i].n + 1, data->philo[i].ate);
	// while (i <= data->np)
	// 	pthread_join(data->philo[i++].id, NULL);
	printf("all satisfied\n");
	return (0);
}
