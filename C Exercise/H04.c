#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int com_choose; // 컴퓨터가 낸 값을 저장하는 변수선언
	int user_choose; // 사용자가 낸 값을 저장하는 변수선언
	int score[2][3] = { {0},{0} }; // 최종점수 값을 저장하는 2차원 배열 선언 (1행 - 컴퓨터 승/무/패, 2행 - 사용자 승/무/패)
	int i, j; // 반복문 사용을 위한 변수선언

	srand(time(0)); // 랜덤함수 사용을 위한 설정

	while (1)
	{
		// 1. 컴퓨터가 임의로 값을 선정
		com_choose = rand() % 3 + 1;

		// 2. 사용자에게 값의 입력받음
		printf("가위 - 1, 바위 - 2, 보 - 3 중 무엇을 내시겠어요? (숫자로 입력) : ");
		scanf("%d", &user_choose);
		if (user_choose == 0)
			break;

		// 3. 승패를 판정
		if (com_choose == 1 && user_choose == 1)
		{
			score[0][1]++;
			score[1][1]++;
			printf("사용자는 가위를 냈습니다. \n");
			printf("컴퓨터는 가위를 냈습니다. -------> 비겼습니다! \n");
		}
		else if (com_choose == 1 && user_choose == 2)
		{
			score[0][2]++;
			score[1][0]++;
			printf("사용자는 바위를 냈습니다. \n");
			printf("컴퓨터는 가위를 냈습니다. -------> 사용자 승! \n");
		}
		else if (com_choose == 1 && user_choose == 3)
		{
			score[0][0]++;
			score[1][2]++;
			printf("사용자는 보를 냈습니다. \n");
			printf("컴퓨터는 가위를 냈습니다. -------> 컴퓨터 승! \n");
		}
		else if (com_choose == 2 && user_choose == 1)
		{
			score[0][0]++;
			score[1][2]++;
			printf("사용자는 가위를 냈습니다. \n");
			printf("컴퓨터는 바위를 냈습니다. -------> 컴퓨터 승! \n");
		}
		else if (com_choose == 2 && user_choose == 2)
		{
			score[0][1]++;
			score[1][1]++;
			printf("사용자는 바위를 냈습니다. \n");
			printf("컴퓨터는 바위를 냈습니다. -------> 비겼습니다! \n");
		}
		else if (com_choose == 2 && user_choose == 3)
		{
			score[0][2]++;
			score[1][0]++;
			printf("사용자는 보를 냈습니다. \n");
			printf("컴퓨터는 바위를 냈습니다. -------> 사용자 승! \n");
		}
		else if (com_choose == 3 && user_choose == 1)
		{
			score[0][2]++;
			score[1][0]++;
			printf("사용자는 가위를 냈습니다. \n");
			printf("컴퓨터는 보를 냈습니다. -------> 사용자 승! \n");
		}
		else if (com_choose == 3 && user_choose == 2)
		{
			score[0][0]++;
			score[1][2]++;
			printf("사용자는 바위를 냈습니다. \n");
			printf("컴퓨터는 보를 냈습니다. -------> 컴퓨터 승! \n");
		}
		else if (com_choose == 3 && user_choose == 3)
		{
			score[0][1]++;
			score[1][1]++;
			printf("사용자는 보를 냈습니다. \n");
			printf("컴퓨터는 보를 냈습니다. -------> 비겼습니다! \n");
		}
	}
	// 4. 종료시 결과를 출력
	printf("컴퓨터 : 이긴횟수는 %d회, 진횟수는 %d회, 비긴횟수는 %d회 입니다. \n", score[0][0], score[0][2], score[0][1]);
	printf("사용자 : 이긴횟수는 %d회, 진횟수는 %d회, 비긴횟수는 %d회 입니다. \n", score[1][0], score[1][2], score[1][1]);
	return 0;
}