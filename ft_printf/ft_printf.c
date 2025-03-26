/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemari <mchemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:10:56 by mchemari          #+#    #+#             */
/*   Updated: 2024/11/20 11:38:26 by mchemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_param(char specifier, va_list param, size_t *caracters)
{
	if (specifier == 'c')
		ft_putchar_pf((char)va_arg(param, int), caracters);
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr_pf((int)va_arg(param, int), caracters);
	else if (specifier == 's')
		ft_putstr_pf((char *)va_arg(param, char *), caracters);
	else if (specifier == 'X')
		ft_puthex_maj_pf((unsigned int)va_arg(param, unsigned int), caracters);
	else if (specifier == 'x')
		ft_puthex_pf((unsigned int)va_arg(param, unsigned int), caracters);
	else if (specifier == '%')
		ft_putchar_pf('%', caracters);
	else if (specifier == 'p')
		ft_putptr_pf(va_arg(param, void *), caracters);
	else if (specifier == 'u')
		ft_unsigned_pf((unsigned int)va_arg(param, unsigned int), caracters);
}

int	ft_printf(const char *str, ...)
{
	va_list	param;
	size_t	caracters;
	size_t	i;

	va_start(param, str);
	caracters = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			print_param(str[i + 1], param, &caracters);
			i++;
		}
		else
			ft_putchar_pf(str[i], &caracters);
		i++;
	}
	va_end(param);
	return (caracters);
}

// int main()
// {
// 	// printf("%d\n",145, 'c', 1000, "test");
// 	// printf("%d",ft_printf("Salut %s, %d 22 : ", "Morgan", 20));
// 	// int x = 42;

// 	// printf(" : %d",ft_printf("%x, %X, %%, %u", 648525, 648525, -12));
// 	printf(" : %d", printf("%p\n", -2147483648));
// 	ft_printf(" : %d", ft_printf("%p", -2147483648));
// }