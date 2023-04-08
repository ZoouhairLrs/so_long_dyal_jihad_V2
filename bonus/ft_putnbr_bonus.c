/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlaarous <zlaarous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 06:56:57 by zlaarous          #+#    #+#             */
/*   Updated: 2023/04/08 00:21:19 by zlaarous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{	
		write(1, "-2147483648", 11);
	}
	else if (n >= 0 && n <= 9)
	{
		c = n + 48;
		ft_putchar(c);

	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr (-n);
	}
	else if (n > 0)
	{
		ft_putnbr (n / 10);
		ft_putnbr (n % 10);
	}
}
