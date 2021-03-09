#include <stdio.h>

float max(float number[]); // 함수 max에 대한 선언
float min(float number[]); // 함수 min에 대한 선언

main()
{
	float number[10]; // 10명의 점수를 저장할 1차원 배열선언
	float average; // 평균에 대한 값을 저장할 변수선언
	float M, m; // 최댓값과 최솟값을 저장하는 변수선언
	float total_sum = 0.0; // 심사점수의 합계값을 저장할 변수선언
	int i; // 반복문 사용을 위한 변수선언

	// 10명의 점수를 입력받아서 저장하는 부분
	for (i = 0; i < 10; i++)
	{
		printf("%d번 심사점수를 입력하세요. : ", i+1);
		scanf("%f", &number[i]);
		total_sum += number[i];
	}

	M = max(number); // 함수 max 호출
	m = min(number); // 함수 min 호출
	
	average = (total_sum - (M + m)) / 8.0;

	printf("가장 큰 점수와 가장 작은 점수를 제외한 8개의 점수에 대한 평균은 %.1f입니다. \n", average);
	return 0;
}

// 함수 max에 대한 정의부
float max(float number[])
{
	int i; // 반복문 사용을 위한 변수선언
	float max; // 최댓값을 저장할 변수선언

	for (i = 0; i < 10; i++)
	{
		if (i == 0)
			max = number[i];
		else
		{
			if (max < number[i])
				max = number[i];
		}
	}
	return max;
}

// 함수 min에 대한 정의부
float min(float number[])
{
	int i; // 반복문 사용을 위한 변수선언
	float min; // 최솟값을 저장할 변수선언

	for (i = 0; i < 10; i++)
	{
		if (i == 0)
			min = number[i];
		else
		{
			if (min > number[i])
				min = number[i];
		}
	}
	return min;
}