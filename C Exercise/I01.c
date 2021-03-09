#include <stdio.h>

void ShowMenu(); // 함수 ShowMenu의 선언

main()
{
	int choose; // 사용자의 선택에 대한 값을 저장하는 변수선언
	int total = 0; // 선택한 메뉴의 총 합계금액의 값을 저장하는 변수선언

	while (1)
	{
		ShowMenu(); // 함수 ShowMenu 호출
		printf("메뉴를 선택해 주세요. (종료 : 5) : ");
		scanf("%d", &choose);
		if (choose == 1)
		{
			total += 15000;
			printf("현제까지의 주문금액은 모두 %d원 입니다. \n", total);
			printf("\n");
		}
		else if (choose == 2)
		{
			total += 10000;
			printf("현제까지의 주문금액은 모두 %d원 입니다. \n", total);
			printf("\n");
		}
		else if (choose == 3)
		{
			total += 7000;
			printf("현제까지의 주문금액은 모두 %d원 입니다. \n", total);
			printf("\n");
		}
		else if (choose == 4)
		{
			total += 2000;
			printf("현제까지의 주문금액은 모두 %d원 입니다. \n", total);
			printf("\n");
		}
		else if (choose == 5)
			break;
		else
		{
			printf("입력하신 값이 유효하지 않습니다. 다시 입력해 주세요. \n");
			printf("\n");
			continue;
		}
	}
	printf("\n");
	printf("선택하신 메뉴의 총 합계금액은 %d원 입니다. \n", total);
	return 0;
}

// 함수 ShowMenu의 정의부
void ShowMenu()
{
	printf("1. 피자(15,000원), 2. 스파게티(10,000원), 3. 샐러드(7,000원), 4. 음료수(2,000원)");
	return;
}