#include <stdio.h>

main()
{
	float input_degree[10]; // 물의 온도값을 저장할 1차원 배열선언
	int count1 = 0; // 냉수의 입력횟수를 저장할 변수선언
	int count2 = 0; // 미온수의 입력횟수를 저장할 변수선언
	int count3 = 0; // 온수의 입력횟수를 저장할 변수선언
	int count4 = 0; // 끓는 물의 입력횟수를 저장할 변수선언
	int i; // 반복문을 사용하기 위한 변수선언

	printf("본 프로그렘에서 물의 온도는 영상 값 만을 지원합니다. \n");
	for (i = 0; i < 10; i++)
	{
		printf("%d번 물의 온도를 입력해 주세요. : ", i + 1);
		scanf("%f", &input_degree[i]);

		if (input_degree[i] >= 0 && input_degree[i] < 25)
			count1++;
		else if (input_degree[i] >= 25 && input_degree[i] < 40)
			count2++;
		else if (input_degree[i] >= 40 && input_degree[i] < 80)
			count3++;
		else if (input_degree[i] >= 80)
			count4++;
		else
			printf("조건을 만족하는 유효한 값이 아닙니다.\n");
	}

	for (i = 0; i < 10; i++)
		printf("%d번째 물의 온도는 %.1f도 입니다. \n", i + 1, input_degree[i]);

	printf("냉수의 입력횟수는 %d회 입니다. \n", count1);
	printf("미온수의 입력횟수는 %d회 입니다. \n", count2);
	printf("온수의 입력횟수는 %d회 입니다. \n", count3);
	printf("끓는 물의 입력횟수는 %d회 입니다. \n", count4);
	return 0;
}