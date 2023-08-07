/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:29:50 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/07 06:24:05 by mbazirea         ###   ########.fr       */
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
	if (init_thread(&philo, &param) == 1)
		return (1);
	if (stay_philo_end(&philo, &param))
		return (1);
	return (0);
}
