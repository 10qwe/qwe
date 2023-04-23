#include <stdio.h>
#include"fib.h"


int main() {
  int choice, n, i;
  printf("Enter your choice:\n");
  printf("1. Generate Fibonacci series\n");
  printf("2. Generate prime numbers\n");
  printf("3. Generate leap years\n");
  scanf("%d", &choice);

  printf("Enter the value of n: ");
  scanf("%d", &n);

  switch (choice) {
    case 1:
      printf("Fibonacci series: ");
      for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
      }
      printf("\n");
      break;
    case 2:
      printf("First %d prime numbers: ", n);
      for (i = 0; i < n; i++) {
        printf("%d ", prime(i));
      }
      printf("\n");
      break;
    case 3:
     printf("Leap years from 2000: ");
      for (i = 2000; i <= 2000 + 4*n; i++) {
        if (leap_year(i)) {
          printf("%d ", i);
        }
      }
      printf("\n");
      break;
    default:
      printf("Invalid choice\n");
      break;
  }

return 0;
}

/*

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}
//1,1,2,3,5,8,13,21

int prime(int n) 
{
  int i, count = 0;
  for (i = 2; count < n; i++) {
    int j, is_prime = 1;
    for (j = 2; j < i; j++) {
      if (i % j == 0) {
        is_prime = 0;
        break;
      }
    }
    if (is_prime) {
      count++;
    }
  }
  return i - 1;
}

int leap_year(int year) {
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        return 1;
      } else {
        return 0;
      }
    } else {
      return 1;
    }
  } else {
    return 0;
  }
}


*/