#include <stdio.h>

main()
{
	int number[10]; // 사용자로부터 입력받은 1~100 사이의 10개의 수를 저장할 변수선언
	int count = 0; // 입력된 유효한 수의 갯수를 저장하는 변수선언 및 초기화
	int i; // 반복문 사용을 위한 변수선언 및 초기화

	//1. 사용자에게 입력값의 조건 제시
	printf("1부터 100사이의 숫자를 입력해 주세요. \n");
	//2. 사용자에게 첫번째 값 입력을 요구하는 부분
	printf("%d번째 숫자를 입력해 주세요. : ", count+1);
	scanf("%d", &number[count]);
	count++;
	while (1)
	{
		printf("%d번째 숫자를 입력해 주세요. : ", count+1);
		scanf("%d", &number[count]);
		for (i = 0; i < count; i++)
		{
			if (number[count] == number[i])
			{
				printf("입력하셨던 수들 중에 같은 수가 있습니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
				break;
			}
		}
		if (i == count)
			count++;
		if (count == 10)
			break;
	}
	//4. 결과를 출력하는 부분
	for (i = 0; i < 10; i++)
	{
		printf("%d번째 숫자는 %d 입니다. \n", i+1, number[i]);
	}
	return 0;
}