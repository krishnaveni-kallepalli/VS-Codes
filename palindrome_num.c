#include<stdio.h>
int main()
{
    int num,rem=0,res=0;
    printf("ENter num:");
    scanf("%d",&num);
    int x = num;
    while(x!=0)
    {
        rem  = x %10;
        res = rem+res*10;
        x = x/10;
    }
    if(res == num) printf("palindrome\n");
    else printf("not palindrome\n");
    return 0;
}