#include <stdio.h>
int main(void)
{
    int n = 0,a = 0,b = 0,rez =-2,c = 0;
    scanf("%d", &n);
    scanf("%d", &b);
    for (int i=1;i<n;i++)
        {
scanf("%d",&c);
        if ((i%2)==1 && rez != 0)  
             {
             a = c; if (b>=a) rez = 1; else rez = 0;
             }
        if ((i%2)==0 && rez != 0){b=c; if(a>=b) rez = 1; else rez=0 ; 
             }

}
printf("%d\n",rez);
}

