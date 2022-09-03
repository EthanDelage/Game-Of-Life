/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:32:57 by edelage           #+#    #+#             */
/*   Updated: 2022/09/03 15:57:08 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define DEAD		'.'
# define ALIVE		'O'
# define TIME2GEN	200000
# define DENSITY	10
# include <unistd.h>
# include <stdlib.h>

typedef struct s_cell	t_cell;
struct s_cell
{
	size_t		x;
	size_t		y;
	char		status;
};

t_cell	**random_map(size_t width, size_t height);
void	size_terminal(size_t *width, size_t *height);
t_cell	**create_grid(size_t width, size_t height);
t_cell	**next_grid(t_cell **previous_grid, size_t width, size_t height);
void	free_grid(t_cell **grid, size_t height);
void	display_screen(t_cell **grid, size_t gen, size_t nb_cell, size_t width);
size_t	ft_putnbr(size_t nb);
/*--- Patterns ---*/
void	glider(t_cell **grid, size_t column, size_t line);
void	boat(t_cell **grid, size_t column, size_t line);
void	spaceship(t_cell **grid, size_t column, size_t line);
void	blinker(t_cell **grid, size_t column, size_t line);

#endif
