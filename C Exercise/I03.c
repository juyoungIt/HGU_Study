#include <stdio.h>

void PrintChar(int x, char y); // 함수 PrintChar의 선언

main()
{
	char word; // 출력할 문자에 대한 값을 저장하는 변수선언
	int number[10]; // 사용자로부터 입력받은 10개의 수를 저장할 1차원 배열선언
	int i; // 반복문 사용을 위한 변수선언

	printf("사용할 문자를 입력해 주세요. : ");
	word = getchar();
	printf("양의 정수 10개를 입력해 주세요. (입력한 정수만큼 문자를 출력합니다.) : ");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &number[i]);
		PrintChar(number[i], word);
	}
	return 0;
}

// 함수 PrintChar의 정의부
void PrintChar(int x, char y)
{
	int i = 0;
	while (1)
	{
		printf("%c", y);
		i++;
		if (i == x)
		{
			printf("\n");
			break;
		}
	}
	return;
}