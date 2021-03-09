//D01 - 1부터 숫자 더하기
#include <stdio.h>

main() {
	int number; // 사용자로부터 입력받은 정수를 저장할 변수선언
	int Sum = 0; // 연산을 진행하여 합에 대한 값을 저장할 변수선언 및 초기화
	int i = 1; // 반복문에서 사용할 변수 선언 및 초기화

	printf("사용자가 생각하고 있는 한 개의 정수를 입력해 주세요. : ");
	scanf("%d", &number);
    
	if (number < 1) {
		printf("유효하지 않은 값을 입력했습니다. 입력하신 값을 확인 후 다시 입력해 주세요. \n");
		return 0;
	}
	while (i <= number) {
		Sum = Sum + i;
		i++;
	}
	printf("1부터 사용자가 입력한 정수 %d 까지의 합은 %d 입니다. \n", number, Sum);
	return 0;
}