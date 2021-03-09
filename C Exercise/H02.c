#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
	int lotto[6]; // 컴퓨터가 만들어낸 로또번호 값을 저장할 1차원 배열선언
	int count; // 로또번호 순서의 값을 저장할 변수선언
	char retry; // 반복여부를 입력하는 문자 값 (Y/N) 을 저장하는 변수선언
	int i; //반복문 사용을 위한 변수선언

	srand(time(0)); // 랜덤함수를 사용하기 위한 준비

	while (1)
	{
		//로또 번호를 생성하는 부분
		count = 0; // 카운트 값 초기화
		lotto[0] = rand() % 45 + 1; // 1차 임의 추출 시행
		count++;
		while (1)
		{
			lotto[count] = rand() % 45 + 1;
			// 중복성 여부를 검사하는 부분
			for (i = 0; i < count; i++)
			{
				if (lotto[count] == lotto[i])
					break;
			}
			if (i == count)
				count++;
			if (count == 6)
				break;
		}
		printf("생성된 로또번호는 %4d", lotto[0]);
		for (i = 1; i < 6; i++)
			printf("%4d", lotto[i]);
		printf("  입니다. \n");

		// 재실행 여부를 체크하는 부분
		while (1)
		{
			printf("번호를 더 생성하시겠습니까? (y/n) : ");
			scanf(" %c", &retry);
			if (retry == 'n' || retry == 'N' || retry == 'y' || retry == 'Y')
				break;
		}
		if (retry == 'y' || retry == 'Y')
			continue;
		else if (retry == 'n' || retry == 'N')
			break;
	}
	return 0;
}