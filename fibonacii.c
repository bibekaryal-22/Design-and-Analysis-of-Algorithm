#include<stdio.h>

int main(){
    int a,b,n,i,c;
    printf("Enter the nth term:");
    scanf("%d",&n);
    a=0;
    b=1;
    for(i=2;i<n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    printf("The nth term item is:%d",c);
}
