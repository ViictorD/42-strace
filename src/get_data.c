/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:06:21 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/20 19:33:23 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strace.h>

long get_word(pid_t pid, long w)
{
	long data;

	// Must be world-aligned
	data = ptrace(PTRACE_PEEKUSER, pid, sizeof(long) * w, NULL);
	if (data == -1)
		exit(-1);
	return (data);
}
