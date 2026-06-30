#include<stdio.h>

int main(){
    int a,b,r;
    printf("Enter two number:");
    scanf("%d%d",&a,&b);
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    printf("The gcd is:%d",a);
}