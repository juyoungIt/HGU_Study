#include <stdio.h>

void sort3num(int * number1, int * number2, int * number3);

main()
{
	int num1, num2, num3; // 사용자로부터 입력받은 수를 저장하는 변수선언

	printf("숫자 3개를 입력하시오. : ");
	scanf("%d %d %d", &num1, &num2, &num3);

	printf("(before) : %d %d %d\n", num1, num2, num3);
	sort3num(&num1, &num2, &num3);
	printf("(after) : %d %d %d\n", num1, num2, num3);
	return 0;
}

void sort3num(int * number1, int * number2, int * number3)
{
	int temp; // swap의 과정에서 사용하기 위한 변수선언
	//1. number1의 값이 가장 클 때
	if (*number1 > *number2 && *number1 > *number3 && *number3 > *number2)
	{
		temp = *number2;
		*number2 = *number3;
		*number3 = temp;
	}//2. number2의 값이 가장 클 때
	else if (*number2 > *number1 && *number2 > *number3 && *number3 < *number1)
	{
		temp = *number1;
		*number1 = *number2;
		*number2 = temp;
	}
	else if (*number2 > *number1 && *number2 > *number3 && *number3 > *number1)
	{
		// 1. 1차 swap
		temp = *number1;
		*number1 = *number2;
		*number2 = temp;
		// 2. 2차 swap
		temp = *number3;
		*number3 = *number2;
		*number2 = temp;
	}//3. number3의 값이 가장 클 때
	else if (*number3 > *number1 && *number3 > *number2 && *number1 > *number2)
	{
		// 1. 1차 swap
		temp = *number1;
		*number1 = *number3;
		*number3 = temp;
		// 2. 2차 swap
		temp = *number2;
		*number2 = *number3;
		*number3 = temp;
	}
	else if (*number3 > *number1 && *number3 > *number2 && *number1 < *number2)
	{
		temp = *number1;
		*number1 = *number3;
		*number3 = temp;
	}
	return;
}