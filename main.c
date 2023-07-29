/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbazirea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:29:50 by mbazirea          #+#    #+#             */
/*   Updated: 2023/07/29 23:35:27 by mbazirea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

int main(int argc, char *argv[])
{
	t_param	param;

	if (init_param(&param, argc, argv) == 1)
		return (1);
	printf("%d\n", param.number_of_philosopher);
	printf("%d\n", param.time_to_die);
	printf("%d\n", param.time_to_eat);
	printf("%d\n", param.time_to_sleep);
	if (argc == 6)
		printf("%d\n", param.max_eat);
	return (0);
}
