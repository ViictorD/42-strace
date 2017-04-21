/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 16:26:53 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/21 16:48:50 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strace.h>

void print_arg(type type, void *value)
{
	fprintf(stderr, "%d, ", (int)value);
}

void display_syscall(long id, void **args)
{
	t_info info;
	int i;
	info = get_info(id);
	fprintf(stderr, "%s ", info.name);
	for (i = 0; i < info.arg_num; i++)
		print_arg(info.args_type[i], args[i]);
	fprintf(stderr, "\n");
}