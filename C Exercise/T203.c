#include <stdio.h>

int count0 = 0, count1 = 0, count2 = 0, count3 = 0; // 기술등급 별 인원수 저장
int count_wd0 = 0, count_wd1 = 0, count_wd2 = 0, count_wd3 = 0; // 기술등급별 투입시간 저장
int sum_pay0 = 0, sum_pay1 = 0, sum_pay2 = 0, sum_pay3 = 0; // 기술 등급별 지급인건비 합계 저장

int calc_fee(int grade, int days);
void print_bar(float ratio[4]);
main()
{
	int p_number; // 프로젝트 투입인원수 저장
	int p_grade; // 기술 등급 저장
	int p_wd; // 투입일수 저장
	int total_pay; // 총 인건비 값을 저장하는 변수선언
	float ratio[4]; // 각 기술등급별 수입비율 값을 저장하는 배열선언
	int i; // 반복문 사용위한 변수선언

	printf("Enter the number of person (max10) : ");
	scanf("%d", &p_number);

	for (i = 0; i < p_number; i++)
	{
		printf("person's grade(0~3) & working days : ");
		scanf("%d %d", &p_grade, &p_wd);
		if (p_grade == 0)
			sum_pay0 += calc_fee(p_grade, p_wd);
		else if (p_grade == 1)
			sum_pay1 += calc_fee(p_grade, p_wd);
		else if (p_grade == 2)
			sum_pay2 += calc_fee(p_grade, p_wd);
		else if (p_grade == 3)
			sum_pay3 += calc_fee(p_grade, p_wd);
	}

	total_pay = sum_pay0 + sum_pay1 + sum_pay2 + sum_pay3;
	ratio[0] = (sum_pay0 / (float)total_pay) * 100;
	ratio[1] = (sum_pay1 / (float)total_pay) * 100;
	ratio[2] = (sum_pay2 / (float)total_pay) * 100;
	ratio[3] = (sum_pay3 / (float)total_pay) * 100;


	printf("\n\n");
	printf("Novice       (0) : %d persons, %d working days, %d won\n", count0, count_wd0, sum_pay0);
	printf("Intermediate (1) : %d persons, %d working days, %d won\n", count1, count_wd1, sum_pay1);
	printf("Advanced     (2) : %d persons, %d working days, %d won\n", count2, count_wd2, sum_pay2);
	printf("Expert       (3) : %d persons, %d working days, %d won\n", count3, count_wd3, sum_pay3);

	printf("\n");
	printf("The ratio of fee by the grade\n");
	print_bar(ratio); // 그래프 그리기
	return 0;
}
int calc_fee(int grade, int days)
{
	if (grade == 0)
	{
		count0++;
		count_wd0 += days;
		return (23849 * 8)*days;

	}
	else if (grade == 1)
	{
		count1++;
		count_wd1 += days;
		return (28317 * 8)*days;
	}
	else if (grade == 2)
	{
		count2++;
		count_wd2 += days;
		return (35555 * 8)*days;
	}
	else if (grade == 3)
	{
		count3++;
		count_wd3 += days;
		return (47688 * 8)*days;
	}

}

void print_bar(float ratio[4])
{
	int number; // 찍을 횟수 저장
	int i; // 반복문 사용위한 변수선언
	printf("Novice        ");
	number = (int)(50 * (ratio[0]/100));
	for (i = 0; i < number; i++)
		printf("N");
	printf("(%.1f%%)", ratio[0]);
	printf("\n");
	printf("Intermediate  ");
	number = (int)(50 * (ratio[1]/100));
	for (i = 0; i < number; i++)
		printf("I");
	printf("(%.1f%%)", ratio[1]);
	printf("\n");
	printf("Advanced      ");
	number = (int)(50 * (ratio[2]/100));
	for (i = 0; i < number; i++)
		printf("A");
	printf("(%.1f%%)", ratio[2]);
	printf("\n");
	printf("Expert        ");
	number = (int)(50 * (ratio[3]/100));
	for (i = 0; i < number; i++)
		printf("E");
	printf("(%.1f%%)", ratio[3]);
	printf("\n");
}