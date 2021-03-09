#include <stdio.h>

main()
{
	int num[10]; // 사용자로부터 입력받은 10개의 변수를 저장할 배열선언
	int first; // 처음 배열에서 가장 큰 변수를 저장할 변수선언
	int second; // 두번째로 큰 수를 저장할 변수선언
	int second_index = 0; // 두번째로 수의 위치에 대한 값을 저장할 변수선언
	int i; // 반복문 사용을 위한 변수선언
	int j = 1; // 반복문 사용을 위한 변수선언 - 2

	for (i = 0; i < 10; i++,j++)
	{
		printf("%d번째 수를 입력해 주세요. : ", j);
		scanf("%d", &num[i]);
	}

	first = num[0];
	for (i = 0; i < 10; i++)
	{
		if (first < num[i])
			first = num[i];
	}

	second = num[0];
	for (i = 0; i < 10; i++)
	{
		if (second < num[i]) {
			if (num[i] == first) {
				second_index += 1;
				continue;
			}

			else {
				second = num[i];
				second_index += 1;
			}		
		}

	}
	printf("입력하신 수 중에서 두번째로 큰 수는 %d 번째 수 %d 입니다. \n", second_index, second);
	return 0;
}