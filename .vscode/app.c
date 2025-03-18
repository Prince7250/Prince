#include<stdio.h>

int main(){
    int a = 5; // Initialize a to 5
    a = a++ + a; // Post-increment: a is used before incrementing
    printf("\nThe number after increment is : %d",a); // Print result
    a = ++a + a; // Pre-increment: a is incremented before use
    printf("\nThe number after increment is : %d",a); // Print result
    
    // Additional examples of increment operations (commented out)
    // printf("\nThe number after increment is : %d",a); // 11
    // a = --a + ++a;
    // printf("\nThe number after increment is : %d",a); // 22
    // a = a + ++a;
    // printf("\nThe number after increment is : %d",a); // e
    return 0;
}
