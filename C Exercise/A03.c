#include <stdio.h>

main() {
	int width, height; //가로, 세로의 길이와 관련된 변수 선언
	int area; // 직사각형 넓이와 관련된 변수 선언
	printf("직사각형의 가로의 길이를 입력해 주세요. : "); // 사용자에게 데이터 입력을 요청 - 1
	scanf("%d", &width); // 사용자로부터 입력받은 정보를 변수 width에 저장
	printf("직사각형의 세로의 길이를 입력해 주세요. : "); // 사용자에게 데이터 입력을 요청 - 2
	scanf("%d", &height); // 사용자로부터 입력받은 정보를 변수 height에 저장
	area = width * height; // 직사각형의 넓이를 구하는 연산 수행
	printf("직사각형의 넓이는  %d 입니다. \n", area); // 연산결과 출력
	return 0;
}