#include <stdio.h>


void sorting_function(int *mass,int n)
{
    int g = n-1;
    int t;
    while(g>=1)
    {
    for(int i=0;i<n-g;i++)
    {
    if(mass[i]>mass[i+g]){
    t=mass[i];
    mass[i]=mass[i+g];
    mass[i+g]=t;
    }
    }
    g = g - 1;;
        }
}

int main(){
        int n;
        scanf("%d",&n);
        int mass[n];
        for(int i=0;i<n;i++){
                scanf("%d",&mass[i]);
        }
        sorting_function(mass,n);
        for(int i=0;i<n;i++)
        {
        printf("%d ", mass[i]);
        }
        printf("\n");
        return 0;
}
