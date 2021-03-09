#include <stdio.h>

struct point
{
	float x; // x좌표 값
	float y; // y좌표 값
};

void save_point(struct point * list[]);

main()
{
	struct point * mypoint[10]; // 구조체 배열을 선언
	int fir_qud = 0; // 제 1사분면의 개수를 저장하는 변수선언
	int sec_qud = 0; // 제 2사분면의 개수를 저장하는 변수선언
	int thr_qud = 0; // 제 3사분면의 개수를 저장하는 변수선언
	int fou_qud = 0; // 제 4사분면의 개수를 저장하는 변수선언
	int i; // 반복문 사용을 위한 변수선언

	// 사용자로부터 좌표값을 입력받는 부분
	for (i = 0; i < 10; i++)
	{
		mypoint[i] = (struct point *)malloc(sizeof(struct point)); // 메모리 할당
		printf("%d번째 좌표의 x, y 값을 입력하시오. : ", i + 1);
		scanf("%f %f", &mypoint[i]->x, &mypoint[i]->y);
	}

	// 저장된 좌표값의 사분면을 판정 및 출력하는 부분
	for (i = 0; i < 10; i++)
	{
		if ((mypoint[i]->x) > 0 && (mypoint[i]->y) > 0)
		{
			printf("%d번째 좌표는 제 1사분면에 위치합니다.\n", i + 1);
			fir_qud++;
		}
		else if ((mypoint[i]->x) < 0 && (mypoint[i]->y) > 0)
		{
			printf("%d번째 좌표는 제 2사분면에 위치합니다.\n", i + 1);
			sec_qud++;
		}

		else if ((mypoint[i]->x) < 0 && (mypoint[i]->y) < 0)
		{
			printf("%d번째 좌표는 제 3사분면에 위치합니다.\n", i + 1);
			thr_qud++;
		}
		else if ((mypoint[i]->x) > 0 && (mypoint[i]->y) < 0)
		{
			printf("%d번째 좌표는 제 4사분면에 위치합니다.\n", i + 1);
			fou_qud++;
		}
		else
			printf("%d번째 좌표는 사분면의 경계에 위치합니다.\n", i + 1);
	}

	// count한 결과값을 출력하는 부분
	printf("1사분면의 좌표는 모두 %d개 입니다.\n", fir_qud);
	printf("2사분면의 좌표는 모두 %d개 입니다.\n", sec_qud);
	printf("3사분면의 좌표는 모두 %d개 입니다.\n", thr_qud);
	printf("4사분면의 좌표는 모두 %d개 입니다.\n", fou_qud);

	save_point(mypoint);

	return 0;
}

// 입력받은 좌표를 txt 파일로 저장하는 함수정의
void save_point(struct point * list[])
{
	FILE * fp; // 파일핸들링 변수 fp 선언
	int i; // 반복문 사용을 위한 변수선언
	
	fp = fopen("point.txt", "wt"); // 파일 open

	for (i = 0; i < 10; i++)
		fprintf(fp, "%.1f %.1f\n", list[i]->x, list[i]->y);

	fclose(fp); // 파일 close
	printf("point.txt에 저장하였습니다. \n");
	return;
}