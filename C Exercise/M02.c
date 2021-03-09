#include <stdio.h>

struct rectangle
{
	int width; // 가로
	int height; // 세로
};

int calc_area(struct rectangle rect); // 직사각형 면적 구하는 함수
int calc_boundary(struct rectangle rect); // 직사각형 둘레 구하는 함수

main()
{
	struct rectangle r;
	int area; // 직사각형의 넓이값을 저장하는 변수선언
	int boundary; // 직사각형의 둘레의 길이를 저장하는 변수선언

	printf("가로 크기는? : ");
	scanf("%d", &r.width);
	printf("세로 크기는? : ");
	scanf("%d", &r.height);

	area = calc_area(r);
	boundary = calc_boundary(r);
	
	printf("직사각형의 면적은 %d이고, 둘레는 %d입니다.\n", area, boundary);
	return 0;
}

int calc_area(struct rectangle rect)
{
	int result; // 연산의 결과값을 저장하는 변수선언
	
	result = rect.width * rect.height;
	return result;
}

int calc_boundary(struct rectangle rect)
{
	int result; // 연산의 결과값을 저장하는 변수선언

	result = (rect.width + rect.height) * 2;
	return result;
}