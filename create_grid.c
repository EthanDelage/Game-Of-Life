/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:42:25 by edelage           #+#    #+#             */
/*   Updated: 2022/09/03 13:14:46 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <time.h>
#include "libft.h"

t_cell	**create_grid(size_t width, size_t height)
{
	size_t	line;
	size_t	column;
	t_cell	**grid;

	line = 0;
	grid = (t_cell **) malloc(sizeof(t_cell *) * (height + 1));
	if (grid == NULL)
		return (NULL);
	while (line < height)
	{
		column = 0;
		grid[line] = (t_cell *) malloc(sizeof(t_cell) * (width + 1));
		if (grid[line] == NULL)
			return (NULL);
		while (column < width)
		{
			grid[line][column].x = column;
			grid[line][column].y = line;
			grid[line][column].status = DEAD;
			column++;
		}
		grid[line][column].status = '\0';
		line++;
	}
	grid[line] = (t_cell *) malloc(sizeof(t_cell) * 1);
	grid[line]->status = '\0';
	return (grid);
}

t_cell	**random_map(size_t width, size_t height)
{
	size_t	column;
	size_t	row;
	t_cell	**grid;

	column = 0;
	row = 0;
	srand(time(NULL));
	grid = create_grid(width, height);
	if (grid == NULL)
		return (NULL);
	while (row < height)
	{
		column = 0;
		while (column < width)
		{
			if (rand() % DENSITY == 0)
				grid[row][column].status = ALIVE;
			column++;
		}
		row++;
	}
	return (grid);
}
