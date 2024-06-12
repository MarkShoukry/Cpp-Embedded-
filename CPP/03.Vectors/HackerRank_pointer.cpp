#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std ;

void update (int *a, int *b)
{
    int A;
    A = *a + *b;
    int B;
    B = abs(*a - *b);
    *a = A;
    *b = B;
}


int main() 
{
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}