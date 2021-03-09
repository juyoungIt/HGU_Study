#include <stdio.h>

struct point
{
	float x; // x좌표
	float y; // y좌표
};

void load_point(struct point * list[]);

main()
{
	struct point * list[10]; // 구조체 포인터 선언
	int fir_qud = 0; // 제 1사분면에 위치하는 좌표 수를 저장
	int sec_qud = 0; // 제 2사분면에 위치하는 좌표 수를 저장
	int thr_qud = 0; // 제 3사분면에 위치하는 좌표 수를 저장
	int fou_qud = 0; // 제 4사분면에 위치하는 좌표 수를 저장
	int i; // 반복문 사용을 위한 변수선언

	load_point(list); // 함수 load_point 호출

	for (i = 0; i < 10; i++)
	{
		printf("%d번째 좌표 (%6.1f,%6.1f)는 ", i+1, list[i]->x, list[i]->y);
		if ((list[i]->x) > 0 && (list[i]->y) > 0)
		{
			printf("제 1사분면에 위치합니다.\n");
			fir_qud++;
		}
		else if ((list[i]->x) < 0 && (list[i]->y) > 0)
		{
			printf("제 2사분면에 위치합니다.\n");
			sec_qud++;
		}
		else if ((list[i]->x) < 0 && (list[i]->y) < 0)
		{
			printf("제 3사분면에 위치합니다.\n");
			thr_qud++;
		}
		else if ((list[i]->x) > 0 && (list[i]->y) < 0)
		{
			printf("제 4사분면에 위치합니다.\n");
			fou_qud++;
		}
		else
			printf("사분면의 경계에 위치합니다. \n");
	}

	// count한 결과값을 출력하는 부분
	printf("제 1사분면에 위치하는 좌표의 개수는 %d개 입니다.\n", fir_qud);
	printf("제 2사분면에 위치하는 좌표의 개수는 %d개 입니다.\n", sec_qud);
	printf("제 3사분면에 위치하는 좌표의 개수는 %d개 입니다.\n", thr_qud);
	printf("제 4사분면에 위치하는 좌표의 개수는 %d개 입니다.\n", fou_qud);
	return 0;
}

void load_point(struct point * list[])
{
	FILE * fp; // 파일 핸들링 변수 fp 선언
	int i; // 반복문 사용을 위한 변수선언

	fp = fopen("point.txt", "rt"); // 파일 open
	
	for (i = 0; i < 10; i++)
	{
		list[i] = (struct point *)malloc(sizeof(struct point)); // 메모리 공간을 할당
		fscanf(fp, "%f %f\n", &list[i]->x, &list[i]->y);
	}

	fclose(fp); // 파일 close
	printf("point.txt에서 좌표 정보를 읽어들였습니다.\n");
	return;
}