#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int s_user[5]; // 사용자가 입력한 순서값 저장
	int s_com[5]; // 컴퓨터가 선정한 순서값 저장
	int count = 0; // 컴퓨터가 몇번째 순서를 결정했는 지를 저장
	int com_win = 0, user_win = 0; // 컴퓨터와 사용자의 승리횟수 저장
	int com_draw = 0, user_draw = 0; // 컴퓨터와 사용자의 비긴횟수 저장
	int com_lose = 0, user_lose = 0; // 컴퓨터오 사용자의 패배횟수 저장
	int i,j; // 반복문 사용을 위한 변수선언

	srand(time(0)); // 랜덤함수를 사용하기 위한 준비

	// 사용자 순서
	printf("사용자가 원하는 순서를 입력해 주세요. : ");
	for (i = 0; i < 5; i++)
		scanf("%d", &s_user[i]);

	// 컴퓨터 순서
	while (1)
	{
		s_com[count] = rand() % 5 + 1;
		// 중복성 여부를 검사하는 부분
		for (i = 0; i < count; i++)
		{
			if (s_com[count] == s_com[i])
				break;
		}
		if (i == count)
			count++;
		if (count == 5)
			break;
	}

	printf("컴퓨터가 선정한 경주마의 순서 : ");
	for (i = 0; i < 5; i++)
		printf("%2d", s_com[i]);
	printf("\n");

	// 승부판정
	for (i = 0; i < 5; i++)
	{
		if (s_user[i] > s_com[i])
		{
			user_lose++;
			com_win ++;
		}
		else if (s_user[i] == s_com[i])
		{
			user_draw++;
			com_draw++;
		}
		else if (s_user[i] < s_com[i])
		{
			user_win++;
			com_lose++;
		}
	}

	printf("경주결과\n");
	printf("사용자 : %d번 승리, %d번 무승부, %d번 패배 --> 총점 : %d점\n", user_win, user_draw, user_lose, 3 * user_win + user_draw);
	printf("컴퓨터 : %d번 승리, %d번 무승부, %d번 패배 --> 총점 : %d점\n", com_win, com_draw, com_lose, 3 * com_win + com_draw);
	return 0;
}