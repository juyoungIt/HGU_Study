#include <stdio.h>

main()
{
	float score[10]; // 사용자로부터 입력받은 10개의 심사점수를 저장할 배열선언
	float max, min; // 입력받은 점수중 최고점과 최하점의 값을 저장할 변수선언
	float first_total = 0; // 입력받은 심사점수 10개의 합을 저장할 변수선언 및 초기화
	float total = 0; // 최고점과 최하점 제외한 나머지 8개 점수의 총합을 저장할 변수선언 및 초기화
	float average; // 8개 심사점수의 평균에 대한 값을 저장할 변수선언
	int i; // 반복문 사용을 위한 변수선언

	for (i = 0; i < 10; i++)
	{
		printf("%d번째 심사점수를 입력해 주세요. : ",i+1);
		scanf("%f", &score[i]);
	}

	max = score[0];
	for (i = 0; i < 10; i++)
	{
		if (score[i] > max)
			max = score[i];
	}

	min = score[0];
	for (i = 0; i < 10; i++)
	{
		if (score[i] < min)
			min = score[i];
	}

	for (i = 0; i < 10; i++)
	{
		first_total += score[i];
	}

	total = first_total - (max + min);
	average = total / 8.0;

	printf("최고점과 최하점을 제외한 8개 점수에 대한 평균은 %.1f 입니다. \n", average);
	return 0;
}