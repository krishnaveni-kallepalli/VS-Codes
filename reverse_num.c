#include<stdio.h>
int main()
{
    int num,rev=0,rem=0;
    printf("ENter num:");
    scanf("%d",&num);
    while(num!=0)
    {
        rem = num%10;
        rev = rem+rev*10;
        num = num/10;
    }
    printf("Reverse of num:%d\n",rev);
    return 0;
}