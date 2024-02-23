/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:31:30 by dabochko          #+#    #+#             */
/*   Updated: 2024/02/22 13:00:33 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*toma un número entero n como argumento y lo escribe en la salida
estándar como una cadena de caracteres. Si n es negativo, escribe
un guión y cambia n a positivo. Luego, si n es mayor que 9, llama
a ft_putnbr(n / 10) recursivamente para escribir los dígitos más
significativos. Finalmente, escribe el dígito menos significativo
de n utilizando ft_putchar().*/
static int	ft_size(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int size;

	size = ft_size(n);
	if (n == 0)
		return(ft_putchar('0'));
	if (n == INT_MIN)
		return(ft_putstr("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	return (size);
}
