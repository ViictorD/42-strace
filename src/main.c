/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:26:48 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/19 20:22:19 by rcargou          ###   ########.fr       */
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
	get_complete_path(ret, a[1]);
	exec_trace(ret, env)
	return (0);
}

