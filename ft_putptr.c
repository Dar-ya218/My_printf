/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:46:04 by dabochko          #+#    #+#             */
/*   Updated: 2024/03/01 15:37:55 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*La función ft_putptr convierte el puntero a un valor de tipo
unsigned long, luego imprime "0x" seguido del valor del puntero
en hexadecimal.*/
int	ft_putptr(unsigned long ptr)
{
	int	size;
	char *hex;

    size = ptr_size(ptr);
    hex = "0123456789abcdef";
    if (ptr == 0)
        return (ft_putchar('0'));
    if (ptr >= 16)
        ft_putptr(ptr / 16);
    ft_putchar(hex[ptr % 16]);
    return (size);
}

int  ptr_size(unsigned long n)
{
    int i;

    i = 0;
    while (n > 0)
    {
        n = n / 16;
        i++;
    }
    return (i);
}
