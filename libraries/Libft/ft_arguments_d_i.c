/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arguments_d_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:27:18 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/01/10 17:27:23 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(int nbr)
{
	int	sum;

	sum = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		if (nbr == -2147483648)
		{
			nbr--;
			sum = 1;
		}
	}
	if (nbr < 10)
		ft_putchar_fd(nbr + 48 + sum, 1);
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10 + sum);
	}
}

int	ft_arguments_d_i(int c)
{
	ft_putnbr(c);
	return (ft_decimal_length(c));
}
