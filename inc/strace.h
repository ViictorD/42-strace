/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strace.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcargou <rcargou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:51:43 by rcargou           #+#    #+#             */
/*   Updated: 2017/04/19 20:25:52 by rcargou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRACE_H
# define STRACE_H

# include <sys/types.h>
# include <sys/ptrace.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
#include <signal.h>

int		get_complete_path(char ret[1024], const char *filename);
void	exec_trace(char *path, char **av, char **env);

#endif
