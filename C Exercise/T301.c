// 학번 : 21700760 이름 : 하주영
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aRecord {
	char region[20]; // 시도명
	int population[5];   // 2013년~2017년 인구수(단위:천명)
	int density[5];  // 2013년~2017년 인구밀도(단위:킬로제곱미터당 인구수)
	float diff_density; // 2013년 대비 2017년 인구밀도 변화율
};

int load_list(struct aRecord * list[]); // 입력용 파일(input.txt)로부터 목록 읽어옴
int add_list(struct aRecord * list[], int count); // 1개의 항목을 입력받아 추가 
void view_list(struct aRecord * list[], int count); // 모든 항목을 출력
void modify_list(struct aRecord * list[], int count); // 1개의 항목 내용 수정
void report_file(struct aRecord * list[], int count); //출력용 파일(output.txt)에 목록 저장
void find_density(struct aRecord * list[], int count); // 인구밀도 변화율이 가장 높은 지역을 찾아서 출력
void find_year(struct aRecord * list[], int count); // 해당 년도의 항목 및 합계만 출력

main()
{
	struct aRecord * itemlist[100];
	int menu, item_count, which;

	item_count = load_list(itemlist);
	printf("%d개의 항목이 등록되었습니다\n", item_count);
	while (1)
	{
		printf("\n메뉴: 1)추가 2)목록 3)변경 4)저장 5)검색 0)종료\n선택>> ");
		scanf("%d", &menu);
		if (menu == 1) item_count = add_list(itemlist, item_count);
		else if (menu == 2) view_list(itemlist, item_count);
		else if (menu == 3) modify_list(itemlist, item_count);
		else if (menu == 4) report_file(itemlist, item_count);
		else if (menu == 5) {
			printf("검색 기준은? 1)인구밀도변화율 2)년도별 선택>> ");
			scanf("%d", &which);
			if (which == 1) find_density(itemlist, item_count);
			else find_year(itemlist, item_count);
		}
		else break;
	}
	printf("프로그램을 종료합니다.\n");
}

int load_list(struct aRecord * list[])
{
	FILE * in_file;
	int i = 0, j, count = 0, scan_result;

	in_file = fopen("input.txt", "rt");
	while (!feof(in_file)) {
		list[i] = (struct aRecord *)malloc(sizeof(struct aRecord));
		scan_result = fscanf(in_file, "%s", list[i]->region);
		if (scan_result == EOF) break;
		for (j = 0; j<5; j++) fscanf(in_file, "%d", &list[i]->population[j]);
		for (j = 0; j<5; j++) fscanf(in_file, "%d", &list[i]->density[j]);
		list[i]->diff_density = 1.0*list[i]->density[4] / list[i]->density[0];
		count++; i++;
	}
	fclose(in_file);
	return count;
}

int add_list(struct aRecord * list[], int count)
{
	// 동작내용 : 1개의 항목을 입력받아 list에 추가함
	// 파라미터 : list (목록 포인터배열), count (목록의 항목 갯수)
	// 리턴값 : 1개가 추가된 목록의 항목 갯수

	int j;
	list[count] = (struct aRecord *)malloc(sizeof(struct aRecord));
	printf("시(도) 이름은? >> ");
	scanf("%s", list[count]->region);
	printf("2013년부터 2017년까지의 인구숫자(단위:천명)를 입력하시오\n>> ");
	for (j = 0; j<5; j++) scanf("%d", &list[count]->population[j]);
	printf("2013년부터 2017년까지의 인구밀도(단위:킬로제곱미터당 인구수)를 입력하시오\n>> ");
	for (j = 0; j<5; j++) scanf("%d", &list[count]->density[j]);
	list[count]->diff_density = 1.0*list[count]->density[4] / list[count]->density[0];
	return count + 1;
}

void view_list(struct aRecord * list[], int count)
{
	int i, j;
	printf("지역(시/도)명\t인구숫자(2013년~17년, 단위 천명)\t인구밀도(2013년~17년)\t인구밀도증가율(%%)\n");
	for (i = 0; i<count; i++) {
		printf("%-10s\t", list[i]->region);
		for (j = 0; j<5; j++) printf("%7d", list[i]->population[j]);
		printf("\t");
		for (j = 0; j<5; j++) printf("%6d", list[i]->density[j]);
		printf("\t%6.2f%%\n", list[i]->diff_density * 100 - 100);
	}
}

void modify_list(struct aRecord * list[], int count)
{
	char temp[20]; // 일시적으로 지역명을 저장하는 문자배열 선언
	int i, j; // 반복문을 사용하기 위한 변수선언
	printf("수정하려는 지역명을 입력해 주세요. : ");
	scanf("%s", &temp);
	// 지역이름 찾기
	for (i = 0; i < count; i++)
	{
		if (strcmp(list[i]->region, temp) == 0)
		{
			// 우선 지역명이 조회되면 기존에 저장된 값을 출력
			printf("지역(시/도)명\t인구숫자(2013년~17년, 단위 천명)\t인구밀도(2013년~17년)\t인구밀도증가율(%%)\n");
			printf("%-10s\t", list[i]->region);
			for (j = 0; j<5; j++) printf("%7d", list[i]->population[j]);
			printf("\t");
			for (j = 0; j<5; j++) printf("%6d", list[i]->density[j]);
			printf("\t%6.2f%%\n", list[i]->diff_density * 100 - 100);

			printf("변경하려는 정보를 입력하세요.\n");
			printf("2013년부터 2017년까지의 인구숫자(단위:천명)를 입력하시오. \n>>");
			for (j = 0; j<5; j++) scanf("%7d", &list[i]->population[j]);
			printf("2013년부터 2017년까지의 인구밀도(단위:킬로제곱미터당 인구수)를 입력하시오. \n>>");
			for (j = 0; j<5; j++) scanf("%d", &list[i]->density[j]);
			list[i]->diff_density = 1.0*list[i]->density[4] / list[i]->density[0]; // 변경된 값을 반영하여 다시 계산
			printf("변경되었습니다. \n");
			return;		
		}
	}
	if (i == count)
	{
		printf("지역명이 잘못 입력되었습니다. \n");
		return;
	}
}

