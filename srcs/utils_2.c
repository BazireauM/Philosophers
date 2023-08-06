/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 04:56:06 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/06 05:42:23 by mbazirea         ###   ########.fr       */
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
