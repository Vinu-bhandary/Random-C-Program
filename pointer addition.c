#include<stdio.h>
void main()
{
    int a=10;
    int *p;
    p=&a;
    printf("%d",p);
    p=p+1;
    printf("\n %d",p);
}
