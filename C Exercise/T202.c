#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sum_array(int size, int numbers[]);

main()
{
	int numbers[10]; // 임의로 추출한 수를 저장
	int result; // 결과값 저장
	int i; // 반복문 사용을 위한 준비
	srand(time(0)); // 랜덤함수사용 준비

	printf("10 Random generated numbers : ");
	for (i = 0; i < 10; i++)
	{
		numbers[i] = rand() % 99 + 1;
		printf("%4d", numbers[i]);
	}
	printf("\n");

	result = sum_array(10, numbers);
	printf("Sum : %d\n", result);
	return 0;
}

int sum_array(int size, int numbers[])
{
	if (size <= 0)
		return 0;
	else
		return sum_array(size - 1, numbers) + numbers[size-1];
}