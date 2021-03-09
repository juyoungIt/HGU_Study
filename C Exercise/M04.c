#include <stdio.h>

struct rectangle
{
	int x1, y1; // 좌상점 좌표값 (왼쪽 위 모서리)
	int x2, y2; // 우하점 좌표값 (오른쪽 아래 모서리)
};

int calc_area(struct rectangle rect);

main()
{
	struct rectangle r1, r2;
	int area1, area2; // 직사각형의 넓이값을 저장하는 변수선언

	printf("첫번째 직사각형의 좌상점 좌표값(x,y)은? : ");
	scanf("%d %d", &r1.x1, &r1.y1);
	printf("첫번째 직사각형의 우하점 좌표값(x,y)은? : ");
	scanf("%d %d", &r1.x2, &r1.y2);
	printf("두번째 직사각형의 좌상점 좌표값(x,y)은? : ");
	scanf("%d %d", &r2.x1, &r2.y1);
	printf("두번째 직사각형의 우하점 좌표값(x,y)은? : ");
	scanf("%d %d", &r2.x2, &r2.y2);

	printf("\n");

	area1 = calc_area(r1);
	area2 = calc_area(r2);
	printf("첫번째 직사각형의 크기 : %d\n", area1);
	printf("두번째 직사각형의 크기 : %d\n", area2);

	if (area1 > area2)
		printf("첫번째 직사각형의 면적이 더 큽니다.\n");
	else if (area1 < area2)
		printf("두번째 직사각형의 면적이 더 큽니다.\n");
	else
		printf("두 직삭형의 면적이 서로 같습니다.\n");

	return 0;
}

int calc_area(struct rectangle rect)
{
	int result; // 결과값을 저장하는 변수선언

	result = (rect.x2 - rect.x1)*(rect.y1 - rect.y2);
	return result;
}