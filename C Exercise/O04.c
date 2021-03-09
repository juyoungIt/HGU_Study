#include <stdio.h>

struct menu
{
	int number; // 메뉴번호
	char name[20]; // 메뉴명
	char madein[20]; // 원산지
	int price; // 가격
};

void save_menu(struct menu * list[]);

main()
{
	struct menu * mymenu[5]; // 구조체 포인터 배열선언
	int i; // 반복문 사용을 위한 변수선언

	// 사용자로부터 입력받은 메뉴정보를 구조체 포인터 배열에 저장
	for (i = 0; i < 5; i++)
	{
		mymenu[i] = (struct menu *)malloc(sizeof(struct menu)); // 메모리 할당
		printf("%d번째 메뉴의 번호, 메뉴명, 원산지, 1인분 가격을 입력하시오. : ", i + 1);
		scanf("%d %s %s %d", &mymenu[i]->number, mymenu[i]->name, mymenu[i]->madein, &mymenu[i]->price);
	}

	// 저장된 메뉴를 출력
	printf("메뉴번호 매뉴이름 원산지 1인분가격\n");
	for (i = 0; i < 5; i++)
		printf("%5d %11s %6s %7d\n", mymenu[i]->number, mymenu[i]->name, mymenu[i]->madein, mymenu[i]->price);

	save_menu(mymenu); // 구조체 포인터를 넘겨줌.
	return 0;
}

// 사용자로부터 입력받은 메뉴정보를 txt파일로 저장하는 함수정의
void save_menu(struct menu * list[])
{
	FILE * fp; // 파일 핸들링 변수 fp 선언
	int i; // 반복문 사용을 위한 변수선언

	fp = fopen("menu.txt", "wt"); // 파일 open

	for (i = 0; i < 5; i++)
		fprintf(fp, "%d %s %s %d\n", list[i]->number, list[i]->name, list[i]->madein, list[i]->price);

	fclose(fp); // 파일 clsoe
	printf("입력하신 menu정보를 menu.txt에 저장하였습니다. \n");
	return;
}