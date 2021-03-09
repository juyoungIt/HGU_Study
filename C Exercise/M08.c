#include <stdio.h>

struct menu
{
	int number;    // 메뉴번호
	char name[20]; // 메뉴명
	int price;     // 가격
};

main()
{
	struct menu mymenu[5];
	FILE * file1;
	int i; // 반복문 사용을 위한 변수선언
	file1 = fopen("menu2.txt", "wt");

	printf("첫번째 메뉴의 번호, 메뉴명, 가격을 입력하시오. : ");
	scanf("%d %s %d", &mymenu[0].number, mymenu[0].name, &mymenu[0].price);
	fprintf(file1, "%d %s %d\n", mymenu[0].number, mymenu[0].name, mymenu[0].price);
	printf("두번째 메뉴의 번호, 메뉴명, 가격을 입력하시오. : ");
	scanf("%d %s %d", &mymenu[1].number, mymenu[1].name, &mymenu[1].price);
	fprintf(file1, "%d %s %d\n", mymenu[1].number, mymenu[1].name, mymenu[1].price);
	printf("세번째 메뉴의 번호, 메뉴명, 가격을 입력하시오. : ");
	scanf("%d %s %d", &mymenu[2].number, mymenu[2].name, &mymenu[2].price);
	fprintf(file1, "%d %s %d\n", mymenu[2].number, mymenu[2].name, mymenu[2].price);
	printf("네번째 메뉴의 번호, 메뉴명, 가격을 입력하시오. : ");
	scanf("%d %s %d", &mymenu[3].number, mymenu[3].name, &mymenu[3].price);
	fprintf(file1, "%d %s %d\n", mymenu[3].number, mymenu[3].name, mymenu[3].price);
	printf("다섯번째 메뉴의 번호, 메뉴명, 가격을 입력하시오. : ");
	scanf("%d %s %d", &mymenu[4].number, mymenu[4].name, &mymenu[4].price);
	fprintf(file1, "%d %s %d\n", mymenu[4].number, mymenu[4].name, mymenu[4].price);

	fclose(file1);

	file1 = fopen("menu2.txt", "rt");

	printf("메뉴번호 메뉴이름 1인분가격\n");
	for (i = 0; i < 5; i++)
	{
		fscanf(file1, "%d", &mymenu[i].number);
		fscanf(file1, "%s", mymenu[i].name);
		fscanf(file1, "%d", &mymenu[i].price);
	}
	for (i = 0; i < 5; i++)
	{
		printf("%5d", mymenu[i].number);
		printf("%11s", mymenu[i].name);
		printf("%8d\n", mymenu[i].price);
	}
	fclose(file1);
	return 0;
}