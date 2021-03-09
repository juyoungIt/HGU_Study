#include <stdio.h>
#include <math.h>

struct rectangle
{
	int x1, y1; // 좌상점 좌표값 (왼쪽 위 모서리)
	int x2, y2; // 우상점 좌표값 (오른쪽 위 모서리)
};

int check_overlap(struct rectangle r1, struct rectangle r2); // 겹치면1, 아니면 0 리턴

main()
{
	struct rectangle r1, r2;
	int result; // 판단결과값을 저장하는 변수선언

	printf("첫번째 직사각형의 좌상점 좌표값은? : ");
	scanf("%d %d", &r1.x1, &r1.y1);
	printf("첫번쨰 직사각형의 우하점 좌표값은? : ");
	scanf("%d %d", &r1.x2, &r1.y2);
	printf("두번째 직사각형의 좌상점 좌표값은? : ");
	scanf("%d %d", &r2.x1, &r2.y1);
	printf("두번째 직사각형의 우하점 좌표값은? : ");
	scanf("%d %d", &r2.x2, &r2.y2);

	result = check_overlap(r1, r2);
	
	if (result == 1)
		printf("두 직사각형은 좌표평면 상에서 겹칩니다. \n");
	else if (result == 0)
		printf("두 직사각형은 좌표명면 상에서 겹치지 않습니다. \n");
	else
		printf("오류가 발생했습니다. (비이상적인 값 return됨) \n");
	
	return 0;
}

int check_overlap(struct rectangle r1, struct rectangle r2)
{
	if (r1.x2 < r2.x1 || r2.x2 < r1.x1)
	{
		if (r1.y1 < r2.y1 || r2.y1 < r1.y2)
			return 0;
	}
	else
		return 1;
}