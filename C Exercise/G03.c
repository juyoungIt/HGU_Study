#include <stdio.h>

main()
{
	int score[5][3]; // 5명의 학생의 각 3과목의 점수를 저장할 2차원 배열선언
	int total_class[3] = { 0,0,0 }; // 과목별 총점의 값을 저장할 1차원 배열선언
	float C_average[3]; // 과목별 평균값을 저장할 1차원 배열선언
	int total_student[5] = { 0,0,0,0,0 }; // 각 학생들의 총점을 저장할 1차원 배열선언
	float S_average[5]; // 각 학생들의 평균을 저장할 1차원 배열선언
	char grade[5]; // 각 학생들의 등급을 저장할 1차원 배열선언
	int i, j; // 반복문 사용을 위한 변수선언

	//1. 점수를 입력받는 부분
	for (i = 0; i < 5; i++)
	{
		printf("%d번 학생의 국어, 영어, 수학 점수를 차례대로 입력해 주세요. : ", i+1);
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &score[i][j]);
		}
	}

	//2. 과목별 총점 및 평균을 구하는 부분
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 5; i++)
		{
			total_class[j] += score[i][j];
		}
	}
	for (j = 0; j < 3; j++)
	{
		C_average[j] = total_class[j] / 5.0;
	}

	//3. 학생별 총점 및 평균을 구하는 부분
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			total_student[i] += score[i][j];
		}
	}
	for (i = 0; i < 5; i++)
	{
		S_average[i] = total_student[i] / 3.0;
	}

	//4. 학생별 등급을 판단하는 과정
	for (i = 0; i < 5; i++)
	{
		if (S_average[i] >= 90)
			grade[i] = 'A';
		else if (S_average[i] >= 80 && S_average[i] < 90)
			grade[i] = 'B';
		else if (S_average[i] >= 70 && S_average[i] < 80)
			grade[i] = 'C';
		else if (S_average[i] >= 60 && S_average[i] < 70)
			grade[i] = 'D';
		else
			grade[i] = 'F';

	}

	//5. 결과를 출력하는 부분
	printf("1) 각 과목별 총점과 평균점수 \n");
	printf("국어점수의 총점은 %d점 이고, 평균점수는 %.1f 입니다. \n", total_class[0], C_average[0]);
	printf("영어점수의 총점은 %d점 이고, 평균점수는 %.1f 입니다. \n", total_class[1], C_average[1]);
	printf("수학점수의 총점은 %d점 이고, 평균점수는 %.1f 입니다. \n", total_class[2], C_average[2]);

	printf("2) 각 학생별 총점과 평균점수, 평균에 따른 등급 \n");
	for (i = 0; i < 5; i++)
	{
		printf("%d번 학생의 총점은 %d점 이고, 평균은 %.1f (등급 %c)입니다. \n", i + 1, total_student[i], S_average[i], grade[i]);
	}
	return 0;
}