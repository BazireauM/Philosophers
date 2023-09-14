/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:07:25 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/06 04:05:24 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_param(t_param *param, int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		printf("need good argument: number_of_philosophers time_to_die time");
		printf("_to_eat time_to_sleep [number_of_times_each_philosopher_");
		printf("must_eat]\n");
		return (1);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) < 0 || ft_atoi(argv[3]) < 0
		|| ft_atoi(argv[4]) < 0)
		return (1);
	param->number_of_philosopher = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	param->max_eat = -42;
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 0)
			return (1);
		param->max_eat = ft_atoi(argv[5]);
	}
	param->dead = 0;
	pthread_mutex_init(&(param->m_log), NULL);
	pthread_mutex_init(&(param->m_dead), NULL);
	return (0);
}

int	init_philo(t_param *param, t_philo **philo, t_fork **fork)
{
	*philo = malloc(sizeof(t_philo) * param->number_of_philosopher);
	if (!philo)
		return (1);
	*fork = malloc (sizeof(t_fork) * param->number_of_philosopher);
	if (!fork)
	{
		free(philo);
		return (1);
	}
	init_philo_param(param, fork, philo);
	return (0);
}

int	init_philo_param(t_param *param, t_fork **fork, t_philo **philo)
{
	int		i;
	t_philo	*test;

	i = 0;
	while (i < param->number_of_philosopher)
	{
		test = &(*philo)[i];
		test->param = param;
		test->id = i;
		test->n_eat = 0;
		test->last_eat = 0;
		test->right_fork_use = 0;
		test->left_fork_use = 0;
		test->right_fork = &((*fork)[i]);
		if (i == param->number_of_philosopher - 1)
			test->left_fork = &((*fork)[0]);
		else
			test->left_fork = &((*fork)[i + 1]);
		test->left_fork->use = 0;
		pthread_mutex_init(&(test->left_fork->lock), NULL);
		pthread_mutex_init(&(test->m_last_eat), NULL);
		i++;
	}
	return (0);
}
