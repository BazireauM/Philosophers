/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:36:43 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/09 06:29:42 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

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
	long			time;
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

//	main.c
void	free_philo_fork(t_philo *philo, t_fork *fork);
int		stop_thread(t_philo *philo);

//	init_all.c
int		init_param(t_param *param, int argc, char *argv[]);
int		init_philo(t_param *param, t_philo **philo, t_fork **fork);
int		init_philo_param(t_param *param, t_fork **fork, t_philo **philo);

//	thread.c
int		init_thread(t_philo **philo, t_param *param);
void	*life(void *phil);
void	life2(t_philo *philo);
void	*check_life(void *phil);
int		check_life2(t_philo *philo, long time);

//	thread_2.c
int		stay_philo_end(t_philo **philo, t_param *param);

//	utils.c
long	get_time(void);
int		ft_atoi(const char *s);
void	stay(long int time);
int		test_death_philo(t_philo *philo);
void	write_status(char *s, t_philo *philo);

//	utils_2.c
void	use_fork(int id, t_philo *philo);
void	stop_use_fork(int id, t_philo *philo);
int		all_eat(t_param *param, t_philo **philo);

#endif
