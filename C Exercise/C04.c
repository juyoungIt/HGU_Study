#include <stdio.h>

main() {
	float m2_area, pyung_area;

	printf("아파트 분양면적을 제곱미터 단위로 입력해 주세요. : ");
	scanf("%f", &m2_area);

	pyung_area = m2_area / 3.305;

	if (pyung_area < 15) {
		printf("사용자가 입력한 아파트의 분양면적은 %.1f 평 이며, 이는 소형에 해당합니다. \n", pyung_area);
	}
	else if (pyung_area >= 15 && pyung_area < 30) {
		printf("사용자가 입력한 아파트의 분양면적은 %.1f 평 이며, 이는 중소형에 해당합니다. \n", pyung_area);
	}
	else if (pyung_area >= 30 && pyung_area < 50) {
		printf("사용자가 입력한 아파트의 분양면적은 %.1f평 이며, 이는 중형에 해당합니다. \n", pyung_area);
	}
	else if (pyung_area >= 50) {
		printf("사용자가 입력한 아파트의 분양면적은 %.1f평 이며, 이는 대형에 해당합니다. \n", pyung_area);
	}
	return 0;
}