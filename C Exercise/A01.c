#include <stdio.h>

main() {
	int birth_year, age; //태어난 연도와 나이를 저장하기 위한 변수선언
	printf("태어난 연도를 입력해주세요."); // 사용자에게 데이터 입력 요청
	scanf("%d", &birth_year); // 사용자가 입력한 정보를 birth_year에 저장
	age = 2017 - birth_year + 1; // 나이를 구하는 연산 수행
	printf("당신의 나이는 %d 살 입니다 \n",age); // 연산결과 출력
	return 0;
}