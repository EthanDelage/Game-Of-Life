/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:43:46 by edelage           #+#    #+#             */
/*   Updated: 2022/09/03 15:47:36 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/ioctl.h>
#include "libft.h"

void	size_terminal(size_t *width, size_t *height)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	*width = w.ws_col;
	*height = w.ws_row - 5;
}

size_t	count_neighbour(t_cell **grid, t_cell cell, size_t width, size_t height)
{
	size_t	neighbour;

	neighbour = 0;
	if (cell.x > 0 && grid[cell.y][cell.x - 1].status == ALIVE)
		neighbour++;
	if (cell.x < (width - 1) && grid[cell.y][cell.x + 1].status == ALIVE)
		neighbour++;
	if (cell.y > 0 && grid[cell.y - 1][cell.x].status == ALIVE)
		neighbour++;
	if (cell.y < (height - 1) && grid[cell.y + 1][cell.x].status == ALIVE)
		neighbour++;
	if (cell.x > 0 && cell.y > 0
		&& grid[cell.y - 1][cell.x - 1].status == ALIVE)
		neighbour++;
	if (cell.x < (width - 1) && cell.y > 0
		&& grid[cell.y - 1][cell.x + 1].status == ALIVE)
		neighbour++;
	if (cell.x > 0 && cell.y < (height - 1)
		&& grid[cell.y + 1][cell.x - 1].status == ALIVE)
		neighbour++;
	if (cell.x < (width - 1) && cell.y < (height - 1)
		&& grid[cell.y + 1][cell.x + 1].status == ALIVE)
		neighbour++;
	return (neighbour);
}

char	behavior_cell(t_cell **grid, t_cell cell, size_t width, size_t height)
{
	size_t	neighbour;

	neighbour = count_neighbour(grid, cell, width, height);
	if (cell.status == ALIVE)
	{
		if (neighbour < 2)
			return (DEAD);
		else if (neighbour > 3)
			return (DEAD);
		else
			return (ALIVE);
	}
	else
	{
		if (neighbour == 3)
			return (ALIVE);
		else
			return (DEAD);
	}
}

t_cell	**next_grid(t_cell **previous_grid, size_t width, size_t height)
{
	size_t	line;
	size_t	column;
	t_cell	**new_grid;

	line = 0;
	column = 0;
	new_grid = create_grid(width, height);
	if (new_grid == NULL)
		return (NULL);
	while (new_grid[line]->status)
	{
		column = 0;
		while (new_grid[line][column].status)
		{
			new_grid[line][column].x = column;
			new_grid[line][column].y = line;
			new_grid[line][column].status = behavior_cell(previous_grid,
					previous_grid[line][column], width, height);
			column++;
		}
		line++;
	}
	free_grid(previous_grid, height);
	return (new_grid);
}
