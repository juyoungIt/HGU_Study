#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calc_distance(struct point *p1, struct point *p2);

struct point
{
	float x; // x좌표 값
	float y; // y좌표 값
};

main()
{
	struct point * point1, * point2;
	float distance; // 두점 사이의 거리값을 저장하는 변수선언

	point1 = (struct point *)malloc(sizeof(struct point));
	point2 = (struct point *)malloc(sizeof(struct point));

	printf("첫번째 좌표의 x값은? : ");
	scanf("%f", &point1->x);
	printf("첫번째 좌표의 y값은? : ");
	scanf("%f", &point1->y);
	printf("두번째 좌표의 x값은? : ");
	scanf("%f", &point2->x);
	printf("두번째 좌표의 y값은? : ");
	scanf("%f", &point2->y);

	distance = calc_distance(point1, point2);

	printf("\n");
	printf("두 좌표사이의 거리는 %.1f입니다. \n", distance);
	return 0;
}

float calc_distance(struct point *p1, struct point *p2)
{
	float result; // 결과값을 저장하는 변수선언

	result = sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
	return result;
}