#include <stdio.h>

main() {
	int num1, num2, num3;
	int max_num, min_num;

	printf("세 개의 정수를 입력해 주세요. : ");
	scanf("%d %d %d", &num1, &num2, &num3);

	if (num1 > num2) {
		max_num = num1;
		min_num = num2;
		if (num3 > num1) {
			max_num = num3;
		}
		else if (num3 < num2) {
			min_num = num3;
		}
		else if (num3 == num1) {
			max_num = num1;
		}
		else if (num3 == num2) {
			min_num = num2;
		}
		printf("사용자가 입려한 세 정수 중에서 최댓값은 %d 이고, \n최솟값은 %d 입니다. \n", max_num, min_num);
	}
	else if (num1 < num2) {
		max_num = num2;
		min_num = num1;
		if (num3 > num2) {
			max_num = num3;
		}
		else if (num3 < num1) {
			min_num = num1;
		}
		else if (num3 == num2) {
			max_num = num2;
		}
		else if (num3 == num1) {
			min_num = num1;
		}
		printf("사용자가 입려한 세 정수 중에서 최댓값은 %d 이고, \n최솟값은 %d 입니다. \n", max_num, min_num);
	}
	else if (num1 == num2) {
		max_num = num1;
		min_num = num2;
		if (num3 > num1) {
			max_num = num3;
			printf("사용자가 입려한 세 정수 중에서 최댓값은 %d 이고, \n최솟값은 %d 입니다.", max_num, min_num);
		}
		else if (num3 < num2) {
			min_num = num3;
			printf("사용자가 입려한 세 정수 중에서 최댓값은 %d 이고, \n최솟값은 %d 입니다.", max_num, min_num);
		}
		else if (num3 == num1) {
			printf("사용자가 입력한 세 정수의 크기가 모두 같아서 최대 최소를 판별할 수 없습니다. \n");
		}
	}
	return 0;
}