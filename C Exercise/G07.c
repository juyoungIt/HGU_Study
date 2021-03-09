#include <stdio.h>

main()
{
	int team_count; // 팀의 수를 저장할 변수선언
	int charge[4] = { 5000,10000,15000,3000 }; // 인원구성별 입장료 값을 저장한 1차원 배열선언
	int count[4]; // 각 팀당 인원구성별 수를 저장할 1차원 배열선언
	int v_count[4] = { 0 }; // 모든 팀 각각의 인원구성별 수를 저장할 1차원 배열선언
	int total_count = 0; // 총 방문자 수 값을 저장할 변수선언
	int pay; // 각팀이 계산한 값을 저장할 변수선언
	int total_pay = 0; // 총 입장료 값을 저장할 변수선언
	int membership; // 할인카드종류 값을 저장할 변수선언
	int i, j; // 반복문 사용을 위한 변수선언

	printf("오늘 방문한 팀의 수를 입력해 주세요. : ");
	scanf("%d", &team_count);

	for (i = 0; i < team_count; i++)
	{
		pay = 0;
		printf("%d번 팀 인원수를 초등학생, 청소년, 일반인, 경로대상 순서로 입력해 주세요. : ", i + 1);
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &count[j]);
			v_count[j] += count[j];
			total_count += count[j];
		}
		printf("%d번 팀 할인카드 종류를 입력해 주세요. (카드없음 - 0, 일반카드 - 1, VIP카드 - 2) : ", i + 1);
		scanf("%d", &membership);
		for (j = 0; j < 4; j++)
			pay += (charge[j] * count[j]);
		if (membership == 1)
			pay = (float)pay * 0.9;
		else if (membership == 2)
			pay = (float)pay * 0.8;

		printf("%d번 팀 입장료는 %d원 입니다. \n", i+1, pay);
		total_pay += pay;
		printf("\n");
	}
	printf("오늘 총 방문자 수는 %d명 입니다. \n", total_count);
	printf("초등학생 수는 %d명 입니다. \n", v_count[0]);
	printf("청소년 수는 %d명 입니다. \n", v_count[1]);
	printf("일반인 수는 %d명 입니다. \n", v_count[2]);
	printf("경로대상 수는 %d명 입니다. \n", v_count[3]);
	printf("\n");
	printf("총 입장료는 %d원 입니다. \n", total_pay);
	return 0;
}