#include <stdio.h>

main() {
	float C_degree, F_degree; // 섭씨온도와 화씨온도 값을 저장할 변수 선언
	printf("섭씨온도를 입력하세요 : "); // 사용자에게 데이터 입력 요청
	scanf("%f", &C_degree); // 사용자에게 입력받은 값을 변수 C_degree 에 저장
	F_degree = C_degree * 1.8 + 32.0; // 화씨온도를 구하는 연산 수행
	printf("입력하신 값을 화씨온도로 변환하면 %f 도 입니다. \n", F_degree); // 연산결과 출력
	return 0;
}