#include<stdio.h>
#include<math.h>
#include<conio.h>

void main(){

    int num,sum=0,temp,a;
    printf("ENter ");
    scanf("%d",&num);
    a=num;
    while (num!=0)
    {
        temp=num%10;
        num=num/10;
        sum=sum+(temp*temp*temp);
    }
    
    if (sum==a)
    {
        printf("No is armstrong");
    }
    else
        printf("No is not armstrong");

    getch();
}