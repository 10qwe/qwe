#include <stdio.h>
#include <conio.h>
#include "area.h" 
int main()
{
    float circle_area, r;
    float rectangle_area, len, wid;
    float square_area, side;
    float triangle_area, base, ht;
    int ch;
    do
    {
        printf("\nMenu : 1.Circle 2.Rectangle 3.Square 4.Triangle 5.Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter the radius : ");
            scanf("%f", &r);
            circle_area = c_area(r);
            printf("The Area of Circle is: %f \n", circle_area);
            break;
        }
        case 2:
        {
            printf("Enter length and width : ");
            scanf("%f %f", &len, &wid);
            rectangle_area = r_area(len, wid);
            printf("The Area of Rectangle is: %f \n", rectangle_area);
            break;
        }
        case 3:
        {
            printf("Enter side : ");
            scanf("%f", &side);
            square_area = s_area(side);
            printf("The Area of Square is: %f \n", square_area);
            break;
        }
        case 4:
        {
            printf("Enter base and height : ");
            scanf("%f %f", &base, &ht);
            triangle_area = t_area(base, ht);
            printf("The Area of Triangle is: %f \n", triangle_area);
            break;
        }
        case 5:
            printf("Exit");
            break;
        default:
            printf("Wrong Input\n");
            break;
        }
    } while (ch != 5);
    getch();
    return 0;
}

/*

.h

#define pi 3.14
#define c_area(r) pi*r*r
#define s_area(side) side*side
#define r_area(len,wid) len*wid
#define t_area(base,ht) 0.5*base*ht

*/