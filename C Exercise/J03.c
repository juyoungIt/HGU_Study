#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int GetRandom(void); // 함수 GetRandom의 선언

main()
{
	int i; // 반복문 사용을 위한 변수선언
	int range; // 판정된 범위에 대한 값을 저장하는 변수선언
	int big = 0, middle = 0, small = 0; // 범위에 해당하는 수의 개수값을 저장하는 변수선언
	srand(time(0)); // 랜덤함수를 사용하기 위한 설정

	for (i = 0; i < 10; i++)
	{
		range = GetRandom(); // 함수 GetRandom의 호출
		if (range == 0)
			big++;
		else if (range == 1)
			middle++;
		else if (range == 2)
			small++;
	}

	printf("\n");
	printf("1. 대 (70 이상) : %d\n", big);
	printf("2. 중 (40 이상) : %d\n", middle);
	printf("3. 소 (40 미만) : %d\n", small);
	return 0;
}

// 함수 GetRandom의 정의부
int GetRandom(void)
{
	int number; // 생성된 임의의 수의 값을 저장할 변수선언

	printf("1~100의 수중에서 10개의 수를 생성합니다. \n");

	number = rand() % 100 + 1; // 임의의 수 생성
	printf("생성된 임의의 숫자는 %d입니다. \n", number);

	if (number >= 70)
		return 0;
	else if (number < 70 && number >= 40)
		return 1;
	else if (number < 40)
		return 2;
}