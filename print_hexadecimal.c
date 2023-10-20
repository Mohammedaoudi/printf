#include "main.h"
#include <unistd.h>
#include <math.h>
/**
 * print_hex_base - base function for printing hexadecimal nbrbers
 * @arg: argument list containing hexadecimal
 * @_case: a  in caps on lower, printing the hex nbrber in caps in lower
 * Return: nbrber of digits printed
 */

int print_hex_base(va_list arg, char _case)
{
        unsigned int nbr = va_arg(arg, unsigned int);
        int nbrCharacters;

        if (nbr == 0)
                return (_putchar('0'));
        nbrCharacters = print_unsignedIntToHex(nbr, _case);

        return (nbrCharacters);
}
/**
 * print_hex - prints a hexadecimal in lower case
 * @arg: list that contains hexadecimal to print
 * Return: nbrber of digits printed
 */

int print_hex(va_list arg)
{
        return (print_hex_base(arg, 'a'));
}

/**
 * print_HEX - prints a hexadecimal in upper case
 * @arg: list that contains hexadecimal to print
 * Return: nbrber of digits printed
 */

int print_HEX(va_list arg)
{
        return (print_hex_base(arg, 'A'));
}
