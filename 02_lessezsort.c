
#include <stdio.h>

void sorting_function(int *mass,int n){ 
        int j;
        int g;
        int temp;
        for(g=n/2;g>0;g = g / 2){
        for(int i=g;i<n;i++){
         temp=mass[i];
        for( j=i;j>=g;j=j - g)
        {
        if(temp<mass[j-g])
        mass[j]=mass[j-g];
        else break;
        }
       mass[j]=temp;
        }
    }
}

int main(){
        int n;
        scanf("%d",&n);
        int mass[n];
        for(int i=0;i<n;i++)
        {scanf("%d",&mass[i]);}
        sorting_function(mass,n);
        for(int i=0;i<n;i++)
        {printf("%d ",mass[i]);}
        printf("\n");
}
