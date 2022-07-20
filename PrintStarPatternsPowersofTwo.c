#include <stdio.h>
#include <math.h>


void printStars(int num) {
        // if the number is even, print 2n stars on each row
    if(num % 2 == 0) {
      for(int i = 1; i <= num; i++ ) {
        for(int j = 1; j <= i * 2; j++) {
            printf("*");
            }
            // print statement for easier grading
        printf("   <----   This is 2 times %d.", i);
        printf("\n");
        } 
        // if the number if odd, print 2 ^ n stars on each row using power function
    } else {
       for(int i = 1; i <= num; i++ ) {
           // So this is news to me, but I found out when using C that the power function
           // expects doubles and if you pass it a casted integer, it may give you the wrong
           // results. To fix this, you can add 1e-9 to the results and it will fix any inaccuracies
        for(int j = 1; j <= (int) (pow(2, i) + 1e-9); j++) {
            printf("*");
            }
            // Print statement for easier grading
        printf("   <----   This is 2 to the power of %d.", i);
        printf("\n");
        }  
    }
}

int main()
{
    int num;
    // get number from user
    printf("Please enter a number: ");
    scanf("%d", &num);
    
    printStars(num);    

    return 0;
}
