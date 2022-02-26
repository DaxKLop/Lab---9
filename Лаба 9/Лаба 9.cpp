#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "rus");
	FILE* f1;
	FILE* f2;
	char str1[100], str2[100];
	int i;
	printf("Записать только чётные строки\n");
	fopen_s(&f1, "f1.txt", "w+");

	if (f1 != NULL)
	{
		printf("Внесите данные:\n");
		for (i = 1; i <= 10; i++)
		{
			fgets(str1, 100, stdin);
			fputs(str1, f1);
		}
		printf("Данные записаны в файлы.\n");
		fclose(f1);


	}
	else
	{
		printf("Невозможно открыть файл\n");
		return 1;
	}
	fopen_s(&f1, "f1.txt", "r+");
	fopen_s(&f2, "f2.txt", "w+");
	if (f1 != NULL && f2 != NULL)
	{
		for (i = 1; i <= 10; i++)
		{
			fgets(str2, 100, f1);
			if (i % 2 == 0)
			{
			fputs(str2, f2);
			printf("%s", str2);
			}
		}
		printf("Данные записаны в файлы.\n");
		fclose(f1);
		fclose(f2);

	}
	else
	{
		printf("Невозможно открыть файл\n");
		return 1;
	}

}