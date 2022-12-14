/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:01:11 by edelage           #+#    #+#             */
/*   Updated: 2022/09/03 17:30:56 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	main(void)
{
	size_t	width;
	size_t	height;
	size_t	gen;
	t_cell	**grid;

	size_terminal(&width, &height);
	grid = random_map(width, height);
	if (grid == NULL || width < 25)
		return (1);
	write(STDOUT_FILENO, "\e[1;1H\e[2J", 11);
	display_screen(grid, 0, 1, width);
	gen = 1;
	usleep(TIME2GEN);
	write(STDOUT_FILENO, "\e[1;1H\e[2J", 11);
	while (gen <= NB_GEN)
	{
		grid = next_grid(grid, width, height);
		if (grid == NULL)
			return (1);
		display_screen(grid, gen, 1, width);
		usleep(TIME2GEN);
		if (gen != NB_GEN)
			write(STDOUT_FILENO, "\e[1;1H\e[2J", 11);
		gen++;
	}
	free_grid(grid, height);
	return (0);
}
