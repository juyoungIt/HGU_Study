#include <stdio.h>

int Askwater(float degree); // 함수 Askwater의 선언

main()
{
	float degree[10]; // 사용자가 입력한 물의 온도값을 저장하는 1차원 배열선언
	int count0 = 0; // return 값이 0인 횟수를 저장하는 변수선언
	int count1 = 0; // return 값이 1인 횟수를 저장하는 변수선언
	int count2 = 0; // return 값이 2인 횟수를 저장하는 변수선언
	int count3 = 0; // return 값이 3인 횟수를 저장하는 변수선언
	int result; // return 값을 저장하는 변수선언
	int i; // 반복문 사용을 위한 변수선언

	// 물의 온도를 입력 및 판정
	for (i = 0; i < 10; i++)
	{
		printf("%d번째 물의 온도를 섭씨 단위로 입력해 주세요. : ", i + 1);
		scanf("%f", &degree[i]);
		result = Askwater(degree[i]); // 함수 Askwater의 호출

		if (result == 0)
			count0++;
		else if (result == 1)
			count1++;
		else if (result == 2)
			count2++;
		else if (result == 3)
			count3++;
	}

	printf("\n");
	// 판정 및 결과를 출력하는 부분
	for (i = 0; i < 10; i++)
		printf("%d번 물의 온도는 %.1f도 입니다. \n", i + 1, degree[i]);

	printf("\n");
	printf("냉수의 입력횟수는 %d회 입니다. \n", count0);
	printf("미온수의 입력횟수는 %d회 입니다. \n", count1);
	printf("온수의 입력횟수는 %d회 입니다. \n", count2);
	printf("끓는 물의 입력횟수는 %d회 입니다. \n", count3);
	return 0;
}

// 함수 Askwater의 정의부
int Askwater(float degree)
{
	if (degree >= 0 && degree < 25)
		return 0;
	else if (degree >= 25 && degree < 40)
		return 1;
	else if (degree >= 40 && degree < 80)
		return 2;
	else if (degree >= 80)
		return 3;
}