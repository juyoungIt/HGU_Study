#include <stdio.h>

main()
{
	int price;
	int pay_type;
	int point;

	printf("식사금액을 입력하시오. : ");
	scanf("%d", &price);
	printf("지불 방식을 결정해 주세요. (현금 - 1, 카드 - 2) : ");
	scanf("%d", &pay_type);

	if (pay_type == 1)
		point = price*0.015;
	else if (pay_type == 2)
		point = price*0.005;

	printf("적립된 포인트는 %d원 입니다. \n", point);
	return 0;
}