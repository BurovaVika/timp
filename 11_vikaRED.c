#include <stdio.h>
int main(void)
{
int n = 0,a=0,b = 0;
scanf("%d", &n);
scanf("%d",&b);
for (int i=1;i<n;i++)
{
if ((i%2)==1)  
{
scanf("%d",&a); if (b>=a) printf(" 1\n"); else {printf(" 0\n");
}}
if ((i%2)==0){scanf("%d",&b); if(a>=b) printf("1\n"); else printf (" 0\n");}

}
}
