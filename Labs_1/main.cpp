#include <stdio.h>
#include <string.h>
#include <conio.h>
#include<locale>

int StrLen(char s[])
{
	int k = 0;
	for (int i = 0; i < 81; i++)
	{
		k = i;
		if (*(s+i) == '\0')
		{
			break;
		}
	}
	return k;
}

int StrCmp(char s1[], char s2[])
{
	int a, b;
	bool isEnd1 = false;
	bool isEnd2 = false;
	for (int i = 0; i < 81; i++)
	{
		if ((a = s1[i]) > (b = s2[i]))return 1;
		if ((a = s1[i]) < (b = s2[i]))return -1;
		if (s1[i] == '\0')isEnd1 = true;
		if (s2[i] == '\0')isEnd2 = true;
		if (isEnd1 && isEnd2) return 0;
	}
}

void StrCpy(char* s1, char const* s2)
{
	for (int i = 0; i < 81; i++)
	{
		s1[i] = s2[i];
	}
}

void StrCat(char* s1, char const* s2)
{
	int k = 0;
	for (int i = 0; i < 81; i++)
	{
		if (s1[i] == '\0')
		{
			k = i; 
			break;
		}
	}
	 
	for (int i = 0; i < 81-(k+1); i++)
		s1[k + i] = s2[i];
}

char* StrChr(char * s, char c)
{
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return &s[i];
	}
	return NULL;
}

char* StrBrk(char* s1, char const* s2)
{
	for (int i = 0; i < 81; i++)
	{
		for (int j = 0; j < 81; j++)
		{
			if (s1[i] == s2[j]) return &s1[i];
		}
	}
	return 0;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	char s1[81];
	gets_s(s1, 80);
	char s2[81];
	gets_s(s2, 80);


	// 1. strlen - длина строки
	//printf("Library: Длина строки = %i\n", strlen(s1));
	//printf("My: Длина строки = %i\n\n", StrLen(s1));

	// 2. strcmp - сравнение строк, 0, 1, -1 в зависимости от кода
	//printf("Library: %i\n", strcmp(s1, s2));
	//printf("My: %i\n", StrCmp(s1, s2));

	// 4. strcpy_s - копирование s2 в s1
	//strcpy_s(s1, s2);
	//printf("Library: %s\n\n", s1);
	//StrCpy(s1, s2);
	//printf("My: %s", s1);

	// 6. strcat_s - копирование s2 в конец s1
	//strcat_s(s1, s2);
	//printf("Library: %s\n\n", s1);
	//StrCat(s1, s2);
	//printf("My: %s", s1);

	// 8. strchr - вывод ссылки на первое вхождение
	             // заданного символа
	//char* p1 = strchr(s1, 'a');
	//printf("Library: %c", *p1);
	//char *p = StrChr(s1, 'a');
	//printf("My: %c", *p);

	// 10. strbrk - найти в s1 любой из множества 
	              // символов входязич в s2
	char* p1 = strpbrk(s1, s2);
	printf("Library: %c\n", *p1);
	char* p = StrBrk(s1, s2);
	printf("My: %c", *p);
}