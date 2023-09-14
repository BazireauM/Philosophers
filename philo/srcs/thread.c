/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 03:52:37 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/07 06:24:22 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	init_thread(t_philo **philo, t_param *param)
{
	int	i;

	i = 0;
	param->time = get_time();
	while (i < param->number_of_philosopher)
	{
		if (pthread_create(&((*philo)[i].t_philo), NULL, life, &((*philo)[i])))
			return (1);
		i++;
	}
	if (pthread_create(&(param->t_death), NULL, check_life, philo))
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
			life2(philo);
	}
	return (0);
}

void	life2(t_philo *philo)
{
	write_status("is eating", philo);
	stay(philo->param->time_to_eat);
	pthread_mutex_lock(&(philo->m_last_eat));
	philo->n_eat += 1;
	pthread_mutex_unlock(&(philo->m_last_eat));
	pthread_mutex_lock(&(philo->m_last_eat));
	philo->last_eat = get_time() - philo->param->time;
	pthread_mutex_unlock(&(philo->m_last_eat));
	stop_use_fork(0, philo);
	stop_use_fork(1, philo);
	write_status("is sleeping", philo);
	stay(philo->param->time_to_sleep);
	write_status("is thinking", philo);
	if (philo->param->time_to_die - (philo->param->time_to_eat + philo->param->time_to_sleep) > 0)
		usleep((philo->param->time_to_die - (philo->param->time_to_eat + philo->param->time_to_sleep)) / 3);
}

void	*check_life(void *phil)
{
	t_param	*param;
	t_philo	**philo;
	long	time;
	int		i;

	philo = (t_philo **)phil;
	param = philo[0]->param;
	while (42)
	{
		i = 0;
		time = get_time() - param->time;
		while (i < param->number_of_philosopher)
		{
			if (check_life2(&(*philo)[i], time))
				return (NULL);
			i++;
		}
		if (all_eat(param, philo))
			return (NULL);
		stay(1);
	}
	return (NULL);
}

int	check_life2(t_philo *philo, long time)
{
	int	dead;
	int	last_eat;

	dead = 0;
	pthread_mutex_lock(&(philo->m_last_eat));
	last_eat = time - philo->last_eat;
	pthread_mutex_unlock(&(philo->m_last_eat));
	if (last_eat > philo->param->time_to_die && !(philo->param->max_eat != -42 && philo->n_eat >= philo->param->max_eat))
	{
		pthread_mutex_lock(&(philo->param->m_log));
		pthread_mutex_lock(&(philo->param->m_dead));
		philo->param->dead = 1;
		pthread_mutex_unlock(&(philo->param->m_dead));
		printf("%09ld %d died\n", time, philo->id + 1);
		pthread_mutex_unlock(&(philo->param->m_log));
		dead = 1;
	}
	return (dead);
}
