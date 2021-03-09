#include <stdio.h>

main()
{
	int count[5][3]; // 각 층, 호 별로 거주자의 수를 저장할 2차원 배열 선언
	int total_count = 0; // 아파트에 거주하고 있는 사람의 수를 저장할 변수선언 및 초기화
	int number; // 아파트 호수에 대한 값을 저장할 변수선언
	int i, j; // 반복문을 사용하기 위한 변수선언

			  //1. 각 층, 호 별로 거주자의 수를 입력받는 부분
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d호에 살고 있는 사람의 수를 입력해 주세요. : ", (i + 1) * 100 + j + 1);
			scanf("%d", &count[i][j]);
		}
	}

	//2. 아파트에 거주하고 있는 사람의 수를 구하는 부분
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 3; j++)
		{
			total_count += count[i][j];
		}
	}

	//3. 결과값을 출력하는 부분
	printf("따라서 해당 아파트의 거주자는 모두 %d명 입니다. \n", total_count);
	return 0;
}