/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelage <edelage@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 14:29:00 by edelage           #+#    #+#             */
/*   Updated: 2022/09/03 15:11:53 by edelage          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

size_t	ft_putnbr(size_t nb)
{
	size_t	count;

	count = 0;
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
		return (count + 1);
	}
	else
	{
		ft_putchar(nb + '0');
		return (count + 1);
	}
}
