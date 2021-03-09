#include <stdio.h>

main()
{
	int num[10]; // 사용자가 입력한 10개의 수를 저장할 1차원 배열선언
	int * p; // 포인터 변수선언 - 1
	int i; // 반복문을 사용하기 위한 변수선언
	int max; // 최댓값을 저장하는 변수선언
	int min; // 최솟값을 저장하는 벼수선언

	p = num; // 포인터 변수에 주소값 할당

	for (i = 0; i < 10; i++)
	{
		printf("%d번째 숫자를 입력해 주세요. : ", i+1);
		scanf("%d", p + i);
	}

	//1. 최댓값을 구하는 과정
	for (i = 0; i < 10; i++)
	{
		if (i == 0)
			max = *(p + i);
		else
			if (max < *(p + i))
				max = *(p + i);
	}

	//2. 최솟값을 구하는 과정
	for (i = 0; i < 10; i++)
	{
		if (i == 0)
			min = *(p + i);
		else
			if (min > *(p + i))
				min = *(p + i);
	}

	printf("최댓값 %d, 최솟값 %d 입니다. \n", max, min);
	return 0;
}