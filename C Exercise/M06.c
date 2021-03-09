#include <stdio.h>

struct menu
{
	int number;      // 메뉴번호
	char name[20];   // 메뉴명
	char madein[20]; // 원산지
	int price;       // 가격
};

main()
{
	struct menu mymenu[5] = { {1,"삼겹살","국내산",9000}, {2,"갈비살","미국산",15000},
	{3,"꽃등심","국내산",30000},{4,"양념갈비","호주산",25000},{5,"차돌박이","국내산",28000} };
	int i; //반복문 사용을 위한 변수선언
	FILE * file1;
	file1 = fopen("menu.txt","wt");

	printf("메뉴번호 메뉴이름 원산지 1인분가격\n");
	for (i = 0; i < 5; i++)
	{
		printf("%5d", mymenu[i].number);
		printf("%11s", mymenu[i].name);
		printf("%8s", mymenu[i].madein);
		printf("%8d\n", mymenu[i].price);
		fprintf(file1, "%d %s %s %d\n", mymenu[i].number, mymenu[i].name, mymenu[i].madein, mymenu[i].price);
	}
	fclose(file1);
	return 0;
}