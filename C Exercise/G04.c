#include <stdio.h>

main()
{
	int kind; // 거래 종류에 대한 값을 저장할 변수선언
	int money; // 거래 금액에 대한 값을 저장할 변수선언
	int charge; // 중개 수수료 값을 저장할 변수선언
	int sum_charge = 0; // 중개 수수료 총액을 저장할 변수선언

	while (1)
	{
		printf("부동산 거래종류 (1:매매, 2:임대, 0:계산종료)를 입력해 주세요. : ");
		scanf("%d", &kind);
		if (kind == 0)
			break;
		printf("부동산 거래금액(원)을 입력하세요. : ");
		scanf("%d", &money);
		

		if (kind == 1)
		{
			if (money >= 0 && money < 50000000)
			{
				charge = money*0.006;
				if (charge > 250000)
					charge = 250000;
				printf("이에 대한 중계 수수료는 %d원 입니다. \n", charge);
				sum_charge += charge;
			}
			else if (money >= 50000000 && money < 200000000)
			{
				charge = money*0.005;
				if (charge > 800000)
					charge = 800000;
				printf("이에 대한 중계 수수료는 %d원 입니다. \n", charge);
				sum_charge += charge;
			}
			else if (money >= 200000000)
			{
				charge = money*0.004;
				printf("이에 대한 중계 수수료는 %d원 입니다. \n", charge);
				sum_charge += charge;
			}
			else
			{
				printf("입력된 금액 값이 유효하지 않습니다. 값을 확인 후 다시 입력해 주세요. \n");
				return 0;
			}
		}
		else if (kind == 2)
		{
			if (money >= 0 && money < 20000000)
			{
				charge = money*0.005;
				if (charge > 70000)
					charge = 70000;
				printf("이에 대한 중계 수수료는 %d원 입니다. \n", charge);
				sum_charge += charge;
			}
			else if (money >= 20000000 && money < 50000000)
			{
				charge = money*0.005;
				if (charge > 200000)
					charge = 200000;
				printf("이에 대한 중계 수수료는 %d원 입니다. \n", charge);
				sum_charge += charge;
			}
			else if (money >= 50000000 && money < 100000000)
			{
				charge = money*0.004;
				if (charge > 300000)
					charge = 300000;
				printf("이에 대한 중계 수수료는 %d원 입니다. \n", charge);
				sum_charge += charge;
			}
			else if (money >= 100000000)
			{
				charge = money*0.003;
				printf("이에 대한 중계 수수료는 %d원 입니다. \n", charge);
				sum_charge += charge;
			}
			else
			{
				printf("입력된 금액 값이 유효하지 않습니다. 값을 확인 후 다시 입력해 주세요. \n");
				return 0;
			}
		}
	}
	printf("지금까지의 수수료 총액은 %d원 입니다. \n", sum_charge);
	return 0;
}