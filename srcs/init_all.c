/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:07:25 by mbazirea          #+#    #+#             */
/*   Updated: 2023/07/29 23:51:51 by mbazirea         ###   ########.fr       */
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
	if (argc == 6)
	{
		if (ft_atoi(argv[5]) < 0)
			return (1);
		param->max_eat = ft_atoi(argv[5]);
	}
	param->dead = 0;
	return (0);
}
