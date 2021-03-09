#include <stdio.h>

int CalcParking(int s_hour, int s_minute, int e_hour, int e_minute); // 함수 CalcParking의 선언
main()
{
	int s_hour, s_minute; // 시작 시간, 분에 대한 값을 저장하는 변수선언
	int e_hour, e_minute; // 종료 시간, 분에 대한 값을 저장하는 변수선언
	int price; // return 값 (주차요금)의 값을 저장할 변수선언
	int total_price = 0; // 총 주차요금 값을 저장할 변수선언
	char more; // 차량이 더 있는 지에 대한 값을 저장하는 변수선언 (y/n)
	int i; // 반복문 사용을 위한 변수선언

	printf("시간은 24시 기준으로 입력받습니다. (오후 1시 --> 13시) \n");
	printf("\n");
	for (i = 0;; i++)
	{
		printf("\n");
		printf("%d번 차량 주차 시작 시각 (시 / 분) : ", i+1);
		scanf("%d %d", &s_hour, &s_minute);
		printf("%d번 차량 주차 종료 시각 (시 / 분) : ", i+1);
		scanf("%d %d", &e_hour, &e_minute);

		price = CalcParking(s_hour, s_minute, e_hour, e_minute); // 함수 CalcParking의 호출
		printf("주차 요금 : %d원 \n", price);
		total_price += price;

		while (1)
		{
			printf("더 입력 하시겠습니까? (Y / N) : ");
			scanf(" %c", &more);
			if (more == 'y' || more == 'Y')
				break;
			else if (more == 'n' || more == 'N')
				break;
			else
			{
				printf("잘못된 값을 입력하셨습니다. 값을 확인 후 다시 입력해 주세요. \n");
				continue;
			}
		}
		if (more == 'y' || more == 'Y')
			continue;
		else if (more == 'n' || more == 'N')
		{
			printf("주차차량 %d대의 총 주차요금은 %d원 입니다. \n", i + 1, total_price);
			return 0;
		}
	}
}

// 함수 CalcParking의 정의부
int CalcParking(int s_hour, int s_minute, int e_hour, int e_minute)
{
	int first_time; // 첫번째 시간이 0시 0분을 기준으로 몇분 후인지 값을 저장하는 변수선언
	int second_time; // 두번째 시간이 0시 0분을 기준으로 몇분 후인지 값을 저장하는 변수선언
	int period; // 주차한 시간에 대한 값을 저장하는 변수선언
	int price = 0; // 주차 금액에 대한 값을 저장하는 변수선언 

	first_time = s_hour * 60 + s_minute;
	second_time = e_hour * 60 + e_minute;
	period = second_time - first_time;

	price = (period / 10) * 500;
	if (period % 10 != 0)
		price += 500; // 오차보정

	return price;
}