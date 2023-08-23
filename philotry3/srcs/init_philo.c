/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:28:44 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/08/23 16:36:08 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_env	*ft_init_data(int argc, char **argv)
{
	t_env		*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->nop = (int)ft_atol(argv[1]);
	env->ttd = (int)ft_atol(argv[2]);
	env->tte = (int)ft_atol(argv[3]);
	env->tts = (int)ft_atol(argv[4]);
	env->end = false;
	env->philos_full = 0;
	env->to_full = 0;
	if (pthread_mutex_init(&env->end_lock, NULL))
		putstr_exit("ERROR creating mutex\n", 1);
	if (argc == 6)
		env->to_full = (int)ft_atol(argv[5]);
	env->table = malloc(sizeof(t_philo *) * env->nop + 1);
	env->table[env->nop] = NULL;
	place_philos(env);
	env->forks = malloc(sizeof(t_fork *) * env->nop + 1);
	env->forks[env->nop] = NULL;
	make_forks(env);
	env->start_t = get_time();
	pthread_mutex_init(&env->print_lock, NULL);
	return (env);
}

void	place_philos(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->nop)
	{
		env->table[i] = malloc(sizeof(t_philo));
		env->table[i]->env = (void *) env;
		env->table[i]->id = i + 1;
		env->table[i]->t_eat = 0;
		env->table[i]->n_forks = 0;
		env->table[i]->thinking = true;
		env->table[i]->sleeping = false;
		env->table[i]->eating = false;
		env->table[i]->start_slp = 0;
		env->table[i]->start_eat = 0;
		env->table[i]->t_to_die = 0;
	}
}

void	make_forks(t_env *env)
{
	int				i;

	i = -1;
	while (++i < env->nop)
	{
		env->forks[i] = malloc(sizeof(t_fork));
		env->forks[i]->in_use = false;
		if (pthread_mutex_init(&env->forks[i]->fork, NULL))
			putstr_exit("ERROR creating forks\n", 1);
		if (pthread_mutex_init(&env->forks[i]->fork_try, NULL))
			putstr_exit("ERROR creating forks\n", 1);
	}
}
