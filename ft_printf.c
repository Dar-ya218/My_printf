/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:10:23 by dabochko          #+#    #+#             */
/*   Updated: 2024/02/20 13:17:23 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/*toma un carácter c como argumento y lo escribe en la salida estándar 
utilizando la función write(). write(1, &c, 1) escribe un solo carácter 
(&c) en el descriptor de archivo 1 (que es la salida estándar).*/
void ft_putchar(char c) {
    write(1, &c, 1);
}

/*toma una cadena de caracteres s como argumento y la escribe en la 
salida estándar carácter por carácter utilizando la función ft_putchar().
El bucle while (*s) se ejecuta hasta que se encuentra el carácter nulo
que marca el final de la cadena.*/
void ft_putstr(char *s) {
    while (*s)
        ft_putchar(*s++);
}

/*toma un número entero n como argumento y lo escribe en la salida 
estándar como una cadena de caracteres. Si n es negativo, escribe 
un guión y cambia n a positivo. Luego, si n es mayor que 9, llama 
a ft_putnbr(n / 10) recursivamente para escribir los dígitos más 
significativos. Finalmente, escribe el dígito menos significativo 
de n utilizando ft_putchar().*/
void ft_putnbr(int n) {
	if (n == INT_MIN) {
        ft_putstr("-2147483648");
        return;
    }
    if (n < 0) {
        ft_putchar('-');
        n = -n;
    }
    if (n > 9)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

/*debe imprimir un número entero sin signo????
la llamada recursiva se utiliza para imprimir los dígitos de un 
número uno por uno. Si el número es mayor o igual a 10, la función
se llama a sí misma con el número dividido por 10. Esto efectivamente
"descarta" el último dígito del número. Luego, imprime el último 
dígito del número original.*/
void ft_putunbr(unsigned int n) {
    if (n >= 10)
        ft_putunbr(n / 10);
    ft_putchar((n % 10) + '0');
}


/*imprime un número en formato hexadecimal
Esta función funciona de manera similar a ft_putnbr(), pero en
lugar de dividir y tomar el módulo por 10, divide y toma el
módulo por 16, y luego usa el resultado para indexar en una
cadena de dígitos hexadecimales. Si n es mayor o igual a 16,
hace una llamada recursiva a ft_puthex(n / 16) para imprimir
los dígitos más significativos. Luego, imprime el dígito menos
significativo*/
void ft_puthex(unsigned int n) {
    char *hexDigits = "0123456789abcdef";

    if (n >= 16)
        ft_puthex(n / 16);
    ft_putchar(hexDigits[n % 16]);
}

void ft_puthex_upper(unsigned int n) {
    char *hexDigits = "0123456789ABCDEF";

    if (n >= 16)
        ft_puthex_upper(n / 16);
    ft_putchar(hexDigits[n % 16]);
}

/*La función ft_putptr convierte el puntero a un valor de tipo
unsigned long, luego imprime "0x" seguido del valor del puntero
en hexadecimal.*/
void ft_putptr(void *p) {
    unsigned long ptr_val = (unsigned long)p;
    ft_putstr("0x");
    ft_puthex_upper(ptr_val);
}

/* Toma una cadena de formato y un número variable de argumentos. 
Utiliza va_start() para inicializar una lista de argumentos args. 
Luego, recorre la cadena de formato carácter por carácter. Si 
encuentra un carácter %, espera que el siguiente carácter sea un 
especificador de formato (c, s o d en este caso) y llama a la 
función correspondiente para escribir el siguiente argumento en 
la salida estándar. Si el carácter no es un %, simplemente lo 
escribe en la salida estándar. Finalmente, utiliza va_end() 
para limpiar args.*/
void ft_printf(char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            if (*format == 'c')
                ft_putchar(va_arg(args, int));
            else if (*format == 's')
                ft_putstr(va_arg(args, char *));
            else if (*format == 'd' || *format == 'i')
                ft_putnbr(va_arg(args, int));
			else if (*format == 'u')
                ft_putunbr(va_arg(args, unsigned int));
            else if (*format == 'x')
                ft_puthex(va_arg(args, unsigned int));
            else if (*format == 'X')
                ft_puthex_upper(va_arg(args, unsigned int));
            else if (*format == 'p')
                ft_putptr(va_arg(args, void *));
        } else {
            ft_putchar(*format);
        }
        format++;
    }

    va_end(args);
}

/*int main() {
    int var = 123;

    ft_printf("Hola, %s. Tienes %d años y tu altura es %u cm.\n", "Juan", 30, 175);
    ft_printf("El valor en hexadecimal de 255 es %x.\n", 255);
    ft_printf("El valor en hexadecimal (mayúsculas) de 255 es %X.\n", 255);
    ft_printf("La dirección de memoria de esta variable es %p.\n", &ft_printf);
    ft_printf("La dirección de memoria de var es %p y su valor es %d.\n", &var, var);

    return 0;
}*/