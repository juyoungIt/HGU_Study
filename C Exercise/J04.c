#include <stdio.h>

int SelectCan(void); //함수 SelectCan의 선언

main()
{
	int price; // 음료의 가격에 대한 값을 저장하는 변수선언
	char more; // 더 주문한 것인지에 대한 응답값을 저장하는 변수선언
	int count = 0; // 음료의 총 갯수 값을 저장하는 변수선언
	int total_price = 0; // 음료의 총 가격을 저장하는 변수선언

	while (1)
	{
		price = SelectCan(); // 함수 SelectCan의 호출
		total_price += price;
		count++;

		printf("더 필요하십니까? : (y / n) : ");
		scanf(" %c", &more);
		if (more == 'y' || more == 'Y')
			continue;
		else if (more == 'n' || more == 'N')
			break;
	}
	printf("\n");
	printf("%d개의 음료를 주문하여 총 %d원 입니다. \n", count, total_price);
	return 0;
}

//함수 SelectCan의 정의부
int SelectCan(void)
{
	int choose; // 사용자가 선택한 것의 번호를 저장하는 변수선언

	printf("1. 콜라(700원), 2. 원두커피(300원), 3. 레몬주스(1000원)\n");
	printf("4. 홍차(500원), 5. 코코아(600원)\n");
	printf("메뉴를 선택해 주세요. : ");
	scanf("%d", &choose);

	if (choose == 1)
		return 700;
	else if (choose == 2)
		return 300;
	else if (choose == 3)
		return 1000;
	else if (choose == 4)
		return 500;
	else if (choose == 5)
		return 600;
}