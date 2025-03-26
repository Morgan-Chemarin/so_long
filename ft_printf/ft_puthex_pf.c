/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemari <mchemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:15:58 by mchemari          #+#    #+#             */
/*   Updated: 2024/11/20 11:40:10 by mchemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_maj_pf(unsigned int num, size_t *caracters)
{
	char	*nbr_hex;

	nbr_hex = "0123456789ABCDEF";
	if (num >= 16)
		ft_puthex_maj_pf(num / 16, caracters);
	ft_putchar_pf(nbr_hex[num % 16], caracters);
}

void	ft_puthex_pf(unsigned int num, size_t *caracters)
{
	char	*nbr_hex;

	nbr_hex = "0123456789abcdef";
	if (num >= 16)
		ft_puthex_pf(num / 16, caracters);
	ft_putchar_pf(nbr_hex[num % 16], caracters);
}

void	ft_puthex_ptr_pf(unsigned long num, size_t *caracters)
{
	char	*hex_digits;

	hex_digits = "0123456789abcdef";
	if (num >= 16)
	{
		ft_puthex_ptr_pf(num / 16, caracters);
		ft_puthex_ptr_pf(num % 16, caracters);
	}
	else
		ft_putchar_pf(hex_digits[num], caracters);
}

//arg nbr_hex

void	ft_putptr_pf(void *ptr, size_t *caracters)
{
	unsigned long	address;

	if (!ptr)
	{
		ft_putstr_pf("(nil)", caracters);
		return ;
	}
	address = (unsigned long)ptr;
	ft_putstr_pf("0x", caracters);
	ft_puthex_ptr_pf(address, caracters);
}
