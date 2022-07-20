#include <stdio.h>

// recursive function for fibonacci calculation
// Must be declared before main (Else it's implicit declaration)
int fib(int num) {
    // 2 base cases when num is 0 or 1
    if(num == 0) {
        return 0;
    } 
    
    else if(num == 1) {
        return 1;
    } 
    // else case - recursively runs fib on sum of previous 2 terms
    else
        return (fib(num - 1) + fib(num - 2));
}


int main()
{
    // get number from user
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // print fib + fibonacci sum (based on sample output provided)
    printf("The fibonacci value for %d is %d", num,  fib(num));
}

