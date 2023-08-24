/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:31:18 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/08/23 19:36:12 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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

void	ft_check_eat(t_env *env, t_philo *philo, long time)
{
	int		left;
	int		right;

	(void) time;
	left = philo->id - 1;
	right = (philo->id) % env->nop;
	if (!ft_try_fork(env, left) && !philo->eating && !ft_check_end(env))
		ft_take_fork(env, philo, left);
	if (env->nop > 1 && !ft_try_fork(env, right) 
		&& !philo->eating && !ft_check_end(env))
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

void	ft_philo_loop(t_env *env, t_philo *philo, long time)
{
	while (1)
	{
		time = get_time();
		if (philo->sleeping)
			ft_sleep(env, philo, time);
		else if (philo->thinking || philo->eating)
			ft_check_eat(env, philo, time);
		usleep(50);
		if (ft_check_end(env))
			break ;
		if (philo->t_to_die - time <= 0)
		{
			print_state("died", philo);
			break ;
		}
		if (env->to_full > 0)
			if (philo->t_eat >= env->to_full)
				break ;
	}
	return ;
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
	ft_philo_loop(env, philo, time);
	ft_end_data(env, philo);
	ft_stop_eat(env, philo, philo->id - 1, (philo->id) % env->nop);
	return (NULL);
}
