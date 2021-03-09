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
	struct menu mymenu[5];
	FILE * file1;
	file1 = fopen("menu.txt", "rt");
	int i; // 반복문 사용을 위한 변수선언

	printf("menu.txt에서 메뉴정보를 읽어들였습니다.\n");
	printf("메뉴번호 메뉴이름 원산지 1인분가격\n");

	for (i = 0; i < 5; i++)
	{
		fscanf(file1, "%d", &mymenu[i].number);
		fscanf(file1, "%s", mymenu[i].name);
		fscanf(file1, "%s", mymenu[i].madein);
		fscanf(file1, "%d", &mymenu[i].price);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%5d", mymenu[i].number);
		printf("%11s", mymenu[i].name);
		printf("%8s", mymenu[i].madein);
		printf("%8d\n", mymenu[i].price);
	}
	fclose(file1);
	return 0;
}