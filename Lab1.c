#include <stdio.h>
#include <string.h>
#define MAXLINE 255

int replace(char *input_file_name, char *output_file_name) 
{
  FILE *file_in;
  FILE *file_out;
  char str[MAXLINE];
  char alph[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
  file_in = fopen(input_file_name, "r");
  if (file_in == NULL)
  {
		printf("Невозможно открыть данный файл %s\n", input_file_name);
		return -1;
	}
  file_out = fopen(output_file_name, "w");
  if (file_out == NULL)
  {
		printf("Невозможно открыть данный файл %s\n", output_file_name);
		return -1;
	}
  while(fgets(str, MAXLINE, file_in) != NULL)
    {
      for(int i = 0; str[i] != '\0'; i++)
        {
          if(str[i] >= '0' && str[i] <= '9')
          {
            str[i] = alph[(int)str[i] - 48];
          }
        }
      fputs(str, file_out);
    }
  fclose(file_in);
  fclose(file_out);
  
}  
int show_files(char *input_file_name, char *output_file_name)
{
  FILE *file_in;
  FILE *file_out;
  char str[MAXLINE];
  file_in = fopen(input_file_name, "r");
  if (file_in == NULL)
  {
		printf("Невозможно открыть данный файл %s\n", input_file_name);
		return -1;
	}
  file_out = fopen(output_file_name, "r");
  if (file_out == NULL)
  {
		printf("Невозможно открыть данный файл %s\n", output_file_name);
		return -1;
	}
  printf("\nИзначальные строки в файле: \n");
  while (fgets(str, MAXLINE, file_in) != NULL)
	{
    puts(str);
    printf("\n");
  }
  printf("\nЗамененные строки в файле: \n");
  while (fgets(str, MAXLINE, file_out) != NULL)
	{
    puts(str);
    printf("\n");
  }
  fclose(file_in);
  fclose(file_out);
}

int input(char *input_file_name) 
{
  FILE *file_inp;
  file_inp = fopen(input_file_name, "w");
  if (file_inp == NULL)
  {
		printf("Невозможно открыть данный файл %s\n", input_file_name);
		return -1;
	}
  int k;
  char str[MAXLINE];
  printf("Введите количество вводимых строк: ");
  scanf("%d", &k);
  getchar();
  for (int i = 0; i<k; i++)
  {
    printf("Введите строку №%d:", i);
    gets(str);
    fputs(str, file_inp);
    fprintf(file_inp, "\n");
  }  
  fclose(file_inp);
}

int main(void) 
{
	FILE *file_in;
  FILE *file_out;
  char input_file_name[40];
	char output_file_name[40];
  int res = 0;
  printf("Введите имя файла с входными данными: ");
	gets(input_file_name);
	printf("Введите имя файла с выходными данными: ");
	gets(output_file_name);
  res = input(input_file_name);
  res = replace(input_file_name, output_file_name);
	res = show_files(input_file_name, output_file_name);
  return 0;
}