/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:35:26 by dabochko          #+#    #+#             */
/*   Updated: 2024/02/20 14:40:36 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*debe imprimir un número entero sin signo????
la llamada recursiva se utiliza para imprimir los dígitos de un
número uno por uno. Si el número es mayor o igual a 10, la función
se llama a sí misma con el número dividido por 10. Esto efectivamente
"descarta" el último dígito del número. Luego, imprime el último
dígito del número original.*/
void	ft_putunbr(unsigned int n)
{
	if (n >= 10)
		ft_putunbr(n / 10);
	ft_putchar((n % 10) + '0');
}
