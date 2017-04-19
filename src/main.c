/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:26:48 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/19 21:07:00 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strace.h>

int main(int ac, char **av, char **env)
{
	char ret[1024];

	if (ac < 2)
	{
		printf("fdp\n");
		return (-1);
	}
	if (get_complete_path(ret, av[1]) < 0)
	{
		printf("fdp\n");
		return (-1);
	}
	exec_trace(ret, av + 1, env);
	return (0);
}

