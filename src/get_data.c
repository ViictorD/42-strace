/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:06:21 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/21 18:19:10 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strace.h>

static const int registers[256] =  { RDI, RSI, RDX, RCX, R8, R9 };

long get_word_user(pid_t pid, long w)
{
	long data;

	// Must be world-aligned
	data = ptrace(PTRACE_PEEKUSER, pid, sizeof(long) * w, NULL);
	if (data == -1)
		printf("MDR\n", );
	return (data);
}

void *get_data_value(pid_t pid, type type, long value)
{
	return ((void*)value);
}

void get_args(pid_t pid, long id, void  **out)
{
	t_info		info;
	long		data;
	int i;

	info = get_info(id);
	for (i = 0; i < info.arg_num; i++)
	{
		data = get_word_user(pid, registers[i]);
		out[i] = get_data_value(pid, info.args_type[i], data);
	}
}
