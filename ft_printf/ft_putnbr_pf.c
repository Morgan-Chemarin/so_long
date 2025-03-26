/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemari <mchemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:44:57 by mchemari          #+#    #+#             */
/*   Updated: 2024/11/20 11:38:34 by mchemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int n, size_t *caracteres)
{
	int	a;
	int	b;

	if (n == -2147483648)
	{
		ft_putchar_pf('-', caracteres);
		ft_putnbr_pf(21, caracteres);
		ft_putnbr_pf(47483648, caracteres);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_pf('-', caracteres);
	}
	if (n > 9)
	{
		a = n % 10;
		b = n / 10;
		ft_putnbr_pf(b, caracteres);
		ft_putchar_pf(a + 48, caracteres);
	}
	else
		ft_putchar_pf(n + 48, caracteres);
}

void	ft_unsigned_pf(unsigned int n, size_t *caracteres)
{
	unsigned int	a;
	unsigned int	b;

	if (n > 9)
	{
		a = n % 10;
		b = n / 10;
		ft_unsigned_pf(b, caracteres);
		ft_putchar_pf(a + 48, caracteres);
	}
	else
		ft_putchar_pf(n + 48, caracteres);
}
