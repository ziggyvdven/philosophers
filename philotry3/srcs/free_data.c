/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:32:03 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/08/17 16:28:24 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// void	return_threads(t_data *data)
// {
// 	int i;

// 	i = -1;
// 	while (i < data->np)
// 		pthread_join(data->philo[i++].id, NULL);
// 	i = -1;
// 	while (++i < data->np)
// 	{
// 		pthread_mutex_unlock(&data->forks[i]);
// 		if (pthread_mutex_destroy(&data->forks[i]))
// 			putstr_exit("ERROR DESTROYING FORKS", 1);
// 	}
// }
