#include <stdio.h>

main() {
	int birth_year, age;
	printf("사용자의 태어난 연도를 입력해 주세요. : ");
	scanf("%d", &birth_year);

	age = 2017 - birth_year + 1;
	if (age < 7) {
		printf("사용자의 나이는 %d세 이며, 이는 유아에 해당합니다. \n", age);
	}
	else if (age >= 7 && age < 13) {
		printf("사용자의 나이는 %d세 이며, 이는 어린이에 해당합니다. \n", age);
	}
	else if (age >= 13 && age < 20) {
		printf("사용자의 나이는 %d세 이며, 이는 청소년에 해당합니다. \n", age);
	}
	else if (age >= 20 && age < 30) {
		printf("사용자의 나이는 %d세 이며, 이는 청년에 해당합니다. \n", age);
	}
	else if (age >= 30 && age < 60) {
		printf("사용자의 나이는 %d세 이며, 이는 중년에 해당합니다. \n", age);
	}
	else if (age >= 60) {
		printf("사용자의 나이는 %d세 이며, 이는 노년에 해당합니다. \n", age);
	}
	else {
		printf("입력된 값이 유효하지 않습니다. 입력하신 값을 확인하시고 다시 입력해 주시기 바랍니다. \n");
	}
	return 0;
}