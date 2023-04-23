#include <stdio.h>
#include "naturalnumber.h"


int main() 
{
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  printf("Factorial of %d is %d\n", n, factorial(n));
  printf("Sum of natural numbers till %d is %d\n", n, sum(n));

  return 0;
}

/*

int factorial(int n) 
{
  if (n == 0) 
  {
    return 1;
  }
  else
  {
  	return n * factorial(n - 1);
  }
  
}

int sum(int n) 
{
  return (n * (n + 1)) / 2;
}

*/

