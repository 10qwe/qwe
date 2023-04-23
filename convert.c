#include <stdio.h>
#include <conio.h>
#include "convert.h"

int main()
{
    int ch;
    float celsius, fahrenheit, metre, feet, litre, cubic;
    float Cel, Far, Met, Ft, Lt, Cu;
    do
    {
        printf("\nMenu 1.Cel to Far 2.Far to Cel 3.Met to Feet 4.Feet to Met 5.Lt to CubFt 6.CubFt to Lt 7.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            print();
            scanf("%f", &celsius);
            Far = convertCelFahrenheit(celsuis);
            printf("The Conversion of Celsius to Fahrenheit is: %f", Far);
            break;
            
        case 2:
            print();
            scanf("%f", &fahrenheit);
            Cel = convertFarCelsuis(fahrenheit);
            printf("The Conversion of Fahrenheit to Celsius is: %f", Cel);
            break;

        case 3:
            print();
            scanf("%f", &metre);
            Ft = convertMetreFeet(metre);
            printf("The Conversion of Metre to Feet is: %f", Ft);
            break;

        case 4:
            print();
            scanf("%f", &feet);
            Met = convertFeetMetre(feet);
            printf("The Conversion of Feet to Metre is: %f", Met);
            break;

        case 5:
            print();
            scanf("%f", &litre);
            Cu = convertLitreCubic(litre);
            printf("The Conversion of Litre to Cubic Feet is: %f ", Cu);
            break;

        case 6:
            print();
            scanf("%f", &cubic);
            Lt = convertCubicLitre(cubic);
            printf("The Conversion of Cubic Feet to Litre is: %f ", Lt);
            break;
            
        case 7:
            printf("Exit");
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    } while (ch != 7);
    getch();
    return 0;
}

/*
.h
#define print() printf("Enter the value : ");
#define convertCelFahrenheit(celsuis) (celsius * 9/5) + 32
#define convertFarCelsuis(fahrenheit) (fahrenheit - 32)*5/9
#define convertMetreFeet(metre) 3.281 * metre
#define convertFeetMetre(feet) feet/3.281
#define convertLitreCubic(litre) 0.04*litre
#define convertCubicLitre(cubic) cubic/0.04

*/