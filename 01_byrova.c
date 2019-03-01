#include <stdio.h>
#include <stdlib.h>
int main(void)
{
int n,x = 0,min = 0;
scanf("%d",&n);
scanf("%d",&x);
min = x;
for (int i =1;i<n;i++)
{
scanf("%d",&x);
if (x <min) min=x;
}
printf("%d",min);
}
