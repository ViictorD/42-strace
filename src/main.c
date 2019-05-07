/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:39:27 by vdarmaya          #+#    #+#             */
/*   Updated: 2019/05/07 15:39:28 by vdarmaya         ###   ########.fr       */
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

