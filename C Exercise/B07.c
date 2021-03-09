#include <stdio.h>

main() {
	int megabytes, time;
	long bytes;
	int usb_type;
	
	printf("사용자가 전송하고자 하는 파일의 용량을 MB 단위로 입력하세요. : ");
	scanf("%d", &megabytes);
	printf("사용자가 사용중인 usb 타입을 선택해 주세요. - USB1.1 - 1, USB2.0 - 2 : ");
	scanf("%d", &usb_type);

	bytes = megabytes * 1024 * 1024;

	if (usb_type == 1) {
		time = bytes / 1500000;
		printf("파일 전송에 걸리는 시간은 %d 초 입니다. \n", time);
	}
	else if (usb_type == 2) {
		time = bytes / 60000000;
		printf("파일 전송에 걸리는 시간은 %d 초 입니다. \n", time);
	}
	return 0;
}