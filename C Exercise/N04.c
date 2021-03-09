#include <stdio.h>
#include <string.h>
#include <ctype.h>

int which_first(char * str1, char * str2);

main()
{
	char string1[20], string2[20];
	char * str1, *str2;
	int result; // 결과값을 저장하는 변수선언

	printf("첫번째 문자열을 입력하시오. : ");
	gets(string1);
	printf("두번째 문자열을 입력하시오. : ");
	gets(string2);

	str1 = string1;
	str2 = string2;

	result = which_first(str1, str2);
	if (result == 1)
		printf("첫번째 문자열이 사전에 먼저 나옵니다. \n");
	else if (result == 2)
		printf("두번째 문자열이 사전에 먼저 나옵니다. \n");

	return 0;
}

int which_first(char * str1, char * str2)
{
	// 대소문자의 구분이 없으므로 소문자를 기준으로 하여 통합하여서 변환과정을 거치도록함.
	// 1. 입력받은 모든 문자를 소문자로 변환하는 과정
	int i, j; // 반복문 사용을 위한 변수선언 - 1
	int k; // 반복문 사용을 위한 변수선언 - 2
	int size; // 비교작업을 진행할 횟수를 저장하는 변수선언

	for (i = 0;; i++)
	{
		if (isupper(*(str1 + i)) == 1)
			*(str1 + i) = 'a' + (*(str1 + i) - 'A');
		if (*(str1 + i) == '\0')
			break;
	}
	for (j = 0;; j++)
	{
		if (isupper(*(str2 + j)) == 1)
			*(str2 + j) = 'a' + (*(str2 + j) - 'A');
		if (*(str2 + j) == '\0')
			break;
	}

	if (i >= j)
		size = i;
	else if (i < j)
		size = j;

	// 2. 변환된 두 문자열을 비교하는 과정
	for (k = 0; k < size; i++)
	{
		if (*(str1 + k) > *(str2 + k))
			return 2;
		else if (*(str1 + k) < *(str2 + k))
			return 1;
		else if (*(str1 + k) == '\0')
			return 1;
		else if (*(str2 + k) == '\0')
			return 2;
	}
}