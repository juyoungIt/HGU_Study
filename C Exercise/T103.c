#include <stdio.h>

main()
{
	int price;
	int pay_type;
	int point;

	printf("식사 금액을 입력해 하시오. : ");
	scanf("%d", &price);
	printf("지불 방식을 입력해 주세요.(현금-1, VIP카드-2, 체크카드-3, 신용카드-4) : ");
	scanf("%d", &pay_type);

	if (pay_type == 1)
		point = price*0.015;
	else if (pay_type == 2)
		point = price*0.02;
	else if (pay_type == 3)
		point = price*0.01;
	else if (pay_type == 4)
		point = price*0.005;

	printf("적립된 포인트는 %d원 입니다. \n", point);
	return 0;

}