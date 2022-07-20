#include <stdio.h>

int main()
{
    int rowColCount;
    int temp;
    printf("Please enter the number of rows and columns: ");
    scanf("%d", &rowColCount);
    
    // Declare 2D Array
    int numArray[rowColCount][rowColCount];
    
    // In c you can't just get the length. This is how you get the length of an array in c.
    int length = sizeof(numArray) / sizeof(numArray[0]);

    
    
    // First nested for loop that asks the user for input to fill in the rows.
    for(int i = 0; i < length; i++) {
        printf("Enter %d numbers to put them in the array on row %d: ", length, (i + 1));
        for(int j = 0; j < length; j++) {
            scanf("%d", &numArray[i][j]);
        }
    }
    
    // Second nested for loop that prints out the resulting 2D array for the user
    printf("\nResulting Matrix:\n");
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            printf("%d ", numArray[i][j]);
        }
        printf("\n");
    }
    
    // Tells the user how many rows there were. Helps to ensure it returns maxes from all rows.
    printf("\nThere were %d rows.", length);
    printf("\nFinding max in each row. . . . Beep boop");

    // Third nested for loop that finds max in each row.
    // Recycles the temp variable.
    for(int i = 0; i < length; i++) {
        temp = numArray[i][0];
        for(int j = 0; j < length; j++) {
            if(numArray[i][j] > temp) {
                temp = numArray[i][j];
                }    
            }
        printf("\nThe largest number in row %d is %d.", (i + 1), temp);
    }
    
    return 0;
}
