#include <stdio.h>

struct person
{
	char name[20];
	char address[80];
	int age;
};

main()
{
	struct person p1, p2, p3;

	printf("첫번째 사람 인적사항을 입력하시오. \n");
	printf("이름은? : ");
	scanf("%s", p1.name);
	printf("주소는? : ");
	scanf("%s", p1.address);
	printf("나이는? : ");
	scanf("%d", &p1.age);

	printf("두번째 사람 인적사항을 입력하시오. \n");
	printf("이름은? : ");
	scanf("%s", p2.name);
	printf("주소는? : ");
	scanf("%s", p2.address);
	printf("나이는? : ");
	scanf("%d", &p2.age);

	printf("세번째 사람 인적사항을 입력하시오. \n");
	printf("이름은? : ");
	scanf("%s", p3.name);
	printf("주소는? : ");
	scanf("%s", p3.address);
	printf("나이는? : ");
	scanf("%d", &p3.age);

	printf("=====================================================\n");
	printf("입력하신 세 명의 인적사항 입니다. \n");
	printf("\n");

	printf("첫번째 사람 : %s/ %s/ %d\n", p1.name, p1.address, p1.age);
	printf("두번째 사람 : %s/ %s/ %d\n", p2.name, p2.address, p2.age);
	printf("세번째 사람 : %s/ %s/ %d\n", p3.name, p3.address, p3.age);
	
	return 0;
}