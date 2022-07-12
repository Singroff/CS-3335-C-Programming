#include <stdio.h>

// Declare recursive function
int getSum(int num);

int main()
{
    int num;
    char c;
    printf("Lab 8: Recursively Add Digits in a Number");
    // While loop to allow user to enter multiple numbers.
    do {
        printf("\n\nPlease enter a number, or enter 0 to exit the program: ");
        scanf("%d", &num);
        if(num >= 0) {
        printf("*************************************\n");
        printf("The digits in %d added together are: %d", num, getSum(num));
        printf("\n*************************************");
        }
        else {
        printf("The number must be non-negative.");
        }
    }
    // Exit the program if the user enters 0.
    while(num != 0);

    printf("\n\nExiting Beep Boop . . .");
    printf("\nGoodbye!");
    return 0;
}

// Recursively add digits.
int getSum(int num) {
    // Base Case
    if(num == 0) {
        return num;
    } else {
        // num % 10 returns last digit in num. (453 % 10 = 3). Dividing by 10 shaves off the last digit.
        // Doing this recursively will add all the digits together.
        return (num % 10) + getSum(num / 10);
    }
}
