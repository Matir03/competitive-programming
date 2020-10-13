#include <stdio.h>

int isArmstrong(int m)
{
    int a,b,c,d;
    int n=m;
    
    d = n % 10;
    n = (n-d)/10;
    c = n % 10;
    n = (n-c)/10;
    b = n % 10;
    n = (n-b)/10;
    a = n % 10;
    
    if (a*a*a+b*b*b+c*c*c+d*d*d==m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int main() 
{
   int n;
   
   printf("Number:");
   scanf("%d",&n);
   
   if (isArmstrong(n)==1)
   {
      printf("The number is Armstrong");
   }
   else
   {
      printf("The number is not Armstrong");
   }
   
   return 0;
}

