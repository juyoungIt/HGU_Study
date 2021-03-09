#include <stdio.h>

int MaxOfTen(void); // 함수 MaxOfTen 선언

main()
{
	int max; // 최댓값을 저장하는 변수선언
	
	max = MaxOfTen(); // 함수 MaxOfTen 호출 및 return 값 max에 저장
	printf("최댓값은 %d입니다. \n", max);
	return 0;
}

// 함수 MaxOfTen의 정의부
int MaxOfTen(void)
{
	int max; // 최댓값을 저장하는 변수선언
	int number[10]; // 사용자가 입력한 10개의 정수값을 저장할 1차원 배열선언
	int i; // 반복문 사용을 위한 변수선언
	
	printf("10개의 숫자 중 최댓값을 구합니다. \n");
	for (i = 0; i < 10; i++)
	{
		printf("%d번째 수를 입력해 주세요. : ", i + 1);
		scanf("%d", &number[i]);
		if (i == 0)
			max = number[i];
		else if (max < number[i])
			max = number[i];
	}
	return max;
}