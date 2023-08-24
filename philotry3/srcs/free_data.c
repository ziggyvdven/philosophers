/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:32:03 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/08/23 18:50:21 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	exit_and_free(t_env *env, char *msg, int fd)
{
	end_and_free(env);
	putstr_exit(msg, fd);
}

void	end_and_free(t_env *env)
{
	int	i;

	i = -1;
	if (ft_check_end(env))
		while (++i < env->nop)
			pthread_join(env->table[i]->thread, NULL);
	i = -1;
	if (env->table)
	{
		while (++i < env->nop)
		{
			pthread_mutex_destroy(&env->forks[i]->fork);
			pthread_mutex_destroy(&env->forks[i]->fork_try);
			free(env->table[i]);
			free(env->forks[i]);
		}
		free(env->forks);
		free(env->table);
	}
	pthread_mutex_destroy(&env->print_lock);
	pthread_mutex_destroy(&env->print_lock);
	free(env);
	return ;
}
