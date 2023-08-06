/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 03:52:37 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/06 05:42:21 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_thread(t_philo **philo)
{
	int	i;

	i = 0;
	philo[0]->param->time = get_time();
	while (i < philo[0]->param->number_of_philosopher)
	{
		if (pthread_create(&(philo[i]->t_philo), NULL, life, &(philo[i])))
			return (1);
		i++;
	}
	if (pthread_create(&(philo[0]->param->t_death), NULL, check_life, philo))
		return (1);
	return (0);
}

void	*life(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	if (philo->id % 2 == 1)
		stay(philo->param->time_to_eat);
	while (!test_death_philo(philo))
	{
		if (philo->n_eat >= philo->param->max_eat
			&& philo->param->max_eat != -42)
			break ;
		use_fork(0, philo);
		if (philo->left_fork_use)
			use_fork(1, philo);
		if (philo->right_fork_use && philo->left_fork_use)
		{
			write_status("is eating", philo);
			stay(philo->param->time_to_eat);
			philo->n_eat += 1;
			pthread_mutex_lock(&(philo->m_last_eat));
			philo->last_eat = get_time() - philo->param->time;
			pthread_mutex_unlock(&(philo->m_last_eat));
			stop_use_fork(0, philo);
			stop_use_fork(1, philo);
			write_status("is sleeping", philo);
			stay(philo->param->time_to_sleep);
		}
	}
	return (0);
}

void	*check_life();
