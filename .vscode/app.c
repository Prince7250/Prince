#include<stdio.h>

int main(){
    int a = 5;
    a = a++ + a;
    printf("\nThe number after increment is : %d",a);
    a = ++a + a;
    printf("\nThe number after increment is : %d",a);
    return 0;
}
