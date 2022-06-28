/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
// Necessary for boolean type
#include <stdbool.h>

int main()
{
    int num, numOfDivisors = 0;
    bool isPrime;
    isPrime = true;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    for(int i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            printf("%d\n", i);
            isPrime = false;
            numOfDivisors++;
        }
        else {
            continue;
        }
    }
    
    if(isPrime) {
        printf("The number %d is prime and has 0 divisors.", num);
    } else {
        printf("The number %d is not prime with %d divisors.", num, numOfDivisors);
    }
    
    return 0;
}
