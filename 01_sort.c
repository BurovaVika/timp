#include <stdio.h>
#include <stdlib.h>

void sort(int *arr,int g,int q)
{
        int j=q;
        int i=g;
        int dom;
        int men = arr[(g+q)/2];
        while(j>=i)
        {
            for(int k;arr[i]<men;i++);
            for(int g;arr[j]>men;j--);
            if(j>=i)
            {
                dom=arr[i];
                arr[i++]=arr[j];
                arr[j--]=dom;
            }
        }
        if(j>g) 
        {sort(arr,g,j);}
        if(q>i)
        {sort(arr,i,q);}
}

int main()
{
        int n;
        scanf("%d",&n);
        int arr[n];
        for(int i=0;i<n;i++)
            {
                scanf("%d",&arr[i]);
            }
        sort(arr,0,n);

        for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
        printf("\n");
        return 0;
}
