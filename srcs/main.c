/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:48:44 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/16 20:41:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

t_data	*init_data(int argc, char **argv)
{
	t_data		*data;
	static int	i = 0;

	data = (t_data *)malloc((sizeof(t_data)) + (int)ft_atol(argv[1])
			* sizeof(t_philo));
	if (!data)
		return (NULL);
	data->np = (int)ft_atol(argv[1]);
	data->ttd = (int)ft_atol(argv[2]) * 1000;
	data->tte = (int)ft_atol(argv[3]) * 1000;
	data->tts = (int)ft_atol(argv[4]) * 1000;
	if (argc == 6)
		data->ntp = (int)ft_atol(argv[5]);
	else
		data->ntp = 0;
	while (i < data->np)
	{
		data->philo[i].id = 0;
		data->philo[i].name = i + 1;
		data->philo[i].data = data;
		i++;
	}
	data->forks = NULL;
	return (data);
}

void	args_valid(int argc, char **argv)
{
	int				i;
	long int		a;

	i = 0;
	(void) argc;
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

void	*philo_funtion(void *param)
{
	t_philo	*philo;
	t_data	*data;

	philo = param;
	data = philo->data;
	while(1)
	{
		usleep(50);
		printf("Philo %d is thinking!\n", philo->name);
		if (data->forks[philo->name % data->np + 1] == 1
		&& data->forks[philo->name % data->np] == 1)
		{
			data->forks[philo->name % data->np + 1] = 0;
			data->forks[philo->name % data->np] = 0;
			printf("Philo %d is eating!\n", philo->name);
			usleep(data->tte);
			data->forks[philo->name % data->np + 1] = 1;
			data->forks[philo->name % data->np] = 1;
			printf("Philo %d is sleeping!\n", philo->name);
			usleep(data->tts);
		}
	}
}

void	get_philosophers(t_data *data)
{
	int	i;
	int	forks[data->np];
	
	i = 0;
	while (forks[i])
		forks[i++] = 1;
	data->forks = forks;
	i = 0;
	while (i < data->np)
	{
		pthread_create(&data->philo[i].id, NULL, philo_funtion, &data->philo[i]);
		i++;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		putstr_exit("INVALID ARGUMENTS\n", 1);
	args_valid(argc, argv);
	data = init_data(argc, argv);
	get_philosophers(data);
	sleep(1);
	printf("%d\n", data->np);
	printf("%d\n", data->ttd);
	printf("%d\n", data->tte);
	printf("%d\n", data->tts);
	printf("%d\n", data->ntp);
	return (0);
}

// #include <pthread.h>
// #include <stdio.h>

// void *thread_function(void *arg) {
//     int thread_arg = *(int *)arg;
//     printf("Hello from thread! Argument: %d\n", thread_arg);
//     pthread_exit(NULL);
// }

// int main() {
//     pthread_t thread_id;
//     int arg = 42;

//     pthread_create(&thread_id, NULL, thread_function, (void *)&arg);

//     // Do some other work in the main thread

//     pthread_join(thread_id, NULL);

//     return 0;
// }