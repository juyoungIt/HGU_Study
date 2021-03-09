#include <stdio.h>

main() 
{
	float input_degree, output_degree;
	int kind;

	printf("입력하고자하는 온도 값을 입력해 주세요. : ");
	scanf("%f", &input_degree);
	printf("입력해주신 온도 값의 단위를 입력해 주세요. (예 : 섭씨 - 1, 화씨 - 2 ) : ");
	scanf("%d", &kind);

	if (kind == 1) {
		output_degree = input_degree * 1.8 + 32;
		printf("입력해주신 섭씨온도를 화씨온도로 변환한 결과 입니다. : %.1f \n" , output_degree);
	}
	else if (kind == 2) {
		output_degree = (input_degree - 32) / 1.8;
		printf("입력해주신 화씨온도를 섭씨온도로 변환한 결과 입니다. : %.1f \n", output_degree);
	}
	return 0;
}