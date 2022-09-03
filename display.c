/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:18:39 by edelage           #+#    #+#             */
/*   Updated: 2022/09/03 15:28:20 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	display_grid(t_cell **grid)
{
	size_t	line;
	size_t	column;

	line = 0;
	while (grid[line]->status)
	{
		column = 0;
		while (grid[line][column].status)
		{
			write(1, &(grid[line][column].status), 1);
			column++;
		}
		write(1, "\n", 1);
		line++;
	}
}

void	display_line(size_t width)
{
	size_t	column;

	column = 0;
	while (column < width)
	{
		write(1, "_", 1);
		column++;
	}
}

void	display_footer(size_t gen, size_t nb_cell, size_t width)
{
	size_t	column;

	column = 0;
	display_line(width);
	write(1, "\n\nGen: ", 7);
	column = 5 + ft_putnbr(gen);
	while (column < width / 4)
	{
		write(1, " ", 1);
		column++;
	}
	write(1, "| Cells: ", 9);
	column += ft_putnbr(nb_cell);
	write(1, "\n", 1);
	column = 0;
	display_line(width);
}

void	display_screen(t_cell **grid, size_t gen, size_t nb_cell, size_t width)
{
	display_grid(grid);
	display_footer(gen, nb_cell, width);
}
