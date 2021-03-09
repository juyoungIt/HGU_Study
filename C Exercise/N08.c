#include <stdio.h>
#include <stdlib.h>

struct menu * ask_menu();

struct menu
{
	int number;    // 메뉴번호
	char name[20]; // 메뉴명
	int price;     // 가격
};

main()
{
	struct menu * menu1;
	struct menu * menu2;
	struct menu * menu3;
	struct menu * menu4;
	struct menu * menu5;

	menu1 = ask_menu();
	menu2 = ask_menu();
	menu3 = ask_menu();
	menu4 = ask_menu();
	menu5 = ask_menu();

	printf("메뉴번호 메뉴이름 1인분가격\n");
	printf("%5d %11s %8d\n", menu1->number, menu1->name, menu1->price);
	printf("%5d %11s %8d\n", menu2->number, menu2->name, menu2->price);
	printf("%5d %11s %8d\n", menu3->number, menu3->name, menu3->price);
	printf("%5d %11s %8d\n", menu4->number, menu4->name, menu4->price);
	printf("%5d %11s %8d\n", menu5->number, menu5->name, menu5->price);
	return 0;
}

struct menu * ask_menu()
{
	struct menu * m;
	m = (struct menu *)malloc(sizeof(struct menu));
	printf("메뉴의 번호, 메뉴명, 가격을 입력하시오. : ");
	scanf("%d %s %d", &m->number, m->name, &m->price);
	return m;
}