/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:36:43 by mbazirea          #+#    #+#             */
/*   Updated: 2023/07/29 23:51:53 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_param
{
	int	number_of_philosopher;
	int time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int max_eat;
	int	dead;
}	t_param;

//	init_all.c
int	init_param(t_param *param, int argc, char *argv[]);

//	utils.c
int	ft_atoi(const char *s);

#endif

