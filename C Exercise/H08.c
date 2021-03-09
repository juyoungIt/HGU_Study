#include <stdio.h>
#include <string.h>

main()
{
	char userid[30];
	char password[30];
	char name[30];
	int i = 0; // 반복문 사용을 위한 변수선언

	printf("사용자 ID를 입력하세요. : ");
	scanf("%s", userid);

	while (1)
	{
		printf("사용자 암호를 입력하세요. : ");
		scanf("%s", password);
		if (strlen(password) < 3)
		{
			printf("==> 암호는 3글자 이상 입력하세요. \n");
			continue;
		}
		break;
	}


	printf("사용자 이름을 입력하세요. : ");
	scanf("%s", name);
	printf("********************************\n");
	printf("사용자 ID : %s\n", userid);
	printf("사용자 암호 : ");
	printf("%c", password[0]);
	printf("%c", password[1]);
	while (1)
	{
		printf("*");
		i++;
		if (i == strlen(password) - 2)
		{
			printf("\n");
			break;
		}
	}
	printf("사용자 이름 : %s\n", name);
	printf("********************************\n");

	return 0;
}