/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemari <mchemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:51:46 by mchemari          #+#    #+#             */
/*   Updated: 2024/11/20 11:40:53 by mchemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_pf(char *s, size_t *caracteres)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*caracteres += 6;
	}
	else
	{
		write(1, s, ft_strlen(s));
		*caracteres += ft_strlen(s);
	}
}
