#include <stdio.h>

main()
{
	int height[10]; // 10명의 키에 대한 값을 저장할 1차원 배열선언
	int weight[10]; // 10명의 체중에 대한 값을 저장할 1차원 배열선언
	float bmi[10]; // 10명의 비만도 수치를 저장할 1차원 배열선언
	int count = 0; // 비만자의 수 값을 저장할 변수선언 및 초기화
	int i; //반복문을 사용하기 위한 변수선언

	//1. 키와 체중에 대한 값을 입력받는 부분
	for (i = 0; i < 10; i++)
	{
		printf("%d번째 사람의 신장(cm단위)과 체중(kg단위)을 순서대로 입력해 주세요. : ", i+1);
		scanf("%d %d", &height[i], &weight[i]);
	}

	//2. 10명의 비만도를 각각 계산하는 부분
	for (i = 0; i < 10; i++)
	{
		bmi[i] = weight[i] / ((height[i]*0.01)*(height[i] * 0.01));
	}

	//3. 10명의 비만도에 대한 값을 판정하는 부분
	for (i = 0; i < 10; i++)
	{
		if (bmi[i] >= 25)
		{
			printf("%d번째 사람은 bmi수치 %.1f로 비만으로 판정되었습니다. \n", i + 1, bmi[i]);
			count++;
		}
	}
	printf("\n");
	printf("비만으로 판정된 사람 수는 총 %d명 입니다. \n", count);
	return 0;
}