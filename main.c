/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:29:50 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/06 04:19:23 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int	main(int argc, char *argv[])
{
	t_param	param;
	t_philo	*philo;
	t_fork	*fork;

	philo = NULL;
	fork = NULL;
	if (init_param(&param, argc, argv) == 1)
		return (1);
	if (init_philo(&param, &philo, &fork) == 1)
		return (1);
	if (init_thread(&philo) == 1)
		return (1);
	printf("%d\n", param.number_of_philosopher);
	printf("%d\n", param.time_to_die);
	printf("%d\n", param.time_to_eat);
	printf("%d\n", param.time_to_sleep);
	if (argc == 6)
		printf("%d\n", param.max_eat);
	printf("%d\n", philo[0].right_fork->use);
	printf("%ld\n", param.time);
	return (0);
}
