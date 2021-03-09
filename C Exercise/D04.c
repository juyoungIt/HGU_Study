//D04 - 미성년자 수 세기

#include <stdio.h>

main() {
	int count_all; // 사용자로부터 입력받은 가족 구성원의 수를 저장할 변수선언
	int count_young = 0; // 미성년자 수에 대한 값을 저장할 변수선언 및 초기화
	int birth_year; // 사용자로부터 입력받은 태어난 연도에 대한 값을 저장하는 변수선언
	int age; // 나이에 대한 값을 저장하는 변수선언
	int x; // 반복문에서 사용할 변수선언

	printf("가족 구성원의 수를 입력해 주세요. : ");
	scanf("%d", &count_all);

	for (x = 1; x <= count_all; x++) {
		printf("태어난 연도를 입력해 주세요. : ");
		scanf("%d", &birth_year);

		age = 2017 - birth_year + 1;

		if (age < 20) {
			count_young++;
		}
	}
	printf("입력해주신 가족 구성원 중에서 미성년자는 %d명 입니다. \n", count_young);
	return 0;
}