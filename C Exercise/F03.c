#include <stdio.h>

main()
{
	int score[5][3]; // 5명의 각각 3과목 점수값을 저장할 2차원 배열 선언
	int total[3];// 각각 세 과목의 총점을 저장할 배열선언 및 초기화
	total[0] = 0;
	total[1] = 0;
	total[2] = 0;
	float average[3]; // 각각 세 과목의 평균을 저장할 배열선언
	int i, j; //반복문 사용을 위한 변수선언

	for (i = 0; i < 5; i++)
	{
		printf("%d번째 학생의 국어, 영어, 수학 점수를 차례대로 입력해 주세요. : ", i + 1);
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &score[i][j]);
		}
	}

	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 5; i++)
		{
			total[j] += score[i][j];
		}
	}

	for (j = 0; j < 3; j++)
	{
		average[j] = total[j] / 5.0;
	}

	for (j = 0; j < 3; j++)
	{
		printf("국어의 총점은 %d이고, 평균은 %.1f 입니다. \n", total[j], average[j]);
	}
	return 0;
}