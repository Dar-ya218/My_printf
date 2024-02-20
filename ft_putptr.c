/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:46:04 by dabochko          #+#    #+#             */
/*   Updated: 2024/02/20 14:47:48 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*La función ft_putptr convierte el puntero a un valor de tipo
unsigned long, luego imprime "0x" seguido del valor del puntero
en hexadecimal.*/
void	ft_putptr(void *p)
{
	unsigned long ptr_val = (unsigned long)p;
	ft_putstr("0x");
	ft_puthex_upper(ptr_val);
}
