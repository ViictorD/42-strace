/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:39:33 by vdarmaya          #+#    #+#             */
/*   Updated: 2019/05/07 15:39:35 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strace.h"

static int	excract_nth_path(char ret[512], char *path, int *index)
{
	int i;

	if (*index > strlen(path))
		return (0);
	for (i = 0; path[*index] && path[*index] != ':' && i < 512; (*index)++, i++)
		ret[i] = path[*index];
	ret[i] = 0;
	(*index)++;
	return (1);
}

int		get_complete_path(char ret[1024], const char *filename)
{
	char	cpath[1024];
	int		index;
	char	*path;

	if (strlen(filename) > 512)
		return (-1);
	if (access(filename, X_OK) == 0)
	{
		strcpy(ret, filename);
		return (1);
	}
	path = getenv("PATH");
	if (path == NULL)
		return (-1);
	index = 0;
	for (;excract_nth_path(cpath, path, &index);)
	{
		strcat(strcat(strcpy(ret, cpath), "/"), filename);
		if (access(ret, X_OK) == 0)
			return (1);
	}
	return (-1);
}