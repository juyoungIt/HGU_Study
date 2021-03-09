#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int result_number[6] = { 0 }; // 당첨번호 값을 저장하는 1차원 배열선언
	int input_number[6] = { 0 }; // 사용자가 입력한 번호 값을 저장하는 1차원 배열선언
	int result = 0; // 맞춘 번호의 개수를 저장하는 변수선언
	int count = 0; // 현재 만들어지고 있는 번호의 순서값을 저장하는 변수선언
	int i; // 반복문 사용을 위한 변수선언

	srand(time(0)); // 랜덤함수를 사용하기 위한 준비

	// 컴퓨터가 로또번호 생성
	result_number[0] = rand() % 45 + 1; // 1차 당첨번호 생성
	count++;
	while (1)
	{
		// n차 당첨번호 생성 및 중복검사과정
		for (i = 0; i < count; i++)
		{
			result_number[count] = rand() % 45 + 1;
			if (result_number[count] == result_number[i])
				break;
		}
		if (i == count)
			count++;
		if (count == 6)
			break;
	}

	// 사용자의 로또번호를 입력
	count = 0;
	printf("원하는 %d번째 로또 숫자를 입력하세요. : ", count+1);
	scanf("%d", &input_number[0]); // 1차 사용자 번호 입력받음
	count++;
	//n차 사용자 번호 입력 및 중복검사과정
	while (1)
	{
		printf("원하는 %d번째 로또 숫자를 입력하세요. : ", count + 1);
		scanf("%d", &input_number[count]);
		for (i = 0; i < count; i++)
		{
			if (input_number[count] == input_number[i])
			{
				printf("=> 잘못 입력하셨습니다. \n");
				break;
			}
		}
		if (i == count)
			count++;
		if (count == 6)
			break;
	}

	// 번호의 일치여부 판단
	count = 0;
	while (1)
	{
		for (i = 0; i < 6; i++)
		{
			if (result_number[count] == input_number[i])
				result++;
		}
		count++;
		if (count == 6)
			break;
	}

	//결과 출력
	printf("\n");
	printf("이번 주의 로또당첨 번호는 %4d", result_number[0]);
	for (i = 1; i < 6; i++)
		printf("%4d", result_number[i]);
	printf(" 입니다. \n");
	printf("\n");
	printf("일치하는 로또번호는 %d개 입니다. \n", result);
	return 0;
}