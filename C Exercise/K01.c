// 본 프로그렘은 2012년 기준으로 작성되었습니다.

#include <stdio.h>

int Askage(int birthyear); // 함수 Askage의 선언

main()
{
	int birthyear; // 태어난 연도값을 저장하는 변수선언
	int count0 = 0; // return 값 0의 횟수를 저장하는 변수선언 및 초기화 (유아)
	int count1 = 0; // return 값 1의 횟수를 저장하는 변수선언 및 초기화 (어린이)
	int count2 = 0; // return 값 2의 횟수를 저장하는 변수선언 및 초기화 (청소년)
	int count3 = 0; // return 값 3의 횟수를 저장하는 변수선언 및 초기화 (청년)
	int count4 = 0; // return 값 4의 횟수를 저장하는 변수선언 및 초기화 (중년)
	int count5 = 0; // return 값 5의 횟수를 저장하는 변수선언 및 초기화 (노년)
	int result; // 판정결과(resturn 값)를 저장한 변수선언
	int i; // 반복문 사용을 위한 변수선언

	// 연도를 입력받고 나이를 판정 및 출력
	for (i = 0;; i++)
	{
		if (i == 100)
			break;
		printf("%d번째 사람의 테어난 연도를 입력해 주세요. : ", i+1);
		scanf("%d", &birthyear);
		if (birthyear > 2012)
			break;
		result = Askage(birthyear);
		if (result == 0)
			count0++;
		else if (result == 1)
			count1++;
		else if (result == 2)
			count2++;
		else if (result == 3)
			count3++;
		else if (result == 4)
			count4++;
		else if (result == 5)
			count5++;

	}

	// 연령대별 수를 출력하는 부분
	printf("\n");
	printf("입력한 사람의 수는 총 %d명 이며, \n", i + 1);
	printf("\n");
	printf("유아는 %d명 입니다. \n", count0);
	printf("어린이는 %d명 입니다. \n", count1);
	printf("청소년은 %d명 입니다. \n", count2);
	printf("청년은 %d명 입니다. \n", count3);
	printf("중년은 %d명 입니다. \n", count4);
	printf("노년은 %d명 입니다. \n", count5);
	return 0;
}

// 함수 Askage의 정의부
int Askage(int birthyear)
{
	int age; // 나이에 대한 값을 저장하는 변수선언

	age = 2012 - birthyear + 1;
	if (age < 7)
	{
		printf("나이는 %d 입니다. \n", age);
		return 0;
	}
	else if (age >= 7 && age < 13)
	{
		printf("나이는 %d 입니다. \n", age);
		return 1;
	}
	else if (age >= 13 && age < 20)
	{
		printf("나이는 %d 입니다. \n", age);
		return 2;
	}
	else if (age >= 20 && age < 30)
	{
		printf("나이는 %d 입니다. \n", age);
		return 3;
	}
	else if (age >= 30 && age < 60)
	{
		printf("나이는 %d 입니다. \n", age);
		return 4;
	}
	else if (age >= 60)
	{
		printf("나이는 %d 입니다. \n", age);
		return 5;
	}
}