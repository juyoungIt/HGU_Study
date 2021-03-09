#include <stdio.h>
#include <string.h>

struct login_data
{
	char id[20];       // 사용자 아이디
	char password[20]; // 사용자 비밀번호
};

// 입력받는 역할을 수행하는 함수선언
int add_user(struct login_data * userlist[], int count);

main()
{
	struct login_data * userlist[10]; // 10명의 로그인 데이터 보관용 포인터 배열
	int user_count = 0; // 등록된 사용자 수
	int i; // 반복문을 사용하기 위한 변수선언

		   // 사용자로부터 값을 입력받는 부분
	for (i = 0; i < 10; i++)
		user_count = add_user(userlist, user_count); // 입력받는 역할을 수행하는 함수호출

													 // 저장된 값을 출력하는 부분
	for (i = 0; i < 10; i++)
		printf("%d번째 사람의 아이디(%s), 비밀번호(%s)\n", i + 1, userlist[i]->id, userlist[i]->password);

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