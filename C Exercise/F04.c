#include <stdio.h>

main()
{
	int score[5][3]; // 5명 학생의 각 3과목의 점수를 저장할 2차원 배열 선언
	int total[5] = { 0,0,0,0,0 }; // 5명 학생 각각의 총점을 저장한 1차원 배열 선언 및 원솟값 초기화
	float average[5]; // 5명 학생 각각의 평균을 저장한 1차원 배열 선언
	int i, j; // 반복문 사용을 위한 변수선언

	//1. 점수값을 입력받는 부분
	for (i = 0; i < 5; i++)
	{
		printf("%d번 학생의 국어, 영어, 수학 점수를 차례대로 입력해 주세요. : ", i + 1);
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &score[i][j]);
		}
	}

	//2. 5명 학생 각각의 총점을 구하는 부분
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 5; i++)
		{
			total[i] += score[i][j];
		}
	}

	//3. 5명 학생 각각의 평균을 구하는 부분
	for (i = 0; i < 5; i++)
	{
		average[i] = total[i] / 3.0;
	}

	//4. 결과값을 출력하는 부분
	for (i = 0; i < 5; i++)
	{
		printf("%d번째 학생의 총점은 %d점 이고, 평균은 %.1f점 입니다. \n", i + 1, total[i], average[i]);
	}
	return 0;
}