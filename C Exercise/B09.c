#include <stdio.h>

main() {
	int height, weight;
	float bmi;

	printf("측정자의 신장(cm 단위)를 입력해주세요. : ");
	scanf("%d", &height);
	printf("측정자의 체중(kg 단위)을 입력해주세요. : ");
	scanf("%d", &weight);

	bmi = weight / ((height*0.01)*(height*0.01));

	if (bmi >= 25) {
		printf("검사결과 비만으로 판정되었습니다. \n");
	}
	else if (bmi < 25) {
		printf("검사결과 정상으로 판정되었습니다. \n");
	}
	return 0;
}