/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:43:36 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/16 19:46:26 by codespace        ###   ########.fr       */
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

typedef struct s_data t_data;

typedef struct s_philo
{
	pthread_t	id;
	t_data		*data;
	int			name;
}				t_philo;

typedef struct s_data
{
	int			np;
	int			ttd;
	int			tte;
	int			tts;
	int			ntp;
	int			*forks;
	t_philo		philo[];
}				t_data;


/*CHECKS*********************************/

/*UTILS*********************************/
int			ft_strisdigit(char *str);
void		putstr_exit(char *str, int fd);
long int	ft_atol(const char *nptr);

#endif