#include <stdio.h>

void PrintChar(int x, int y, char z); // 함수 PrintChar 선언

main()
{
	char word; // 문자에 대한 값을 저장할 변수선언
	int i; // 반복문 사용을 위한 변수선언
	int space; // 여백에 대한 값을 저장할 변수선언
	int height; // 높이에 대한 값을 저장할 변수선언

	printf("우직각 삼각형을 그리는 데 사용할 문자를 입력해 주세요. : ");
	word = getchar();
	printf("우직각 삼각형의 높이와 왼쪽 여백의 값을 입력해 주세요. : ");
	scanf("%d %d", &height, &space);

	for (i = 0; i < height; i++)
	{
		PrintChar(space+height-i, i+1, word); // 함수 PrintChar 호출
	}
}

// 함수 PrintChar 정의부
void PrintChar(int x, int y, char z)
{
	int i; // 반복문 사용을 위한 변수선언
	for (i = 0; i < x; i++)
		printf(" ");
	for (i = 0; i < y; i++)
		printf("%c", z);
	printf("\n");
	return;
}