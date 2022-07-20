/*
Program Name: Program2_Epps.c
Programmer: Caleb Epps
Class: CS 3335
HW: 03
Problem: 02
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Better Practice for this to be a global variable
#define MAXSIZE 25

// Declare Standard Stack Functions, initialized below main
bool isEmpty();
bool isFull();
void push(char c);
char pop();
void makeEmpty();

// Declare Necessary Variables for Stack Implementation
char symbols[MAXSIZE];
// check stack position
int top = 0;

int main()
{
    char c;
    
    printf("Enter a combination of parentheses or braces.");
    printf("\nEXAMPLE: (()) or ({})");
    printf("\nYour input: ");
    // while loop executes while there is input on the same line..
    while((c = getchar()) != '\n') {
        if(c == '(' || c == '{') {
            // Push the character to the stack
            push(c);
            // if it's a closing symbol, perform pop and make sure it's matching.
        } else if(c == ')') {
            if(pop() != '(') {
                printf("These are not nested properly.");
                // Exits the program.
                exit(0);
            }
        } else if(c == '}') {
            if(pop() != '{') {
                printf("These are not nested properly.");

                exit(0);
            }
        }
    }
    // The stack should be empty here. if not, then they aren't nested properly.
    if(isEmpty()) {
        printf("The braces and parentheses are nested properly, nice!");
    } else {
        printf("The braces and parentheses are not nested properly.");
    }
    
    return 0;
}

// Standard isEmpty check, returns true if top is 0.
bool isEmpty() {
    if(top == 0) {
        return true;
    } else {
        return false;
    }
}

// Standard isFull check, returns true if top is equal to MAXSIZE
bool isFull() {
    if(top == MAXSIZE) {
        return true;
    } else {
        return false;
    }
}
// Pushes character to the stack
void push(char c) {
    if(isFull()) {
        printf("Stack is full");
    } else {
        symbols[top++] = c;

    }
}

// Standard pop to get character from stack
char pop() {
    if(!(isEmpty())) {
        --top;
        return symbols[top];
        }
}

// Voids entire stack
void makeEmpty() {
    top = 0;
}

