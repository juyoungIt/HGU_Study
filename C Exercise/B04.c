#include <stdio.h>

main() {
	float m2_area, pyung_area;

	printf("아파트의 분양 면적 (제곱미터 단위)을 입력하세요 : ");
	scanf("%f", &m2_area);

	pyung_area = m2_area / 3.305;

	printf("아파트의 평형은 %.1f 이고, \n", pyung_area);

	if (pyung_area >= 30) {
		printf("30평 이상이므로 큰 아파트에 해당합니다. \n");
	}
	else if (pyung_area < 30) {
		printf("30평 미만이므로 작은 아파트에 해당합니다. \n");
	}
	return 0;
}