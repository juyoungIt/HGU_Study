#include <stdio.h>
#include <math.h>

struct point
{
	float x; // x좌표 값
	float y; // y좌표 값
};

float calc_distance(struct point p1, struct point p2); // 두 점 사이의 거리를 구하는 함수

main()
{
	struct point p1, p2;
	float distance; // 두점사이의 거리값을 저장하는 변수선언

	printf("첫번째 좌표의 x값은? : ");
	scanf("%f", &p1.x);
	printf("첫번째 좌표의 y값은? : ");
	scanf("%f", &p1.y);

	printf("두번째 좌표의 x값은? : ");
	scanf("%f", &p2.x);
	printf("두번째 좌표의 y값은? : ");
	scanf("%f", &p2.y);

	distance = calc_distance(p1, p2);

	printf("\n");
	printf("두 좌표 사이의 거리는 %.1f 입니다. \n", distance);

	return 0;
}

float calc_distance(struct point p1, struct point p2)
{
	float result; // 결과값을 저장하는 변수선언

	result = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
	return result;
}