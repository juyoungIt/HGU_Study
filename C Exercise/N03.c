#include <stdio.h>

int string_length(char * str);

main()
{
	int str[20]; // 사용자로부터 입력받은 문자열을 저장할 문자배열 선언
	int length; // 문자열의 길이값을 저장하는 변수선언
	char * p_str; // 포인터변수 선언

	printf("문자열을 입력하세요. : ");
	gets(str);
	p_str = str;

	length = string_length(p_str);

	printf("문자열의 길이는 %d입니다. \n", length);
	return 0;
}

int string_length(char * str)
{
	int i; // 반복문 사용을 위한 변수선언
	int count = 0; // 문자의 개수를 count할 변수선언

	for (i = 0;; i++)
	{
		if (*(str+i) == '\0')
			break;
		else
			count++;
	}

	return count;
}