#include <stdio.h>

main() {
	int birth_year, age;

	printf("태어난 연도를 입력해주세요 : ");
	scanf("%d", &birth_year);

	age = 2017 - birth_year + 1;

	if (age >= 20) {
		printf("당신은 성인 입니다. \n");
	}
	else {
		printf("당신은 미성년자 입니다. \n");
	}
	return 0;
}