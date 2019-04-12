
#include <stdio.h>
#include <stdlib.h>
void change(int *numbers, int start, int bot)
{
  int tmp; 
  int complet = 0; 
  
  while ((start * 2 <= bot) && (!complet)) 
  {
    if (start * 2 == bot)    
      tmp = start * 2;    
    
    else if (numbers[start * 2 + 1] < numbers[start * 2])
      {tmp = start * 2;}
    else
      tmp = start * 2 + 1;
    
    if ( numbers[tmp] > numbers[start]) 
    {
      int temp = numbers[start]; 
      numbers[start] = numbers[tmp];
      numbers[tmp] = temp;
      start = tmp;
    }
    else 
      {complet = 1;}
  }
}

void heapSort(int *arr, int n) 
{
    int tmp;

  for (int i = (n / 2) - 1; i >= 0; i--)
    change(arr, i, n - 1);
  for (int i = n - 1; i >= 1; i--)
  {
     tmp = arr[0];
    arr[0] = arr[i]; 
    arr[i] = tmp;
    change(arr, 0, i - 1);
  }
}
int main()
{
  int g;
  scanf("%d",&g);
  int mass[g];
  for (int i = 0; i<g; i++)
      scanf("%d",&mass[i]);

  heapSort(mass, g);
   for (int i = 0; i<g; i++)
    printf("%d ", mass[i]);
  printf("\n");
 }
