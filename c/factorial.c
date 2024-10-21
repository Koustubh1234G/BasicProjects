#include<stdio.h>
#include<conio.h>

void main(){
    //clrscr();

    int num,i,fact=1;
    printf("Enter a letter ");
    scanf("%d",&num);

    for (i=num; i >0; i--)
    {
        fact=fact*i;
        
    }
    printf("%d",fact);

    getch();
}