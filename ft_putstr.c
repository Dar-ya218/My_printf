/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:28:00 by dabochko          #+#    #+#             */
/*   Updated: 2024/02/20 14:29:32 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*toma una cadena de caracteres s como argumento y la escribe en la
salida estándar carácter por carácter utilizando la función ft_putchar().
El bucle while (*s) se ejecuta hasta que se encuentra el carácter nulo
que marca el final de la cadena.*/
void	ft_putstr(char *s)
{
	while (*s)
		ft_putchar(*s++);
}
