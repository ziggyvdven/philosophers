/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:46:14 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/08/23 19:27:01 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_try_fork(t_env *env, int side)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&env->forks[side]->fork_try);
	if (env->forks[side]->in_use)
		i = 1;
	pthread_mutex_unlock(&env->forks[side]->fork_try);
	usleep(50);
	return (i);
}

void	ft_take_fork(t_env *env, t_philo *philo, int side)
{
	pthread_mutex_lock(&env->forks[side]->fork);
	print_state("has taken a fork", philo);
	pthread_mutex_lock(&env->forks[side]->fork_try);
	env->forks[side]->in_use = true;
	pthread_mutex_unlock(&env->forks[side]->fork_try);
	philo->n_forks++;
}

void	ft_release_fork(t_env *env, t_philo *philo, int side)
{
	pthread_mutex_unlock(&env->forks[side]->fork);
	pthread_mutex_lock(&env->forks[side]->fork_try);
	env->forks[side]->in_use = false;
	pthread_mutex_unlock(&env->forks[side]->fork_try);
	philo->n_forks--;
}

void	ft_stop_eat(t_env *env, t_philo *philo, int left, int right)
{
	if (!ft_check_end(env))
		print_state("is sleeping", philo);
	ft_release_fork(env, philo, left);
	ft_release_fork(env, philo, right);
	philo->eating = false;
	philo->sleeping = true;
	philo->start_eat = 0;
	philo->n_forks = 0;
}
