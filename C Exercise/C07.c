#include <stdio.h>

main() {
	int megabytes;
	long bytes;
	int send_type;
	float time;

	printf("전송하고자 하는 파일의 용량을 메가바이트(MB) 단위로 입력해 주세요. : ");
	scanf("%d", &megabytes);
	printf("지침에 따라서 파일전송 방식을 선택해 주세요. : \n 1 : WI-FI \n 2 : Bluetooth \n 3 : LTE \n 4 : USB \n");
	scanf("%d", &send_type);

	bytes = megabytes * 1024 * 1024;

	if (send_type == 1) {
		time = bytes / 1500000.0;
		printf("전송방식은 WI-FI를 선택하였고 예상 소요시간은 %.1f 초 입니다. \n", time);
	}
	else if (send_type == 2) {
		time = bytes / 300000.0;
		printf("전송방식은 Bluetooth를 선택하였고 예상 소요시간은 %.1f 초 입니다. \n", time);
	}
	else if (send_type == 3) {
		time = bytes / 1000000.0;
		printf("전송방식은 LTE를 선택하였고 예상 소요시간은 %.1f 초 입니다. \n", time);
	}
	else if (send_type == 4) {
		time = bytes / 60000000.0;
		printf("전송방식은 USB를 선택하였고 예상 소요시간은 %.1f 초 입니다. \n", time);
	}
	else {
		printf("유효하지 않는 send_type 을 입력하지 않습니다. 입력한 값을 다시한 번 확인해 주세요. : \n");
	}
	return 0;
}