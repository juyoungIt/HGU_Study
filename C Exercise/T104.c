#include <stdio.h>

main()
{
	int price;
	int pay_type;
	int h_point = 0;
	int v_point = 0;
	int c_point = 0;
	int s_point = 0;
	int total_points = 0;

	while (1)
	{
		printf("식사금액과 지불방법을 입력하세요.(현금-1, VIP카드-2, 체크카드-3, 신용카드-4) : ");
		scanf("%d %d", &price, &pay_type);

		if (price <= 0)
			break;
		if (pay_type == 1)
			h_point = h_point + price*0.015;
		else if (pay_type == 2)
			v_point = v_point + price*0.02;
		else if (pay_type == 3)
			c_point = c_point + price*0.01;
		else if (pay_type == 4)
			s_point = s_point + price*0.005;
	}
	total_points = h_point + v_point + c_point + s_point;

	printf("지불 방법에 따라서 적립된 포인트는 다음과 같습니다. \n");
	printf("현금 - %d원, VIP카드 - %d원, 체크카드 - %d원, 신용카드 - %d원 \n", h_point, v_point, c_point, s_point);
	printf("총 적립된 포인트는 %d원 입니다. \n", total_points);
	return 0;
}