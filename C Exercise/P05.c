#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct login_data
{
	char id[20];       // 사용자 아이디
	char password[20]; // 사용자 비밀번호
};

// 입력받는 역할을 수행하는 함수선언
int add_user(struct login_data * userlist[], int count);
// 사용자 정보확인 함수선언
int check_user(struct login_data * userlist[], int count, struct login_data * tempuser);
// 모든 사용자 정보를 출력하는 함수선언
void all_user(struct login_data * userlist[], int count);
// 사용자 목록을 txt파일로 저장하는 함수선언
void save_list(struct login_data * userlist[], int count);

main()
{
	struct login_data * userlist[10]; // 10명의 로그인 데이터 보관용 포인터 배열
	struct login_data * user; // 로그인하기 위해 입력되는 사용자 정보
	int user_count = 0; // 등록된 사용자 수
	int i, check; // 반복문을 사용하기 위한 변수선언

				  // 사용자로부터 값을 입력받는 부분
	for (i = 0; i < 10; i++)
		user_count = add_user(userlist, user_count); // 입력받는 역할을 수행하는 함수호출

    // 저장된 값을 출력하는 부분
	all_user(userlist, user_count);

	// 사용자 정보를 txt로 저장하는 함수호출
	save_list(userlist, user_count);
	printf("입력하신 사용자 정보를 user.txt에 저장하였습니다.\n");

	// 사용자 정보를 확인하는 부분
	user = (struct login_data *)malloc(sizeof(struct login_data));
	while (1) {
		printf("로그인할 아이디는? --> ");
		scanf("%s", user->id);
		printf("로그인할 비밀번호? --> ");
		scanf("%s", user->password);
		check = check_user(userlist, user_count, user);
		if (check == 0)
			printf("아이디는 맞는데 비밀번호가 틀립니다.\n");
		else if (check == -1)
			printf(" 맞는 아이디가 없습니다.\n");
		else {
			printf("아이디와 비밀번호 둘다 맞습니다.\n");
			break;
		}
	}

	return 0;
}

// 입력받는 역할을 수행하는 함수정의
int add_user(struct login_data * userlist[], int count)
{
	int i; // 반복문 사용을 위한 변수선언

	userlist[count] = (struct login_data *)malloc(sizeof(struct login_data)); // 메모리 할당
																			  // 사용자 정보가 등록 가능한 정보인지 검사하는 부분
	while (1)
	{
		printf("%d번째 사람의 아이디, 비밀번호를 순서대로 입력해 주세요. : ", count + 1);
		scanf("%s %s", userlist[count]->id, userlist[count]->password);
		// 아이디 글자수가 4글자 이상인지 검사하는 부분
		if (strlen(userlist[count]->id) >= 4)
		{
			// 등록된 아이디 중에 중복되지 않는 지 검사하는 부분
			for (i = 0; i < count; i++)
			{
				if (strcmp(userlist[count]->id, userlist[i]->id) == 0)
				{
					printf("동일한 아이디가 이미 등록되어 있습니다. 다시 입력해 주세요.\n");
					break;
				}
			}
			// 중복 검사를 걸리지 않고 통과한 경우
			if (i == count)
			{
				// 비밀번호 글자수가 4글자 이상인지 검사하는 부분
				if (strlen(userlist[count]->password) < 4)
				{
					printf("사용자 비밀번호는 4글자 이상으로 입력하셔야 합니다. \n");
					continue;
				}
				// 비밀번호 글자수 검사를 통과한 경우
				else
				{
					count++; // 모든 검사를 통과하여 사용자 정보가 등록됨.
					break;
				}
			}
		}
		else
		{
			printf("사용자 아이디는 4글자 이상으로 입력하셔야 합니다.\n");
			continue;
		}
	}
	return count; // 등록된 사용자 수 값을 return
}

// 사용자 정보확인 함수 정의
int check_user(struct login_data * userlist[], int count, struct login_data * tempuser)
{
	int i; // 반복문 사용을 위한 변수선언

		   // 등록된 아이디를 조회해보는 부분
	for (i = 0; i < count; i++)
	{
		if (strcmp(tempuser->id, userlist[i]->id) == 0)
		{
			// 비밀번호를 조회해보는 부분
			if (strcmp(tempuser->password, userlist[i]->password) == 0)
				return 1;
			else
				return 0;
		}
	}
	// 아이디가 조회되지 않는 경우
	if (i == count)
		return -1;
}

// 모든 사용자 정보를 출력하는 함수정의
void all_user(struct login_data * userlist[], int count)
{
	int i; // 반복문 사용을 위한 변수선언

	printf("---------------------------------------\n");
	printf("No  아이디  비밀번호\n");
	printf("---------------------------------------\n");
	for (i = 0; i < 10; i++)
		printf("%2d %6s %6s\n", i + 1, userlist[i]->id, userlist[i]->password);
	printf("---------------------------------------\n");
	return;
}

// 사용자 목록을 txt파일로 저장하는 함수정의
void save_list(struct login_data * userlist[], int count)
{
	int i; // 반복문 사용을 위한 변수선언
	FILE * fp; // 파일 핸들링 변수 fp 선언
	fp = fopen("user.txt", "wt"); // 파일 open

	// 파일에 사용자 정보를 저장하는 부분
	for (i = 0; i < 10; i++)
		fprintf(fp, "%s %s\n", userlist[i]->id, userlist[i]->password);

	fclose(fp); // 파일 close
	return;
}