void report_file(struct aRecord * list[], int count)
{
	int i, j; // 반복문을 사용하기 위한 변수선언
	FILE * fp; // 파일 핸들링 변수선언
	fp = fopen("output.txt", "wt"); // 파일 open

	// 파일에 메모리에 저장된 값을 입력하는 부분
	fprintf(fp, "지역(시/도)명\t인구숫자(2013년~17년, 단위 천명)\t인구밀도(2013년~17년)\t인구밀도증가율(%%)\n");
	for (i = 0; i<count; i++) 
	{
		fprintf(fp, "%-10s\t", list[i]->region);
		for (j = 0; j<5; j++) fprintf(fp, "%7d", list[i]->population[j]);
		fprintf(fp, "\t");
		for (j = 0; j<5; j++) fprintf(fp,"%6d", list[i]->density[j]);
		fprintf(fp, "\t%6.2f%%\n", list[i]->diff_density * 100 - 100);
	}
	fclose(fp); // 파일 close
	printf("성공적으로 output.txt에 최근의 데이터가 저장되었습니다. \n");
	return;
}

void find_density(struct aRecord * list[], int count)
{
	float Max; // 인구밀도변화율이 가장 큰 값을 저장하는 변수선언
	int Max_index; // 인구밀도변화율이 가장 큰 곳의 인덱스 값을 저장하는 변수선언
	int i, j; // 반복문을 사용하기 위한 변수선언

	// 인구밀도변화율이 가장 큰 곳의 index값을 찾는 부분
	for (i = 0; i < count; i++)
	{
		if (i == 0)
			Max = list[i]->diff_density;
		else
		{
			if (Max < list[i]->diff_density)
			{
				Max = list[i]->diff_density;
				Max_index = i;
			}
		}
	}

	// 찾은 부분을 화면에 출력
	printf("인구밀도 변화율이 가장 높은 지역은 다음과 같습니다. \n");
	printf("지역(시/도)명\t인구숫자(2013년~17년, 단위 천명)\t인구밀도(2013년~17년)\t인구밀도증가율(%%)\n");
	printf("%-10s\t", list[Max_index]->region);
	for (j = 0; j<5; j++) printf("%7d", list[Max_index]->population[j]);
	printf("\t");
	for (j = 0; j<5; j++) printf("%6d", list[Max_index]->density[j]);
	printf("\t%6.2f%%\n", list[Max_index]->diff_density * 100 - 100);
	return;
}

void find_year(struct aRecord * list[], int count)
{
	int temp_year; // 검색할 년도값을 저장하는 변수선언
	int i; // 반복문을 사용하기 위한 변수선언
	int j; // 연도별 index를 가리키는 변수선언
	int total_sum = 0; // 총인구수 값을 저장하는 변수선언
	int density_sum = 0; // 인구밀도 값을 저장하는 변수선언

	// 사용자에게 검색할 연도를 입력받음
	printf("검색할 년도를 입력하시오. >> ");
	scanf("%d", &temp_year);

	// 연도 값이 있는 지 없는 지 판정하는 부분
	if (temp_year >= 2013 && temp_year <= 2017)
	{
		if (temp_year == 2013) j = 0;
		else if (temp_year == 2014) j = 1;
		else if (temp_year == 2015) j = 2;
		else if (temp_year == 2016) j = 3;
		else j = 4;
		printf("지역(시/도)명\t인구숫자(%d년, 단위 천명)\t인구밀도(%d년)\n", temp_year, temp_year);
		for (i = 0; i<count; i++) 
		{
			printf("%-10s\t", list[i]->region);
			printf("\t");
			printf("%7d\t", list[i]->population[j]);
			printf("\t");
			printf("%6d\n", list[i]->density[j]);
			total_sum += list[i]->population[j];
			density_sum += list[i]->density[j];
		}
	}
	else
	{
		printf("해당년도의 자료는 없습니다. \n");
		return;
	}
	printf("총 인구수 : %d천명\n", total_sum);
	printf("인구밀도 : %d명/킬로제곱미터\n", density_sum);
}

/*

추가 데이터용 항목 (순서대로 시도명, 인구수5개, 인구밀도5개)
Gyeongbuk 2661 2671 2678 2686 2681 140 140 141 141 141
Gyeongnam 3278 3307 3330 3346 3355 311 314 316 317 318
Jeju 570 583 599 619 634 308 315 324 335 343
Sejong 118 132 187 233 276 255 285 403 500 593


*/