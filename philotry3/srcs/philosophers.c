/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:31:18 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/08/18 18:32:44 by zvan-de-         ###   ########.fr       */
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

void	ft_eat(t_philo *philo)
{
	print_state("is eating", philo);
	philo->n_forks = 0;
	philo->thinking = false;
	philo->eating = true;
	philo->t_eat++;
	philo->t_to_die = get_time() + philo->env->ttd; 
	philo->start_eat = get_time();
}

void	ft_stop_eat(t_env *env, t_philo *philo, int left, int right)
{
	print_state("is sleeping", philo);
	ft_release_fork(env, philo, left);
	ft_release_fork(env, philo, right);
	philo->eating = false;
	philo->sleeping = true;
	philo->start_eat = 0;
	philo->n_forks = 0;
}

void	ft_check_eat(t_env *env, t_philo *philo, long time)
{
	int		left;
	int		right;

	(void) time;
	left = philo->id - 1;
	right = (philo->id) % env->nop;
	if (!ft_try_fork(env, left) && !philo->eating && !ft_check_end(env))
		ft_take_fork(env, philo, left);
	if (env->nop > 1 && !ft_try_fork(env, right) && !philo->eating && !ft_check_end(env))
		ft_take_fork(env, philo, right);
	if (philo->n_forks > 1)
		ft_eat(philo);
	else if (time - philo->start_eat >= env->tte && philo->thinking == false)
		ft_stop_eat(env, philo, left, right);
}

long	ft_sleep(t_env *env, t_philo *philo, long int timer)
{
	if (philo->start_slp == 0 && philo->sleeping)
		philo->start_slp = timer;
	else if (timer - philo->start_slp >= env->tts)
	{
		philo->sleeping = false;
		philo->thinking = true;
		philo->start_slp = 0;
		print_state("is thinking", philo);
	}
	return (get_time());
}

void	ft_end_data(t_env *env, t_philo *philo)
{
	pthread_mutex_lock(&env->end_lock);
	if (env->to_full > 0)
	{
		if (philo->t_eat >= env->to_full)
			env->philos_full++;
	}
	else 
		env->end = true;
	pthread_mutex_unlock(&env->end_lock);
	return ;
}

int	ft_check_end(t_env *env)
{
	int i;

	i = 0;
	pthread_mutex_lock(&env->end_lock);
	if (env->end)
		i = 1;
	pthread_mutex_unlock(&env->end_lock);
	return (i);
}

void	*ft_philo_life(void *param)
{
	t_philo			*philo;
	t_env			*env;
	long			time;

	philo = (t_philo *) param;
	env = (t_env *) philo->env;
	time = get_time();
	philo->t_to_die = time + env->ttd;
	if (philo->id % 2 || philo->id == 1)
		usleep(100000);
	while (1)
	{
		time = get_time();
		if (philo->sleeping)
			ft_sleep(env, philo, time);
		else if (philo->thinking || philo->eating)
			ft_check_eat(env, philo, time);
		if (philo->t_to_die - time <= 0)
		{
			print_state("has died", philo);
			break ;
		}
		if (env->to_full > 0)
		{
			if (philo->t_eat >= env->to_full)
				break ;
		}
		if (ft_check_end(env))
			break ;
	}
	ft_release_fork(env, philo, philo->id - 1);
	ft_release_fork(env, philo, (philo->id) % env->nop);
	printf("philo %d got out\n", philo->id);
	ft_end_data(env, philo);
	return (NULL);
}
