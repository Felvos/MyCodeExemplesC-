#include <stdio.h>
#include <locale.h>
#define lmax 64

int main(void) 
{
  printf("Лабораторная работа №2\nЗадание 2\n");
  int d[lmax];
  int n;
  
  printf("\nВведите длинну массива (1 - %d): ", lmax); 
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    {
      printf("\nВведите [%d] элемент массива: ", i);
      scanf("%d", &d[i]);
    }
  printf("\nВаш изначальный массив: \n"); 
  for (int i = 0; i < n; i++)
    {
      printf("[%d] ", d[i]);
    }
  for(int i = 0; i < n; i++)
    {
      int rank = 0;
      int remainder = 0; 
      int ranked_ten = 1; 
      while(remainder != d[i])
        {
          rank++; 
          int divider = 1;
          for (int i = 0; i < rank; i++) 
            {
              divider = divider * 10;
            }
          remainder = d[i] % divider; 
        }
      rank--; 
      for(int k = 0; k < rank; k++)
        {
          ranked_ten = ranked_ten * 10;
        }
      d[i] = ((d[i] % 10) * ranked_ten) + (d[i] / 10); 
    }
  printf("\nВаш новый массив: \n");
  for (int i = 0; i < n; i++)
    {
      printf("[%d] ", d[i]);
    }
  return 0;
}