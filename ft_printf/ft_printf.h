/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemari <mchemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:26:35 by mchemari          #+#    #+#             */
/*   Updated: 2024/11/20 11:38:37 by mchemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *str, ...);
void	ft_putchar_pf(char c, size_t *caracteres);
void	ft_putnbr_pf(int n, size_t *caracteres);
void	ft_putstr_pf(char *s, size_t *caracteres);
void	ft_puthex_pf(unsigned int num, size_t *caracters);
void	ft_puthex_maj_pf(unsigned int num, size_t *caracters);
void	ft_putptr_pf(void *ptr, size_t *caracters);
int		ft_strlen(char *s);
void	ft_unsigned_pf(unsigned int n, size_t *caracteres);

#endif
