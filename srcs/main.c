/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zvan-de- <zvan-de-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:48:44 by zvan-de-          #+#    #+#             */
/*   Updated: 2023/06/17 13:31:37 by zvan-de-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		putstr_exit("INVALID ARGUMENTS\n", 1);
	args_valid(argc, argv);
	data = init_data(argc, argv);
	get_philosophers(data);
	pthread_join(data->philo[0].id, NULL);
	printf("%d\n", data->np);
	printf("%d\n", data->ttd);
	printf("%d\n", data->tte);
	printf("%d\n", data->tts);
	printf("%d\n", data->ntp);
	return (0);
}
