#include <stdio.h>

void AskBiman(int height, int weight); // 함수 AskBiman의 선언

main()
{
	int height; // 키에 대한 값을 저장하는 변수선언
	int weight; // 체중에 대한 값을 저장하는 변수선언
	int i; // 반복문 사용을 위한 변수선언

	for (i = 0; i < 10; i++)
	{
		printf("%d번째 사람의 신장(cm)과 체중(kg)을 순서대로 입력해 주세요. : ", i+1);
		scanf("%d %d", &height, &weight);
		AskBiman(height, weight);
	}
	return 0;
}

// 함수 AskBiman의 정의부
void AskBiman(int height, int weight)
{
	float result; // 비만도 판정결과 값을 저장할 변수선언
	result = weight / ((height*0.01)*(height*0.01));
	if (result < 18.5)
		printf("비만도 수치는 %.1f이며, '저체중'으로 판정되었습니다. \n", result);
	else if (result >= 18.5 && result < 23)
		printf("비만도 수치는 %.1f이며, '정상체중'으로 판정되었습니다. \n", result);
	else if (result >= 23 && result < 25)
		printf("비만도 수치는 %.1f이며, '과체중'으로 판정되었습니다. \n", result);
	else if (result >= 25 && result < 30)
		printf("비만도 수치는 %.1f이며, '경도비만'으로 판정되었습니다. \n", result);
	else if (result >= 30)
		printf("비만도 수치는 %.1f이며, '고도비만'으로 판정되었습니다. \n", result);
	else
		printf("입력된 값이 유효하지 않습니다. 입력한 값을 확인해주세요. \n");
	return;
}