/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:48:52 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/08/23 17:04:26 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_end_data(t_env *env, t_philo *philo)
{
	pthread_mutex_lock(&env->end_lock);
	if (!env->end)
	{
		if (env->to_full > 0 && philo->t_eat >= env->to_full)
			env->philos_full++;
		else 
			env->end = true;
	}
	else
		env->end = true;
	pthread_mutex_unlock(&env->end_lock);
	return ;
}

int	ft_check_end(t_env *env)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&env->end_lock);
	if (env->end)
		i = 1;
	pthread_mutex_unlock(&env->end_lock);
	return (i);
}
