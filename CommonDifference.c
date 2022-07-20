/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    // The input terms
    int firstTerm;
    int cDifference;
    int numOfTerms;
    

    // Get first term
    printf("Please enter the first term: ");
    scanf("%d", &firstTerm);
    // Get common difference
    printf("Please enter the common difference: ");
    scanf("%d", &cDifference);
    // Get number of terms
    printf("Please enter the number of terms: ");
    scanf("%d", &numOfTerms);
    
    // The output terms
    int lastTerm = firstTerm + (numOfTerms - 1) * cDifference;
    double sumOfTerms = numOfTerms * (firstTerm + lastTerm) / 2;
    double avgOfTerms = (sumOfTerms) / numOfTerms;
    
    // Print last term of sequence
    printf("The last term of the sequence is: %d\n", lastTerm);
    // Print sum of terms (%.0f to avoid decimals)
    printf("The sum of all terms in the sequence is: %.0f\n", sumOfTerms);
    // Print average of terms in sequence (%.1f for decimal points)
    printf("The average of terms in the sequence is: %.1f", avgOfTerms);
    
    return 0;
}
