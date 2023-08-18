/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:43:36 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/08/18 18:28:41 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_env	t_env;

typedef struct s_fork
{
	pthread_mutex_t	fork;
	pthread_mutex_t	fork_try;
	bool			in_use;
}				t_fork;

typedef struct s_philo
{
	t_env			*env;
	int				id;
	int				n_forks;
	int				t_eat;
	bool			thinking;
	bool			sleeping;
	bool			eating;
	long int		t_to_die;
	long int		start_slp;
	long int		start_eat;
	pthread_t		thread;
}				t_philo;

typedef struct s_env
{
	int				nop;
	int				ttd;
	int				tts;
	int				tte;
	int				philos_full;
	bool			end;
	int				to_full;
	long int		start_t;
	t_fork			**forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	end_lock;
	t_philo			**table;
}				t_env;



/*PHILOSOPHERS*****************************************************************/
void				*ft_philo_life(void *param);
void				ft_check_eat(t_env *env, t_philo *philo, long time);

/*INITS************************************************************************/
t_env				*ft_init_data(int argc, char **argv);
void				place_philos(t_env *env);
void				make_forks(t_env *env);

/*UTILS************************************************************************/
int					ft_strisdigit(char *str);
void				putstr_exit(char *str, int fd);
long int			ft_atol(const char *nptr);
long				get_time(void);
void				print_state(char *str, t_philo *philo);
int					ft_check_end(t_env *env);

#endif