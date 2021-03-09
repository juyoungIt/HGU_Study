#include <stdio.h>
#include <string.h>

struct person_num
{
	char name[20]; // 이름
	char num[20];  // 전화번호
}list[100]; // 저장가능한 최대 인원수를 100명으로 제한함.;

void pop_menu(); // 기능항목을 출력하는 함수선언
void num_save(); // 번호를 저장하는 함수선언
void num_remove(); // 번호를 삭제하는 함수선언
void inq_name(); // 이름으로 번호를 조회하는 함수선언
void inq_num(); // 번호로 이름을 조회하는 함수선언

int count = 0; // 저장된 번호의 수를 저장하는 변수선언
main()
{
	int task_num; // 선택한 작업번호를 저장하는 변수선언 
	int i; // 반복문을 사용하기 위한 변수선언

	while (1)
	{
		pop_menu();
		printf("수행할 작업을 입력해 주세요. : ");
		scanf("%d", &task_num);

		// 1. 입력된 값이 1일 때 - 새로운 번호추가
		if (task_num == 1)
			num_save();
		// 2. 입력된 값이 2일 때 - 번호 삭제
		else if (task_num == 2)
			num_remove();
		// 3. 입력된 값이 3일 때 - 이름으로 번호조회
		else if (task_num == 3)
			inq_name();
		// 4. 입력된 값이 4일 때 - 번호로 이름조회
		else if (task_num == 4)
			inq_num();
		// 5. 입력된 값이 5일 때 - 종료
		else if (task_num == 5)
			break;
	}
	// 사용자가 종료를 입력한 경우 지금까지 저장된 번호들을 출력
	printf("=============================\n\n");
	printf("전화번호부\n\n");
	printf("순서    이름      전화번호\n");
	for (i = 0; i < count; i++)
	{
		printf("%3d %9s %15s\n", i+1, list[i].name, list[i].num);
	}
	return 0;
}

// 기능항목을 출력하는 함수
void pop_menu()
{
	printf("=============================\n");
	printf("기능항목\n\n");
	printf(" 1. 새로운 번호추가\n\n");
	printf(" 2. 번호삭제\n\n");
	printf(" 3. 이름으로 번호조회\n\n");
	printf(" 4. 번호로 이름조회\n\n");
	printf(" 5. 종료\n\n");
	printf("=============================\n");
	return;
}

// 번호를 입력받아서 저장하는 함수
void num_save()
{
	int i; // 반복문을 사용하기 위한 변수선언
	char name[20], num[20]; // 사용자가 입력한 이름과 번호를 저장하는 배열

	printf("이름과 번호를 순서대로 입력해 주세요. : ");
	scanf("%s %s", name, num);

	//번호의 중복을 검사 (예외처리)
	for (i = 0; i < count; i++)
	{
		if (strcmp(num, list[i].num) == 0)
		{
			printf("=============================\n");
			printf("--> 입력하신 번호는 이미 저장되어 있는 번호입니다.\n");
			return 0;
		}
	}
	strcpy(list[count].name, name);
	strcpy(list[count].num, num);
	printf("=============================\n");
	printf("--> 입력하신 정보가 성공적으로 저장되었습니다. \n");
	count++;
	return;
}
// 번호 또는 이름을 입력받아서 삭제하는 함수
void num_remove()
{
	char data[20]; // 사용자가 입력한 번호나 이름을 저장할 변수선언
	int method; // 조회하는 방식을 저장하는 변수선언
	int index; // 같은 data가 발견된 index값을 저장
	int i; // 반복문을 사용하기 위한 변수선언

	printf("삭제하고자 하는 정보를 무엇으로 조회할까요? (이름 - 1, 번호 - 2) : ");
	scanf("%d", &method);
	if (method == 1)
	{
		printf("이름을 입력해 주세요. : ");
		scanf("%s", data);
		// 입력한 이름을 검색
		for (i = 0; i < count; i++)
		{
			if (strcmp(data, list[i].name) == 0)
				break;
		}
		index = i;
		if (index < count)
		{
			for (i = index; i < count; i++)
			{
				list[i] = list[i + 1]; // 한칸씩 당김
			}
			printf("=============================\n");
			printf("--> 입력하신 정보를 성공적으로 삭제했습니다.\n");
			return 0;

		}
		else if (index == count)
		{
			printf("=============================\n");
			printf("--> 입력하신 이름이 목록 내에 존재하지 않습니다.\n");
			return 0;
		}
		
	}
	else if (method == 2)
	{
		printf("번호를 입력해 주세요. : ");
		scanf("%s", data);
		// 입력한 번호를 검색
		for (i = 0; i < count; i++)
		{
			if (strcmp(data, list[i].num) == 0)
				break;
		}
		index = i;
		if (index < count)
		{
			for (i = index; i < count; i++)
			{
				list[i] = list[i + 1]; // 한칸씩 당김
			}
			printf("=============================\n");
			printf("--> 입력하신 정보를 성공적으로 삭제했습니다.\n");
			return 0;
		}
		else if (index == count)
		{
			printf("=============================\n");
			printf("--> 입력하신 번호가 목록 내에 존재하지 않습니다.\n");
			return 0;
		}
	}
}
// 이름으로 번호를 조회하는 함수
void inq_name()
{
	char name[20]; // 사용자에게 입력받은 이름을 저장할 배열선언
	int index; // 조회하고자 하는 이름의 index값을 저장하는 변수선언
	int i; // 반복문을 사용하기 위한 변수선언

	printf("조회 할 이름을 입력해주세요. : ");
	scanf("%s", name);
	// 입력한 이름을 검색
	for (i = 0; i < count; i++)
	{
		if (strcmp(name, list[i].name) == 0)
			break;
	}
	index = i;
	if (index < count)
	{
		printf("=============================\n");
		printf("--> 조회하신 %s님의 번호는 %s 입니다.\n", list[index].name, list[index].num);
		return 0;
	}
	else if (index == count)
	{
		printf("=============================\n");
		printf("--> 입력하신 이름이 목록 내에 존재하지 않습니다.\n");
		return 0;
	}
}
// 번호로 이름을 조회하는 함수
void inq_num()
{
	char num[20]; // 사용자에게 입력받은 번호를 저장할 배열선언
	int index; // 조회하고자 하는 번호의 index값을 저장하는 변수선언
	int i; // 반복문을 사용하기 위한 변수선언

	printf("조회할 번호를 입력해주세요. : ");
	scanf("%s", num);
	// 입력한 번호를 검색
	for (i = 0; i < count; i++)
	{
		if (strcmp(num, list[i].num) == 0)
			break;
	}
	index = i;
	if (index < count)
	{
		printf("=============================\n");
		printf("--> 조회하신 번호 %s는 %s님의 번호입니다.\n", list[index].num, list[index].name);
		return 0;
	}
	else if (index == count)
	{
		printf("=============================\n");
		printf("--> 입력하신 번호가 목록 내에 존재하지 않습니다.\n");
		return 0;
	}
}