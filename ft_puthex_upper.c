/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:42:14 by dabochko          #+#    #+#             */
/*   Updated: 2024/02/20 14:44:05 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#includo "ft_printf.h"
/*It prints a number in hexadecimal format. This function works similarly
to ft_putnbr(), but instead of dividing and taking the modulus by 10, it
divides and takes the modulus by 16, and then uses the result to index
into a string of hexadecimal digits. If n is greater than or equal to 16,
it makes a recursive call to ft_puthex(n / 16) to print the most significant
digits. Then, it prints the least significant digit.*/
void	ft_puthex_upper(unsigned int n)
{
	char *hexDigits = "0123456789ABCDEF";

	if (n >= 16)
		ft_puthex_upper(n / 16);
	ft_putchar(hexDigits[n % 16]);
}
