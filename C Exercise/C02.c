#include <stdio.h>

main() 
{
	float input_degree;

	printf("사용자가 측정한 온도 값을 입력해 주세요. : ");
	scanf("%f", &input_degree);

	if (input_degree >= 0 && input_degree < 25) {
		printf("사용자가 온도를 측정한 물은 냉수에 해당합니다. \n");
	}
	else if (input_degree >= 25 && input_degree < 40) {
		printf("사용자가 온도를 측정한 물은 미온수에 해당합니다. \n");
	}
	else if (input_degree >= 40 && input_degree < 80) {
		printf("사용자가 온도를 측정한 물은 온수에 해당합니다. \n");
	}
	else if (input_degree >= 80) {
		printf("사용자가 온도를 측정한 물은 끓는 물에 해당합니다. \n");
	}
	else if (input_degree < 0) {
		printf("입력된 온도 값이 유효하지 않습니다. 입력한 값을 확인 후 다시 입력해 주세요. \n");
	}
	return 0;
}