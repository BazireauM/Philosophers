/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 06:17:59 by mbazirea          #+#    #+#             */
/*   Updated: 2023/08/07 06:47:49 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	stay_philo_end(t_philo **philo, t_param *param)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (i < param->number_of_philosopher)
	{
		if (pthread_join((*philo)[i].t_philo, NULL))
			r = 1;
		i++;
	}
	return (r);
}
