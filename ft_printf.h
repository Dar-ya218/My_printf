/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:54:13 by dabochko          #+#    #+#             */
/*   Updated: 2024/03/07 16:08:46 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned int n, char const place);
int	ft_putptr(unsigned long ptr);
int	ptr_size(unsigned long n);

#endif
