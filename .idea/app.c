#include<stdio.h>
int main(){
    int a = 1;
    // a = a++ + a;
    // printf("%d", a);
    // a = ++a + a;
    a = a + a++;
    printf("\n%d", a); 
    a = ++a + a;
    printf("\n%d", a);
    a = a++ + a;
    printf("\n%d", a);
    // a = a + a++;
    // printf("\n%d", a);
    // // a = ++a + a;
    // a += a++;
    // printf("\n%d", a);
    return 0;
}