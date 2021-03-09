#include <stdio.h>

main()
{
	int count[5][3]; // 각 층, 호수 별로 거주자 수를 저장할 2차원 배열 선언
	int f_count[5] = { 0,0,0,0,0 }; // 층별 거주자 수를 저장할 1차원 배열선언 및 초기화
	int n_count[3] = { 0,0,0 }; // 호수별 거주자 수를 저장할 1차원 배열선언 및 초기화
	int total_count = 0; // 총 거주자의 수를 저장할 변수선언 및 초기화
	int i, j; //반복문 사용을 위한 변수선언

	//1. 각 층, 호 별 거주자를 입력받는 부분
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d호 거주자의 수를 입력해 주세요. : ", (i + 1) * 100 + j + 1);
			scanf("%d", &count[i][j]);
		}
	}

	//2. 각 층별 거주자 수를 구하는 부분
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
			f_count[i] += count[i][j];
	}

	//3. 각 호수별 거주자 수를 구하는 부분
	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 5; i++)
			n_count[j] += count[i][j];
	}

	//4. 총 거주자 수를 구하는 부분
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
			total_count += count[i][j];
	}

	//5. 결과를 출력하는 부분
	for (i = 0; i < 5; i++)
	{
		printf("%d층 거주자는 모두 %d명 입니다.\n", i + 1, f_count[i]);
		if (i == 4)
			printf("\n");
	}

	for (j = 0; j < 3; j++)
	{
		printf("%d호 라인 거주자는 모두 %d명 입니다.\n", j + 1, n_count[j]);
		if (j == 2)
			printf("\n");
	}
	printf("그리고 아파트 총 거주자 수는 모두 %d명 입니다. \n", total_count);
	return 0;
}