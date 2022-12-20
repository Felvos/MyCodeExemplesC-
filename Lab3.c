#include <stdio.h>
#include <locale.h>
#define lmax 64



int main(void) 
{
  printf("Лабораторная работа №2\nЗадание 1\n");

  int d[lmax][lmax];
  int n, m;
  int is_even = 1;
  printf("\nВведите высоту матрицы (1 - %d): ", lmax);
  scanf("%d", &n);
  printf("\nВведите ширину матрицы (1 - %d): ", lmax);
  scanf("%d", &m);
  for (int i = 0; i < n; i++) //Ввод матрицы
    {
      for (int j = 0; j < m; j++)
        {
          printf("\nВведите [%d][%d] элемент матрицы: ", i, j);
          scanf("%d", &d[i][j]);
        }
    }
  printf("\nВаша изначальная матрица: \n");
  for (int i = 0; i < n; i++) //Вывод изначальной матрицы
    {
      for (int j = 0; j < m; j++)
        {
          printf("[%d] ", d[i][j]);
        }
      printf("\n");
    }
  for (int i = 0; i < n; i++) //Алгоритм выявления четной строки и ее удаления сдвигом
      {
        is_even = 1; //Строка считается четной, до тех пор, пока не встречается нечетный элемент
        for (int j = 0; j < m; j++)
          {
            if(d[i][j] % 2 == 1) // Проверка элемента строки на четность
            {
              is_even = 0;
            }
          }
        if(is_even == 1)
        {
          for (int k = i; k < n; k++) //Цикл, проходящийся по строкам матрицы, начиная с четной строки, сдвиг
            {
              if(k != n - 1)
              {
                for (int l = 0; l < m; l++) //Спокойно меняем значение текущего элемента на значение следующего до последнего
                  {
                    d[k][l] = d[k+1][l];
                  }
              }
              if(k == n - 1)
              {
                for (int l = 0; l < m; l++) //Последняя строка
                  {
                    d[k][l] = 0;
                  }
              }
            }
          n--; //Исключаем последнюю строку
          i--; //Если мы сдвинем строку и на месте четной вновь окажется четная
        }
      }
  printf("\nВаша новая матрица:\n");
  for (int i = 0; i < n; i++) //Вывод новой матрицы
    {
      for (int j = 0; j < m; j++)
        {
          printf("[%d] ", d[i][j]);
        }
      printf("\n");
    }   
  if(n == 0)
  {
    printf("Все строки удалены");
  }
  return 0;
  
}