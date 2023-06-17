/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:43:36 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/17 16:08:49 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include	<stdio.h>
# include	<string.h>
# include	<stdlib.h>
# include	<stdbool.h>
# include	<limits.h>
# include	<fcntl.h>
# include	<unistd.h>
# include	<sys/time.h>
# include	<pthread.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t	id;
	int			state;
	t_data		*data;
	int			n;
}				t_philo;

typedef struct s_data
{
	int					np;
	int					ttd;
	int					tte;
	int					tts;
	int					ntp;
	pthread_mutex_t		*forks;
	t_philo				philo[];
}				t_data;

/*PHILOSOPHERS*****************************************************************/
void				*philo_funtion(void *param);

/*INITS************************************************************************/
pthread_mutex_t		*make_forks(t_data *data);
t_data				*init_data(int argc, char **argv);
void				get_philosophers(t_data *data);

/*UTILS************************************************************************/
int					ft_strisdigit(char *str);
void				putstr_exit(char *str, int fd);
long int			ft_atol(const char *nptr);

#endif