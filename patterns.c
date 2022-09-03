/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 22:58:27 by edelage           #+#    #+#             */
/*   Updated: 2022/09/02 23:24:55 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	glider(t_cell **grid, size_t column, size_t line)
{
	grid[line + 2][column].status = ALIVE;
	grid[line + 2][column + 1].status = ALIVE;
	grid[line + 2][column + 2].status = ALIVE;
	grid[line + 1][column + 2].status = ALIVE;
	grid[line][column + 1].status = ALIVE;
}

void	boat(t_cell **grid, size_t column, size_t line)
{
	grid[line][column].status = ALIVE;
	grid[line + 1][column].status = ALIVE;
	grid[line][column + 1].status = ALIVE;
	grid[line + 1][column + 2].status = ALIVE;
	grid[line + 2][column + 1].status = ALIVE;
}

void	spaceship(t_cell **grid, size_t column, size_t line)
{
	grid[line + 1][column].status = ALIVE;
	grid[line + 3][column].status = ALIVE;
	grid[line][column + 1].status = ALIVE;
	grid[line][column + 2].status = ALIVE;
	grid[line][column + 3].status = ALIVE;
	grid[line][column + 4].status = ALIVE;
	grid[line + 1][column + 4].status = ALIVE;
	grid[line + 2][column + 4].status = ALIVE;
	grid[line + 3][column + 3].status = ALIVE;
}

void	blinker(t_cell **grid, size_t column, size_t line)
{
	grid[line + 1][column].status = ALIVE;
	grid[line + 1][column + 1].status = ALIVE;
	grid[line + 1][column + 2].status = ALIVE;
}
