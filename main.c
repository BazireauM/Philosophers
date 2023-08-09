/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:29:50 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/09 06:40:48 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	main(int argc, char *argv[])
{
	t_param	param;
	t_philo	*philo;
	t_fork	*fork;
	int		r;

	philo = NULL;
	fork = NULL;
	r = 0;
	if (init_param(&param, argc, argv) == 1)
		return (1);
	if (init_philo(&param, &philo, &fork) == 1)
		return (1);
	if (init_thread(&philo, &param) == 1)
	{
		stop_thread(&philo[0]);
		r = 1;
	}
	if (stay_philo_end(&philo, &param))
	{
		free_philo_fork(philo, fork);
		return (1);
	}
	free_philo_fork(philo, fork);
	return (r);
}

void	free_philo_fork(t_philo *philo, t_fork *fork)
{
	free(philo);
	free(fork);
}

int	stop_thread(t_philo *philo)
{
	pthread_mutex_lock(&(philo->param->m_dead));
	philo->param->dead = 1;
	pthread_mutex_unlock(&(philo->param->m_dead));
	return (1);
}
