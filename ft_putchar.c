/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:18:51 by dabochko          #+#    #+#             */
/*   Updated: 2024/02/20 15:56:39 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*toma un carácter c como argumento y lo escribe en la salida estándar
utilizando la función write(). write(1, &c, 1) escribe un solo carácter
(&c) en el descriptor de archivo 1 (que es la salida estándar).*/
int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
