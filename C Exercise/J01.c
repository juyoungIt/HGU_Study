#include <stdio.h>

int SelectMenu(void); // 함수 SelectMenu의 선언

main()
{
	int total_price = 0; // 총 가격의 값을 저장할 변수선언
	int price; // 가격에 대한 값을 저장할 변수선언

	while (1)
	{
		price = SelectMenu(); // 함수 SelectMenu의 호출
		if (price == -1)
			break;
		total_price += price;
		printf("현제까지의 주문금액은 %d원 입니다. \n", total_price);
	}
	printf("\n");
	printf("총 주문 금액은 %d원 입니다. \n", total_price);
	return 0;
}

// 함수 SelectMenu의 정의부
int SelectMenu(void)
{
	int number; // 사용자가 입력한 번호를 저장할 변수선언

	printf("1. 피자(15,000원), 2. 스파게티(10,000원), 3. 샐러드(7,000원), 4. 음료수(2,000원)\n");
	printf("메뉴를 선택해 주세요. (종료 - 5) : ");
	scanf("%d", &number);
	if (number == 1)
		return 15000;
	else if (number == 2)
		return 10000;
	else if (number == 3)
		return 7000;
	else if (number == 4)
		return 2000;
	else if (number == 5)
		return -1;
	else
	{
		printf("유효한 값이 아닙니다. 입력하신 값을 확인 후 다시 입력해 주세요. : ");
		return 0;
	}
}