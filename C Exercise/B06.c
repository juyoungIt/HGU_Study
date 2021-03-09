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

	printf("사용자의 시험응시 총점은 %d 이고, \n", total);
	printf("사용자의 평균은 %.1f 점 입니다. \n", average);

	if (kor >= 90) {
		printf("사용자의 국어점수가 우수한 것으로 평가되었습니다. \n");
	}
	if (eng >= 90) {
		printf("사용자의 영어 점수가 우수한 것으로 평가되었습니다. \n");
	}
	if (math >= 90) {
		printf("사용자의 수학 점수가 우수한 것으로 평가되었습니다. \n");
	}
	return 0;
}