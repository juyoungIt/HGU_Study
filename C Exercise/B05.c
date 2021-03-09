#include <stdio.h>

main() {
	int days, seconds, m_count;

	printf("변환하고자 하는 날 수를 입력해주세요. : ");
	scanf("%d", &days);

	seconds = days * 24 * 60 * 60;
	m_count = seconds / 1000000;

	printf("날수에 해당하는 기간은 모두 %d 초 입니다. \n", seconds);
	if (m_count != 0) {
		printf("그리고 변환된 값은 100만초를 %d번 포함합니다. \n", m_count);
	}
	return 0;
}