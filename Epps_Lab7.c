/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

void rotateFourChars(char *charPtr, int charLength) {
    
    // First for loop (Outer For Loop) prints new lines when needed
    for(int i = 0; i < charLength; i++) {
        // first inner for loop prints the rotated letters i to charLength
        for(int j = i; j < charLength; j++) {
            printf("%c", *(charPtr + j));
        }
        // Second inner for loop prints rotated letters from 0 to i.
        for(int k = 0; k < i; k++) {
            printf("%c", *(charPtr + k));
        }
        // Just regular required new line print
        printf("\n");
    }
}
    

int main()
{
    // Max characters for modularity. Also passed to function
    int max = 4;
    char characters[max];
    int current = 0;
    printf("Character Rotation: Enter the characters you'd like to rotate.");
    printf("\nOptionally, enter a number to choose the number of characters.");
    printf("\nNote: Please do not press enter after typing the number.");
    printf("\nExamples for 3 and 6 characters: 3abc // 6abcdef");
    printf("\nNote: If no number if entered, the default is 4 characters (abcd).");
    printf("\nYour Input: ");
    // Saves input characters to a character array.
    scanf("%d", &max);
    for(int i = 0; i < max; i++) {
        scanf("%c", &characters[i]);
        if(characters[i] == '\n') {
            break;
        }
    }
    // rotation method
    printf("\n");
    printf("Your Rotation Results: \n");
    printf("****************************\n");
    rotateFourChars(characters, max);

    return 0;
}
