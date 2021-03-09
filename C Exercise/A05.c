#include <stdio.h>

main() {
	int days, seconds; //날짜와 초의 값을 저장할 변수선언
	printf("날수를 입력하세요. : "); // 사용자에게 데이터 입력요청
	scanf("%d", &days); // 사용자로부터 입력받은 값을 변수 days에 저장
	seconds = days * 24 * 60 * 60; // 초를 구하는 연산 수행
	printf("날수에 해당되는 시간은 모두 %d 초 입니다. \n", seconds); // 연산결과 출력
	return 0;
}