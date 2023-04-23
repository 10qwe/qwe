// Write a program to create your own �C� library using macros for conversions. (binary <--> decimal, binary <--> hexadecimal)

#include <stdio.h>
#include <conio.h>
#include "hexbix.h"

int main()
{
    int ch, dec;
    long long bin, hex;
    char hexdec[100];

    printf("\nMenu\n1.Binary to decimal\n2.Decimal to Binary\n3.Binary to Hexadecimal\n4.Hexadecimal to Binary\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        print();
        scanf("%lld", &bin);
        dec = bintodec(bin);
        printf("Decimal= %d", dec);
        break;
    case 2:
        print();
        scanf("%d", &dec);
        bin = dectobin(dec);
        printf("Binary= %lld", bin);
        break;
    case 3:
        print();
        scanf("%lld", &bin);
        hex = bintohex(bin);
        printf("Hexadecimal= %lX", hex);
        break;
    case 4:
        print();
        scanf("%s", &hexdec);
        bin = hexTobin(hexdec);
        break;
    default:
        printf("Wrong Input\n");
    }

    return 0;
}


/*
#include <math.h>

void print()
{
    printf("Enter number= ");
}

int bintodec(long long bin)
{
    int dec = 0, i = 0, rem;

    while (bin != 0)
    {
        rem = bin % 10;
        bin = bin / 10;
        dec += rem * pow(2, i);
        ++i;
    }

    return dec;
}

long long dectobin(int dec)
{
    long long bin = 0;
    int rem, i = 1;

    while (dec != 0)
    {
        rem = dec % 2;
        dec /= 2;
        bin += rem * i;
        i *= 10;
    }

    return bin;
}

long long bintohex(long long bin)
{
    long int hex = 0, i = 1, rem;
    while (bin != 0)
    {
        rem = bin % 10;
        hex = hex + rem * i;
        i = i * 2;
        bin = bin / 10;
    }
    return hex;
}

char hexTobin(char *hex)
{

    long int i = 0;
    printf("\nBinary= ");
    while (hex[i])
    {

        switch (hex[i])
        {
        case '0':
            printf("0000");
            break;
        case '1':
            printf("0001");
            break;
        case '2':
            printf("0010");
            break;
        case '3':
            printf("0011");
            break;
        case '4':
            printf("0100");
            break;
        case '5':
            printf("0101");
            break;
        case '6':
            printf("0110");
            break;
        case '7':
            printf("0111");
            break;
        case '8':
            printf("1000");
            break;
        case '9':
            printf("1001");
            break;
        case 'A':
        case 'a':
            printf("1010");
            break;
        case 'B':
        case 'b':
            printf("1011");
            break;
        case 'C':
        case 'c':
            printf("1100");
            break;
        case 'D':
        case 'd':
            printf("1101");
            break;
        case 'E':
        case 'e':
            printf("1110");
            break;
        case 'F':
        case 'f':
            printf("1111");
            break;
        default:
            printf("\nInvalid hexadecimal digit %c", hex[i]);
        }
        i++;
    }
}

*/