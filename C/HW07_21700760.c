#include <stdio.h>

main()
{
	int size; // magic squre의 size값을 저장하는 변수선언
	int magic_square[30][30]; // magic square의 정보를 저장하는 2차원 배열선언 및 마방진의 최대크기 설정

	/* size값이 30을 넘어가게 될 경우 정상적인 모양으로 출력이 불가능 하여
	size의 최댓값을 30으로 설정하였습니다.*/

	int x, y; // magic squre의 시작 위치에 대한 값을 저장하는 변수선언
	int i, j;; // 반복문 사용을 위한 변수선언

	// 1. 사용자로부터 magic squre의 size 값을 입력받는 부분
	while (1)
	{
		printf("2보다 큰 홀수의 값으로 magic square의 size를 결정해 주세요. : ");
		scanf("%d", &size);
		if (size % 2 == 0)
		{
			printf("size 값은 홀수의 값으로만 입력해 주셔야 합니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
			continue;
		}
		break;
	}

	// 2. magic square를 결정하는 부분
	x = 0; y = (size-1) / 2; // magic square가 맨처음에 시작하는 위치를 설정
	for (i = 1; i <= size * size; i++)
	{
		magic_square[x][y] = i;

		if (i%size == 0)// size의 배수일 경우 바로 밑에 +1 한 수를 써주면 됨. (규칙)
			x++;
		else
		{
			if (x == 0)//배열의 인덱스 0부분 으로 도착했으면 반대편 부분으로 이동 (규칙)
				x = size - 1;
			else
				x--;

			if (y == 0)//배열의 인덱스 0부분 으로 도착했으면 반대편 부분으로 이동 (규칙)
				y = size - 1;
			else
				y--;
		}
	}


	// 3. magic square를 그리는 부분
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%4d", magic_square[i][j]);
		}
		if (j == size)
			printf("\n\n");
	}
	return 0;
}