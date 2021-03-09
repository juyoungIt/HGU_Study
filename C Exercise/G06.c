#include <stdio.h>

main()
{
	int order[3]; // 구매하는 제품의 개수를 저장할 1차원 배열 선언
	int sale; // 계산한 판매금액 값을 저장할 변수선언
	int total_sale = 0; // 총 매출액 값을 저장할 변수선언
	int total_order[3] = { 0,0,0 }; // 제품 각각의 총 판매개수를 저장할 변수선언
	int i; // 반복문 사용을 위한 변수선언

	printf("세 종류의 제품(1. 가죽장갑 - 1만원, 2. 털장갑 - 6천원, 3. 비닐장갑 - 3천원)이 있습니다. \n");

	while (1)
	{
		printf("\n");
		for (i = 0; i < 3; i++)
		{
			printf("%d번 제품을 몇개 구매하시겠습니까? : ", i + 1);
			scanf("%d", &order[i]);
			total_order[i] += order[i];
		}
		if (order[0] == 0 && order[1] == 0 && order[2] == 0)
			break;
		sale = 10000 * (order[0]) + 6000 * (order[1]) + 3000 * (order[2]);
		printf("판매금액은 %d원 입니다. \n", sale);
		total_sale += sale;
	}
	printf("\n");
	printf("지금까지 판매한 가죽장갑은 총 %d개 입니다. \n", total_order[0]);
	printf("지금까지 판매한 털장갑은 총 %d개 입니다. \n", total_order[1]);
	printf("지금까지 판매한 비닐장갑은 총 %d개 입니다. \n", total_order[2]);
	printf("지금까지의 총 매출금액은 %d원 입니다. \n", total_sale);
	return 0;
}