#include <stdio.h>

int main()
{
    // Outer for loop prints new lines
    for(int i = 1; i <= 5; i++) {
        // Inner for loop prints characters.
        for(int j = 5; j > 0; j--) {
            // If j <= to i, instead of a dot, I print i.
            if(j <= i) {
                printf("%d", i);
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    
    // New line separator
    printf("\n\n");
    
    // Second set of loops. Same principle, except 
    // I print j if its equal to i.
    for(int i = 1; i <= 5; i++) {
        for(int j = 5; j > 0; j--) {
            if(j == i) {
                printf("%d", j);
            } else {
                printf(".");   
            }
        }
        printf("\n");
    }

    return 0;
}
