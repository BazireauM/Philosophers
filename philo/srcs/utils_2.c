/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:56:06 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/07 06:47:30 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	use_fork(int id, t_philo *philo)
{
	int		*i;
	t_fork	*fork;

	if (!test_death_philo(philo))
	{
		i = &(philo->left_fork_use);
		fork = philo->left_fork;
		if (id == 1)
		{
			i = &(philo->right_fork_use);
			fork = philo->right_fork;
		}
		pthread_mutex_lock(&(fork->lock));
		if (*i == 0 && !fork->use)
		{
			*i = 1;
			fork->use = 1;
			pthread_mutex_unlock(&(fork->lock));
			write_status("has taken a fork", philo);
		}
		else
			pthread_mutex_unlock(&(fork->lock));
	}
}

void	stop_use_fork(int id, t_philo *philo)
{
	int		*i;
	t_fork	*fork;

	i = &(philo->left_fork_use);
	fork = philo->left_fork;
	if (id == 1)
	{
		i = &(philo->right_fork_use);
		fork = philo->right_fork;
	}
	pthread_mutex_lock(&(fork->lock));
	*i = 0;
	fork->use = 0;
	pthread_mutex_unlock(&(fork->lock));
}

int all_eat(t_param *param, t_philo **philo)
{
	int i;
	int x;
	t_philo *phil;

	i = 0;
	x = 0;
	while (i < param->number_of_philosopher)
	{
		phil = &(*philo)[i];
		pthread_mutex_lock(&(phil->m_last_eat));
		if (phil->n_eat == param->max_eat)
			x++;
		pthread_mutex_unlock(&(phil->m_last_eat));
		i++;
	}
	if (x == i)
		return (1);
	return (0);
}
