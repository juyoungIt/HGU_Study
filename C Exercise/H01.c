#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int solution; // 컴퓨터가 만들어낸 1에서 100사이의 임의의 값을 저장하는 변수선언
	int answer; // 사용자로 부터 입력받은 1에서 100사이의 임의의 정수
	int count = 0; // 사용자가 정답을 맞추기 위해서 입력한 횟수를 저장하는 변수선언

	srand(time(0)); // 랜덤함수를 사용하기 위한 준비
	solution = rand() % 100 + 1; // 임의의 수 선정

	while (1)
	{
		printf("1부터 100까지의 숫자 하나를 맞춰보세요. : ");
		scanf("%d", &answer);

		if (answer > solution)
		{
			printf("입력하신 수보다 작은 수 입니다. \n");
			count++;
		}
		else if (answer < solution)
		{
			printf("입력하신 수보다 큰 수 입니다. \n");
			count++;
		}
		else // answer == solution
		{
			count++;
			printf("%d번 만에 정답을 맞추셨습니다. \n", count);
			break;
		}
	}
	return 0;
}