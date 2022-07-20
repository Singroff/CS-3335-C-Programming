/*
Program Name: Program1_Epps.c
Programmer: Caleb Epps
Class: CS 3335
HW: 03
Problem: 01 (Caesar Cipher)
*/

#include <stdio.h>

int main()
{
    int maxChar = 50;
    char message[maxChar];
    int shiftAmount;
    
    // Gets the message from the user and save it to character array
    printf("Enter your secret message (Less than 50 characters): ");
    for(int i = 0; i < maxChar; i++) {
        scanf("%c", &message[i]);
        if(message[i] == '\n') {
            break;
        }
    }
    // Prints the message back to the user for confirmation purposes.
    printf("You entered: ");
    for(int i = 0; i < maxChar; i++) {
        printf("%c", message[i]);
        if(message[i] == '\n') {
            break;
        }
    }
    
    // Prompts the user for how much to shift their message.
    printf("Now enter how many places to shift your message: ");
    scanf("%d", &shiftAmount);
    printf("You want to shift your message %d places. Standby. . . .\n", shiftAmount);
    
    // For Loop that performs the actual shift.
    for(int i = 0; i < maxChar; i++) {
        // We only want to shift letters, so conditions ensure it's letters only.
        if(message[i] >= 'A' && message[i] <= 'Z') {
            // Formula gives accurate shift results. This solves the wrap-around problem. 
            message[i] = ((message[i] - 'A') + shiftAmount) % 26 + 'A';
        } else if(message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a') + shiftAmount) % 26 + 'a';
            // Breaks out of the loop at the end of the message.
        } else if(message[i] == '\n') {
            break;
        }
    }
    // Prints the ecrypted message back to the user.
    printf("Your encrypted message is: ");
    for(int i = 0; i < maxChar; i++) {
        printf("%c", message[i]);
        if(message[i] == '\n') {
            break;
        }
    }
    printf("Wow, very secure! :D");

    return 0;
}
