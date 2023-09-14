/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:26:25 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/06 05:23:32 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	get_time(void)
{
	long			a;
	struct timeval	time;

	gettimeofday(&time, NULL);
	a = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (a);
}

int	ft_atoi(const char *s)
{
	int	i;
	int	mul;
	int	final;

	i = 0;
	mul = 1;
	final = 0;
	while (s[i] != '\0' && (s[i] == '\f' || s[i] == '\r' || s[i] == ' '
			|| s[i] == '\t' || s[i] == '\v' || s[i] == '\n'))
		i++;
	if (s[i] == '-')
	{
		mul = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		final = final * 10 + s[i] - 48;
		i++;
	}
	final *= mul;
	return (final);
}

void	stay(long int time)
{
	long int	time2;

	time2 = get_time();
	while ((get_time() - time2) < time)
		usleep(100);
}

int	test_death_philo(t_philo *philo)
{
	int	i;

	pthread_mutex_lock(&(philo->param->m_dead));
	i = philo->param->dead;
	pthread_mutex_unlock(&(philo->param->m_dead));
	return (i);
}

void	write_status(char *s, t_philo *philo)
{
	long	i;

	i = get_time() - philo->param->time;
	pthread_mutex_lock(&(philo->param->m_log));
	if (!test_death_philo(philo))
		printf("%09ld %d %s\n", i, philo->id + 1, s);
	pthread_mutex_unlock(&(philo->param->m_log));
}
