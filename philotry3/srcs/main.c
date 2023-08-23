/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:48:44 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/08/23 17:04:37 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	args_valid(char **argv)
{
	int				i;
	long int		a;

	i = 0;
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

void	end_and_free(t_env *env)
{
	int	i;

	i = -1;
	while (++i < env->nop)
		pthread_join(env->table[i]->thread, NULL);
}

void	ft_let_the_hungergames_begin(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nop)
	{
		pthread_create(&env->table[i]->thread, NULL, ft_philo_life,
			env->table[i]);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc < 5 || argc > 6)
		putstr_exit("INVALID ARGUMENTS\n", 1);
	args_valid(argv);
	env = ft_init_data(argc, argv);
	ft_let_the_hungergames_begin(env);
	while (1)
	{
		pthread_mutex_lock(&env->end_lock);
		if (env->end == true)
			break ;
		if (env->philos_full >= env->nop)
		{
			printf("all satisfied!\n");
			break ;
		}
		pthread_mutex_unlock(&env->end_lock);
	}
	pthread_mutex_unlock(&env->end_lock);
	end_and_free(env);
	return (0);
}
