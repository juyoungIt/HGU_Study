#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int number[5]; // 사용자로부터 입력받은 5개의 수를 저장할 1차원 배열선언
	int pow_value[5][5]; // 임의의 두 수 a,b로 만들 수 있는 a^b의 값들을 저장할 2차원 배열선언
	int max, min; // 최대값과 최솟값을 저장할 변수선언
	int a, b; // 랜덤으로 추출된 값을 저장하여 전달하기 위한 변수선언
	int max_a, max_b; // 최댓값을 만들어 내는 경우의 a와 b의 값을 저장할 변수선언
	int min_a, min_b; // 최솟값을 만들어 낸는 경우의 a와 b의 값을 저장할 변수선언
	int i, j; // 반복문 사용을 위한 변수선언
	srand(time(0)); // 랜덤함수를 사용하기 위한 설정

	// 1. 사용자로부터 5개의 수를 입력받는다.
	printf("2 ~ 9 사이의 수 중에서 5개를 선택하여 입력해 주세요. : ");
	for (i = 0; i < 5; i++)
		scanf("%d", &number[i]);

	// 2. 5개의 숫자중 임의의 a, b를 선택하여서 a^b의 값을 계산 & 최대최소 선발
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			a = number[rand() % 5];
			b = number[rand() % 5];
			// 중복되는 다음 연산을 진행하지 않음.
			if (a == b)
				continue;
			pow_value[i][j] = pow(a, b);
			// 맨 처음 부분은 비교없이 값을 집어넣음
			if (i == 0 && j == 0)
			{
				max = pow_value[i][j];
				max_a = a; max_b = b;
				min = pow_value[i][j];
				min_a = a; min_b = b;
			}
			// 이후 들어오는 수들은 대소여부 및 중복여부를 체크함
			else
			{ 
				if (max < pow_value[i][j])
				{
					max = pow_value[i][j];
					max_a = a; max_b = b;
				}
				if (min > pow_value[i][j])
				{
					min = pow_value[i][j];
					min_a = a; min_b = b;
				}
			}
		}
	}
	//3. 결과를 출력
	printf("\n");
	printf("입력하신 5개의 수로 제곱수를 만들면 ... \n");
	printf("가장 큰 수는 %d의 %d승인 %d입니다. \n", max_a, max_b, max);
	printf("가장 작은 수는 %d의 %d승인 %d입니다. \n", min_a, min_b, min);
	return 0;
}