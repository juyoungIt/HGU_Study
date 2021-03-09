#include <stdio.h>

main() {
	float m2_area, pyung_area; // 분양면적과 평형 값 정보를 저장할 변수 선언
	printf("아파트의 분양면적을 입력해주세요. : "); // 사용자에게 데이터 입력 요청
	scanf("%f", &m2_area); // 사용자에게 입력받은 값을 변수 m2_area에 저장
	pyung_area = m2_area / 3.305; // 평수를 구하는 연산 수행
	printf("아파트의 평형은 %f 입니다. \n", pyung_area); // 연산결과를 출력
	return 0;
}