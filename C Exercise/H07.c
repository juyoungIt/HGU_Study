#include <stdio.h>
#include <math.h>

main()
{
	int number[10]; // 사용자로부터 입력받은 1에서 100사이의 수를 저장하는 1차원 배열선언
	int total_sum = 0; // 사용자로부터 입력받은 수의 총합을 저장하는 변수선언
	float average; // 사용자로부터 입력받은 수의 평균을 저장하는 변수선언
	float bunsan[10]; // 분산의 값을 저장하는 변수선언
	float total_bunsan = 0; // 분산의 총합을 저장하는 변수선언
	float average_bunsan; // 분산의 평균을 저장하는 변수선언
	float std_dev; // 표준편차의 값을 저장하는 변수선언
	int i; // 반복문 사용을 위한 변수선언

	printf("1에서 100사이의 숫자 10개를 입력해 주세요. : ");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &number[i]);
		total_sum += number[i];
	}
	average = total_sum / 10.0;
	printf("\n");
	printf("입력하신 수들의 총합은 %d, 평균은 %.1f입니다.", total_sum, average);

	for (i = 0; i < 10; i++)
		bunsan[i] = (number[i] - average) * (number[i] - average);

	printf("\n");
	printf("분산은 다음과 같습니다. \n");
	for (i = 0; i < 10; i++)
	{
		printf("%.1f", bunsan[i]);
		printf(" ");
		total_bunsan += bunsan[i];
	}
	average_bunsan = total_bunsan / 10.0;
	std_dev = sqrt(average_bunsan);

	printf("\n");
	printf("분산의 평균은 %.1f, 표준편차는 %.1f입니다. \n", average_bunsan, std_dev);
	return 0;
}