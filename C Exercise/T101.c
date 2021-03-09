#include <stdio.h>

main()
{
	int price;
	int point;

	printf("식사금액을 입력해 주세요. : ");
	scanf("%d", &price);

	point = price*0.015;

	printf("적립된 포인트는 %d원 입니다. \n", point);
	return 0;
}