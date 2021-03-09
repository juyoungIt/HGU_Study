#include <stdio.h>

main()
{
	int birth_year; // 태어난 연도 값을 저장할 변수선언
	int age[100]; // 나이 값을 저장할 1차원 배열선언
	int count_person = 0; // 총 사람의 수를 저장할 변수선언
	int count_baby = 0; // 유아의 수를 저장할 변수선언
	int count_child = 0; // 어린이 수를 저장할 변수선언
	int count_youth = 0; // 청소년의 수를 저장할 변수선언
	int count_young = 0; // 청년의 수를 저장할 변수선언
	int count_adult = 0; // 중년의 수를 저장할 변수선언
	int count_old = 0; // 노년의 수를 저장할 변수선언
	int i; // 반복문을 위한 변수선언

	printf("본 프로그렘은 2012년을 기준으로 제작되었습니다. \n");
	for (i = 0; i < 100; i++)
	{
		printf("%d번째 사람의 태어난 연도를 입력해 주세요. : ", i + 1);
		scanf("%d", &birth_year);
		if (birth_year >= 2012)
			break;
		age[i] = 2012 - birth_year + 1;

		if (age[i] < 7)
			count_baby++;
		else if (age[i] >= 7 && age[i] < 13)
			count_child++;
		else if (age[i] >= 13 && age[i] < 20)
			count_youth++;
		else if (age[i] >= 20 && age[i] < 30)
			count_young++;
		else if (age[i] >= 30 && age[i] < 60)
			count_adult++;
		else
			count_old++;
		count_person++;
	}

	for (i = 0; i < count_person; i++)
		printf("%d번째 학생의 나이는 %d세 입니다. \n", i + 1, age[i]);

	printf("유아는 %d명 입니다. \n", count_baby);
	printf("어린이는 %d명 입니다. \n", count_child);
	printf("청소년은 %d명 입니다. \n", count_youth);
	printf("청년은 %d명 입니다. \n", count_young);
	printf("중년은 %d명 입니다. \n", count_adult);
	printf("노년은 %d명 입니다. \n", count_old);
	return 0;
}