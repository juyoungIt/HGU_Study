#include <stdio.h>

main() {
	int grade; // 사용자가 입력한 학점에 대한 값을 저장할 변수선언
	
	printf("귀하의 학점을 입력해주세요. : "); // 사용자에게 학점에 대한 값 입력요청
	scanf("%d", &grade); // 사용자가 입력한 학점에 대한 값을 변수 grade에 저장

	if (grade >= 90 && grade <= 100) {
		printf("축하드립니다. 이번학기 성적 A를 받으셨습니다. \n");
	}
	else if (grade < 90 && grade >= 80) {
		printf("축하드립니다. 이번학기 성적 B를 받으셨습니다. \n");
	}
	else if (grade < 80 && grade >= 70) {
		printf("아쉽게도 이번학기 성적 C를 받으셨습니다. 다음에는 더 좋은 결과를 얻을 수 있기를 바랍니다. \n");
	}
	else if (grade < 70 && grade >= 60) {
		printf("아쉽게도 이번학기 성적 D를 받으셨습니다. 다음에는 더 좋은 결과를 얻을 수 있기를 바랍니다. \n");
	}
	else if (grade >= 0 && grade < 60) {
		printf("이번학기 성적 F를 받으셨습니다. 다음에는 더 좋은 결과를 얻을 수 있기를 바랍니다. \n");
	}
	else {
		printf("유효하지 않는 값입니다. 입력하신 학점의 값을 확인해보시기 바랍니다. \n");
	}
	return 0;
}