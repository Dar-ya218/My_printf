/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:18:51 by dabochko          #+#    #+#             */
/*   Updated: 2024/03/07 14:12:21 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*It takes a character 'c' as an argument and writes it to the standard output
using the 'write()' function. 'write(1, &c, 1)' writes a single character
(&c) to file descriptor 1 (which is the standard output).*/
int	ft_putchar(int c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}
