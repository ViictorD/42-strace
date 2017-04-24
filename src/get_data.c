/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:06:21 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/24 13:23:18 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strace.h>

static const int registers[256] =  { RDI, RSI, RDX, RCX, R8, R9 };

long get_word_user(pid_t pid, long w)
{
	long data;

	// Must be world-aligned
	data = ptrace(PTRACE_PEEKUSER, pid, sizeof(long) * w, NULL);
	return (data);
}

long get_word(pid_t pid, long w)
{
	long data;

	data = ptrace(PTRACE_PEEKDATA, pid, w, NULL);
	return (data);
}

char *get_string(pid_t pid, long addr)
{
	long data;
	char *string;
	unsigned i;
	int j;
	int next;

	string = (char *)malloc(sizeof(char) * (256 * 4 + 1));
	string[0] = 0;
	for (i = 0; i < 256; i++)
	{
		data = get_word(pid, addr + i * 4);
		memcpy(&string[i * 4], &data, sizeof(long));
		for (j = 0; j < sizeof(long) / 8; j++)
			if (&((char*)data)[j] == '\0')
				break ;
	}
	return (string);
}

void *get_data_value(pid_t pid, type type, long value)
{
	if (type == string_)
		return (get_string(pid, value));
	return ((void*)value);
}

void get_args(pid_t pid, long id, void  **out)
{
	t_info		info;
	long		data;
	int			i;

	info = get_info(id);
	for (i = 0; i < info.arg_num; i++)
	{
		out[i] == NULL;
		data = get_word_user(pid, registers[i]);
		out[i] = get_data_value(pid, info.args_type[i], data);
	}
}
