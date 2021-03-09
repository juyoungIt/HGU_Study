#include <stdio.h>

struct score
{
	int kor; // 국어점수
	int eng; // 영어점수
	int mat; // 수학점수
	int sum; // 총점
	float average; // 평균
};

// 사용자로부터 입력받은 학생들 점수정보를 저장하는 함수선언
void save_score(struct score * list[], int count);

main()
{
	struct score * student[5]; // 구조체 포인터 선언
	int count; // 학생수의 값을 저장하는 변수선언
	int temp_sum = 0; // 구한 총점을 임시적으로 저장하는 변수선언
	float temp_ave; // 구한 평균을 임시적으로 저장하는 변수선언
	int i; // 반복문 사용을 위한 변수선언

	// 사용자로부터 과목별 점수값을 입력받는 부분

	printf("입력할 학생의 수를 입력해 주세요. : ");
	scanf("%d", &count);

	for (i = 0; i < count; i++)
	{
		student[i] = (struct score * )malloc(sizeof(struct score)); // 메모리 할당
		printf("%d번째 학생의 국어, 영어, 수학점수를 순서대로 입력해 주세요. : ", i + 1);
		scanf("%d %d %d", &student[i]->kor, &student[i]->eng, &student[i]->mat);
	}

	// 사용자로부터 입력받은 값을 바탕으로 총점과 평균을 구하는 부분
	for (i = 0; i < count; i++)
	{
		temp_sum = (student[i]->kor) + (student[i]->eng) + (student[i]->mat);
		temp_ave = temp_sum / 3.0;
		student[i]->sum = temp_sum; // 구한 값을 구조체에 넘겨줌 - 1
		student[i]->average = temp_ave; // 구한 값을 구조체에 넘겨줌 - 2
	}

	// 결과값을 출력하는 부분
	printf("번호 국어 영어 수학 총점 평균\n");
	for (i = 0; i < count; i++)
		printf("%3d %4d %4d %4d %4d %5.1f\n", i + 1, student[i]->kor, student[i]->eng, student[i]->mat, student[i]->sum, student[i]->average);

	// 입력한 값을 txt파일로 저장하는 부분
	save_score(student, count);
	return 0;
}

// 사용자로부터 입력받은 학생들 점수정보를 저장하는 함수정의
void save_score(struct score * list[], int count)
{
	FILE * fp; // 파일 핸들링 변수 fp 선언
	int i; // 반복문 사용을 위한 변수선언

	fp = fopen("score.txt", "wt"); // 파일 open
	for (i = 0; i < count; i++)
		fprintf(fp,"%d %d %d %d %d %.1f\n", i + 1, list[i]->kor, list[i]->eng, list[i]->mat, list[i]->sum, list[i]->average);
	fclose(fp); // 파일 close
	printf("입력하신 학생들의 점수정보를 score.txt에 저장하였습니다.\n");
	return;
}