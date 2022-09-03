/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:37:08 by edelage           #+#    #+#             */
/*   Updated: 2022/09/03 15:40:53 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	free_grid(t_cell **grid, size_t height)
{
	size_t	line;

	line = 0;
	while (line <= height)
	{
		free(grid[line]);
		line++;
	}
	free(grid);
}
