#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int coins; // 사용자가 입력한 코인의 수를 저장할 변수선언
	int number[3]; // 랜덤하게 만들어질 슬롯머신의 수를 저장할 1차원 배열선언
	int dummy; // 게임 스타트를 위한 의미없는 입력숫자
	int i,j; // 반복문 사용을 위한 변수선언

	srand(time(0)); // 랜덤함수를 사용하기 위한 설정

	// 1. 사용자에게 코인의 개수를 입력받음
	printf("사용하실 코인의 개수를 입력해 주세요. : ");
	scanf("%d", &coins); j = 1;

	while(1)
	{
		printf("게임 %d회 Start!!! (아무 숫자나 입력하세요.) : ", j);
		scanf("%d", &dummy); j++;

		// 2. 슬롯머신에서 임의의 수 3개를 생성함.
		for (i = 0; i < 3; i++)
			number[i] = rand() % 9 + 1;

		// 3. 결과를 출력 및 판정하고 사용자에게 보상함.
		printf("게임결과 : %4d", number[0]);
		for (i = 1; i < 3; i++)
			printf("%4d", number[i]);

		if (number[0] == number[1] && number[1] == number[2] && number[0] == number[2])
		{
			printf("   ===>   축하합니다! 숫자 3개 일치!! ===> 코인 4개 증정 ... \n");
			coins += 4;
			coins--;
			printf("남아있는 코인은 모두 %d개 입니다. \n", coins);
		}
		else if(number[0] != number[1] && number[1] != number[2] && number[0] != number[2])
		{
			printf("   ===>   꽝입니다... 아쉽군요... \n");
			coins--;
			printf("남아있는 코인은 모두 %d개 입니다. \n", coins);
		}
		else
		{
			printf("   ===>   축하합니다! 숫자 2개 일치! ===> 코인 2개 증정 ... \n");
			coins += 2;
			coins--;
			printf("남아있는 코인은 모두 %d개 입니다. \n", coins);
		}

		if (coins == 0)
		{
			printf("\n");
			printf("코인을 모두 소진하였습니다. 게임종료! \n");
			printf("\n");
			break;
		}
	}
	return 0;
}