#include <stdio.h>
#include <string.h>
#define SIZE 20
#define N 10

main()
{
	char com_os[N][SIZE]={ "Window", "MacOS", "UNIX", "Linux", "Android", "ios", "WindowMobile", "TIZEN", "Bada", "BlackBerryOS" }; 
	// string의 배열을 저장하는 2차원 배열선언
	char temp[20]; // 자리를 바꾸는 과정에서 임시로 string을 저장할 1차원 배열선언
	int count = 0; // sorthing이 몇번째 이루어지고 있는 지에 대한 값을 저장하는 변수선언
	int i; // 반복문 사용을 위한 변수선언
	
	printf("Sorting 이전의 string 배열\n");
	printf("\n");
	printf("-->   ");
	for (i = 0; i < N; i++)
		printf("%s\t", com_os[i]);
	printf("\n");

	// Sorting 과정
	while (1)
	{
		count = 0; // count값 초기화
		for (i = 0; i < N; i++)
		{
			if (strcmp(com_os[i], com_os[i + 1]) > 0)
			{
				strcpy(temp, com_os[i]);
				strcpy(com_os[i], com_os[i + 1]);
				strcpy(com_os[i + 1], temp);
				count++;
			}
		}
		// 더 이상 sorthing 작업이 이루어지지 않는다면 sorthing 작업이 완료된 것으로 보고 반복을 종료함.
		if (count == 0)
			break;
	}
	printf("\n");
	printf("=====================================================================================================");
	printf("\n");
	// Sorting 결과 출력
	printf("Sorting 결과\n");
	printf("\n");
	printf("-->   ");
	for (i = 0; i < N; i++)
		printf("%s\t", com_os[i]);
	printf("\n\n");
	return 0;
}