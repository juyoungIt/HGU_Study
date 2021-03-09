#include <stdio.h>

main() {
	int kor, eng, math; // 국어, 영어, 수학점수의 값을 저장할 변수선언
	int total; // 총점의 값을 저장할 변수선언
	float average; // 평균의 값을 저장할 변수선언

	printf("본인의 국어점수를 입력해주세요. : "); // 사용자에게 데이터 입력 요청 - 1
	scanf("%d", &kor); // 사용자로부터 입력받은 값을 변수 kor에 저장
	printf("본인의 영어점수를 입력해주세요. : "); // 사용자에게 데이터 입력 요청 - 2
	scanf("%d", &eng); // 사용자로부터 입력받은 값을 변수 eng에 저장
	printf("본인의 수학점수를 입력해주세요. : "); // 사용자에게 데이터 입력 요청 - 3
	scanf("%d", &math); // 사용자로부터 입력받은 값을 변수 math에 저장

	total = kor + eng + math; // 총점을 구하는 연산수행
	average = total / 3.0; // 평균을 구하는 연산수행

	printf("입력하신 점수의 총점은 %d 점이고, \n", total); // 연산결과 출력 - 1
	printf("평균은 %f 입니다. \n", average); // 연산결과 출력 - 2
	return 0;
}