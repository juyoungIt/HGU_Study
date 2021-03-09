//D02 - 입력받은 숫자들 중에서 가장 큰 수와 가장 작은 수 구하기

#include <stdio.h>

main() {
	int number; // 사용자로부터 입력받은 정수를 저장할 변수 선언
	int Max_num, Min_num; // 최대값과 최솟값을 저장할 변수 선언
	Max_num = 0;
	Min_num = 100;

	while (1) {
		printf("0부터 100까지의 수 중에서 임의로 선택하여 입력해주세요. : ");
		scanf("%d", &number);
	 
		if (number < 0 || number >100) {
			break;
		}
		if (number > Max_num) {
			Max_num = number;
		}
		if (number < Min_num) {
			Min_num = number;
		}
	}
	printf("사용자가 유효조건 내에서 입력한 수의 최솟값은 %d 이고, 최댓값은 %d 입니다. \n", Min_num, Max_num);
	return 0;
}