/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:28:00 by dabochko          #+#    #+#             */
/*   Updated: 2024/02/21 12:18:22 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*toma una cadena de caracteres s como argumento y la escribe en la
salida estándar carácter por carácter utilizando la función ft_putchar().
El bucle while (*s) se ejecuta hasta que se encuentra el carácter nulo
que marca el final de la cadena.*/
int	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return(ft_putstr("null"));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
