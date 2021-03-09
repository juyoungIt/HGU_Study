#include <stdio.h>

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
	userlist[count] = (struct login_data * )malloc(sizeof(struct login_data)); // 메모리 할당
	printf("%d번째 사람의 아이디, 비밀번호를 순서대로 입력해 주세요. : ", count + 1);
	scanf("%s %s", userlist[count]->id, userlist[count]->password);
	count++; // 내용 추가후 사용자 수 값을 1증가
	return count; // 등록된 사용자 수 값을 return
}