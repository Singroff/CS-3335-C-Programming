#include <stdio.h>

#define FREEZING_POINT 32.0f // Must use floats here
// Must use floats here (5/9 doesn't work)
#define SCALE_FACTOR (5.0f / 9.0f)

int main(){
    float fahrenheit, celsius;
    printf("Enter Fahrenheit: ");
    scanf("%f", &fahrenheit);

    celsius = (fahrenheit - FREEZING_POINT) * SCALE_FACTOR;
    printf("%.1f degrees fahrenheit is %.1f degrees celsius.", fahrenheit, celsius);
    return 0;
}