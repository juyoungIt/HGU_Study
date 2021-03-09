#include <stdio.h>
#include <string.h>

char * reverse_string(char * str);

main()
{
	char pre_string[20]; // 사용자가 입력한 문자열을 저장할 배열선언
	char post_string[20]; // 반전된 문자열을 저장할 배열선언
	char * str;
	
	printf("문자열을 입력하시오. : ");
	gets(pre_string);
	str = pre_string;
	strcpy(post_string, reverse_string(str));
	printf("역순으로 변환한 문자열은 다음과 같습니다. --> %s\n", post_string);
	return 0;

}

char * reverse_string(char * str)
{
	int i; // 반복문 사용을 위한 변수선언
	int length; // 문자열의 길이를 저장하는 변수선언
	char temp; // 문자열의 반전작업에서 필요한 변수선언
	int size; // 반복문 종료조건을 위한 변수선언

	// 1. 문자열의 길이 구하기
	for (i = 0;; i++)
	{
		if (*(str + i) == '\0')
			break;
	}
	length = i;

	// 2. 문자열 반전시키기
	// 2-1. 문자열의 길이가 홀수 일 때
	if (length % 2 == 1)
	{
		size = length / 2;
		for (i = 0; i < size; i++)
		{
			temp = *(str + i);
			*(str + i) = *(str + (length - (i + 1)));
			*(str + (length - (i + 1))) = temp;
		}
	}
	// 2-2. 문자열의 길이가 짝수 일 때
	else if (length % 2 == 0)
	{
		size = length / 2;
		for (i = 0; i < size; i++)
		{
			temp = *(str + i);
			*(str + i) = *(str + (length - (i + 1)));
			*(str + (length - (i + 1))) = temp;
		}
	}
	return str;
}