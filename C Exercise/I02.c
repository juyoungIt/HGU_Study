#include <stdio.h>

void PrintStar(); // 함수 PrintStar의 선언

main()
{
	int size[10]; // 사용자로부터 입력받은 10개의 수를 저장할 1차원 배열선언
	int i; // 반복문 사용을 위한 변수선언

	printf("양의 정수 10개를 입력해 주세요. (입력하신 숫자만큼 '*' 가 그려집니다.) : ");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &size[i]);
		PrintStar(size[i]); // 함수 PrintStar 호출
	}
	return 0;
}

// 함수 PrintStar의 정의부
void PrintStar(int x)
{
	int i = 0;
	while (1)
	{
		printf("*");
		i++;
		if (i == x)
		{
			printf("\n");
			break;
		}
	}
	return;
}