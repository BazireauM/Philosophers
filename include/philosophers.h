/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:36:43 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/05 04:31:05 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

typedef struct s_fork
{
	int				use;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_param
{
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	int				dead;
	pthread_mutex_t	m_log;
	pthread_mutex_t	m_dead;
	pthread_t		t_death;
}	t_param;

typedef struct s_philo
{
	t_param			*param;
	int				id;
	int				n_eat;
	int				right_fork_use;
	int				left_fork_use;
	long			last_eat;
	t_fork			*right_fork;
	t_fork			*left_fork;
	pthread_mutex_t	m_last_eat;
	pthread_t		t_philo;
}	t_philo;

//	init_all.c
int	init_param(t_param *param, int argc, char *argv[]);
int	init_philo(t_param *param, t_philo **philo, t_fork **fork);
int	init_philo_param(t_param *param, t_fork **fork, t_philo **philo);

//	utils.c
int	ft_atoi(const char *s);

#endif
