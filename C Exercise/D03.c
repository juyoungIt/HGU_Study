//D03 - 입력받은 숫자들의 총 합계와 평균 구하기

#include <stdio.h>

main() {
	int number; // 사용자로부터 입력받은 수를 저장하는 변수선언
	int count = 0; // 사용자가 입력한 수의 개수 값을 저장할 변수선언 및 초기화
	int total = 0; // 사용자의 입력한 값의 합계를 저장할 변수선언 및 초기화
	float average = 0.0; // 사용자가가 입력한 값의 평균값을 저장할 변수선언 및 초기화

	while (1) {
		printf("0에서 100까지의 수 중에서 임의로 선택하여 입력해 주세요. : ");
		scanf("%d", &number);

		if (number < 0 || number > 100) {
			break;
		}
		count++;
		total = total + number; // 총 합계를 구하는 연산수행
	}
	average = (float)total / (float)count; // 평균을 구하는 연산수행

	printf("유효범위 내에서 사용자가 입력한 값 %d개 의 합계는 %d 이고, 평균은 %.1f 입니다. \n", count, total, average);
	return 0;
}