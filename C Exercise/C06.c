#include <stdio.h>

main() {
	int kor, eng, math;
	int total;
	float average;

	printf("사용자의 국어 점수를 입력해 주세요. : ");
	scanf("%d", &kor);
	printf("사용자의 영어 점수를 입력해 주세요. : ");
	scanf("%d", &eng);
	printf("사용자의 수학 점수를 입력해 주세요. : ");
	scanf("%d", &math);

	total = kor + eng + math;
	average = total / 3.0;


	printf("사용자의 세 과목 총점은 %d 이고, \n", total);
	printf("사용자의 세 과목 평균은 %.1f 입니다. \n", average);

	if (average >= 90) {
		printf("귀하의 시험성적은 수 로 평가되었습니다. \n");
	}
	else if (average >= 80 && average < 90) {
		printf("귀하의 시험성적은 우 로 평가되었습니다. \n");
	}
	else if (average >= 70 && average < 80) {
		printf("귀하의 시험성적은 미 로 평가되었습니다. \n");
	}
	else if (average >= 60 && average < 70) {
		printf("귀하의 시험성적은 양 으로 평가되었습니다. \n");
	}
	else if (average < 60) {
		printf("귀하의 시험성적은 가 로 평가되었습니다. \n");
	}
	return 0;
}