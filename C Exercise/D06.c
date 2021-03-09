// D06 - 아파트 평형 계산 및 종류 판정

#include <stdio.h>

main() {
	float m2_area; // 제곱미터 단위의 분양면적 값을 저장할 변수선언
	float pyung_area; // 평형수로 변환된 분양면적 값을 저장할 변수선언
	int count1 = 0; //소형 아파트의 개수에 대한 값을 저장하는 변수선언
	int count2 = 0; //중소형 아파트의 개수에 대한 값을 저장하는 변수선언
	int count3 = 0; // 중형 아파트의 개수에 대한 값을 저장하는 변수선언
	int count4 = 0; // 대형 아파트의 개수에 대한 값을 저장하는 변수선언
	int i; //반복문에 사용되는 변수선언

    for (i = 1; i <= 10; i++) {

		printf("아파트의 분양면적을 제곱미터 단위로 입력해 주세요. : ");
		scanf("%f", &m2_area);

		pyung_area = m2_area / 3.305;

		if (pyung_area < 15) {
			count1++;
			printf("이 아파트의 평형은 %.1f평에 해당합니다. \n", pyung_area);
		}
		else if (pyung_area >= 15 && pyung_area < 30) {
			count2++;
			printf("이 아파트의 평형은 %.1f평에 해당합니다. \n", pyung_area);
		}
		else if (pyung_area >= 30 && pyung_area < 50) {
			count3++;
			printf("이 아파트의 평형은 %.1f평에 해당합니다. \n", pyung_area);
		}
		else if (pyung_area >= 50) {
			count4++;
			printf("이 아파트의 평형은 %.1f평에 해당합니다. \n", pyung_area);
		}
	}
	printf("소형 아파트의 개수는 %d개 입니다. \n", count1);
	printf("중소형 아파트의 개수는 %d개 입니다. \n", count2);
	printf("중형 아파트의 개수는 %d개 입니다. \n", count3);
	printf("대형 아파트의 개수는 %d개 입니다. \n", count4);
	return 0;
}