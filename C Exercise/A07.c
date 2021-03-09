#include <stdio.h>

main() {
	int gigabytes, megabytes, kilobytes; // 용량과 관련된 변수 선언
	unsigned int  bytes; // bytes의 값이 크게 나오므로 자료형을 unsigned로 지정
	printf("파일을 용량을 기가바이트 단위로 입력해주세요 : ");
	scanf("%d", &gigabytes);

	megabytes = gigabytes * 1024; // 변환과정 - 1
	kilobytes = megabytes * 1024; // 변환과정 - 2
	bytes = kilobytes * 1024; // 변환과정 - 3

	printf("입력하신 파일의 용량은 \n"); 
	printf("%d 메가바이트 \n", megabytes); // 변환결과 출력 - 1
	printf("%d 킬로바이트 \n", kilobytes); // 변환결과 출력 - 2
	printf("%u 바이트 입니다. \n", bytes); // 변환결과 출력 - 3, 서식문자의 사용에 주의
	return 0;
}