#include <stdio.h>

main()
{
	int hour, minute; // 시간과 분에 대한 값을 저장하는 변수선언
	int charge; // 이용료에 대한 값을 저장하는 변수선언
	int total_charge = 0; // 이용료 총액 값을 저장하는 변수선언

	while (1)
	{
		printf("사용한 시간을 시간과 분으로 입력해 주세요.(예 1시간 20분 --> 1 20) : ");
		scanf("%d %d", &hour, &minute);

		if (hour >= 2 && hour < 3)
		{
			charge = 2000 * hour + 1000 * (1 + minute / 31);
			if (minute == 0)
				charge -= 1000; // 오차값 보정
			charge = (float)charge * 0.95;
			printf("고객님의 이용료는 %d원 입니다. \n", charge);
			total_charge += charge;
		}
		else if (hour >= 3 && hour < 5)
		{
			charge = 2000 * hour + 1000 * (1 + minute / 31);
			if (minute == 0)
				charge -= 1000; // 오차값 보정
			charge = (float)charge * 0.9;
			printf("고객님의 이용료는 %d원 입니다. \n", charge);
			total_charge += charge;
		}
		else if (hour >= 5)
		{
			charge = 2000 * hour + 1000 * (1 + minute / 31);
			if (minute == 0)
				charge -= 1000; // 오차값 보정
			charge = (float)charge * 0.8;
			printf("고객님의 이용료는 %d원 입니다. \n", charge);
			total_charge += charge;
		}
		else if (hour == 0 && minute == 0)
			break;
		else
		{
			charge = 2000 * hour + 1000 * (1 + minute / 31);
			printf("고객님의 이용료는 %d원 입니다. \n", charge);
			if (minute == 0)
				charge -= 1000; // 오차값 보정
			total_charge += charge;
		}
	}
	printf("\n");
	printf("지금까지의 이용료 총 금액은 %d원 입니다. \n", total_charge);
	return 0;
}