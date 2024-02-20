/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:31:30 by dabochko          #+#    #+#             */
/*   Updated: 2024/02/20 14:41:22 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*toma un número entero n como argumento y lo escribe en la salida
estándar como una cadena de caracteres. Si n es negativo, escribe
un guión y cambia n a positivo. Luego, si n es mayor que 9, llama
a ft_putnbr(n / 10) recursivamente para escribir los dígitos más
significativos. Finalmente, escribe el dígito menos significativo
de n utilizando ft_putchar().*/
void	ft_putnbr(int n)
{
	if (n == INT_MIN)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
