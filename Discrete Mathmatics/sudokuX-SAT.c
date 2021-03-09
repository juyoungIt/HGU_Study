#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp = fopen("formula.txt", "w");

    // standard input으로 입력을 처리하는 경우 사용하는 코드
    char line_one[10], line_two[10], line_three[10], line_four[10], 
        line_five[10], line_six[10], line_seven[10], line_eight[10], line_nine[10]; // 각 라인별 입력 정보를 저장하는 부분
    char board[9][9]; // 스도쿠 판에 대한 정보를 저장하는 2차원 배열
    char element;     // 입력으로 부터 받아오는 문자 하나하나

    // 사용자로부터 기본 input을 입력받는 부분
    scanf("%s", line_one);
    scanf("%s", line_two);
    scanf("%s", line_three);
    scanf("%s", line_four);
    scanf("%s", line_five);
    scanf("%s", line_six);
    scanf("%s", line_seven);
    scanf("%s", line_eight);
    scanf("%s", line_nine);

    // 입력받은 내용을 스도쿠 판으로 전달
    for(int i=0 ; i<9 ; i++) {
        element = line_one[i];
        board[i][0] = element;
    }
    for(int i=0 ; i<9 ; i++) {
        element = line_two[i];
        board[i][1] = element;
    }
    for(int i=0 ; i<9 ; i++) {
        element = line_three[i];
        board[i][2] = element;
    }
    for(int i=0 ; i<9 ; i++) {
        element = line_four[i];
        board[i][3] = element;
    }
    for(int i=0 ; i<9 ; i++) {
        element = line_five[i];
        board[i][4] = element;
    }
    for(int i=0 ; i<9 ; i++) {
        element = line_six[i];
        board[i][5] = element;
    }
    for(int i=0 ; i<9 ; i++) {
        element = line_seven[i];
        board[i][6] = element;
    }
    for(int i=0 ; i<9 ; i++) {
        element = line_eight[i];
        board[i][7] = element;
    }
    for(int i=0 ; i<9 ; i++) {
        element = line_nine[i];
        board[i][8] = element;
    }

    // 파일로 입력을 처리하는 경우 사용하는 코드
    /*
    FILE *input = fopen("input.txt", "r"); // 초기 input

    char board[9][9]; // 스도쿠 판에 대한 정보를 저장하는 2차원 배열
    char element;     // 입력으로 부터 받아오는 문자 하나하나
    // 파일로 부터 입력을 받아와서 스도쿠 사전값의 정보를 저장
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            element = fgetc(input);
            if (element == '\n')
            {
                x--;
                continue;
            }
            board[x][y] = element;
        }
    }
    */


    int i, j, n;
    int r, s;

    // 729개의 명제 생성
    for (i = 1; i <= 9; i++)
        for (j = 1; j <= 9; j++)
            for (n = 1; n <= 9; n++)
                fprintf(fp, "(declare-const p%d%d%d Bool)\n", i, j, n);

    // Q0. pre-assigned number -> 사전에 입력되어 있는 값을 리딩하여 기입함
    fprintf(fp, "; Q0\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for (int y = 0; y < 9; y++)
    {
        for (int x = 0; x < 9; x++)
        {
            if (board[x][y] != '?')
            {
                i = y + 1;
                j = x + 1;
                n = board[x][y];
                fprintf(fp, "p%d%d%c ", i, j, n);
            }
        }
    }
    fprintf(fp, "))\n");

    // Q1 -> 가로가 각각 1 ~ 9 사이의 수를 가질 수 있도록 하는 부분
    fprintf(fp, "; Q1\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for (i = 1; i <= 9; i++)
    {
        fprintf(fp, "(and ");
        for (n = 1; n <= 9; n++)
        {
            fprintf(fp, "(or ");
            for (j = 1; j <= 9; j++)
            {
                fprintf(fp, "p%d%d%d ", i, j, n);
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    //Q2 -> 세로가 각각 1~9 사이의 수를 가질 수 있도록 하는 부분
    fprintf(fp, "; Q2\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for (j = 1; j <= 9; j++)
    {
        fprintf(fp, "(and ");
        for (n = 1; n <= 9; n++)
        {
            fprintf(fp, "(or ");
            for (i = 1; i <= 9; i++)
            {
                fprintf(fp, "p%d%d%d ", i, j, n);
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q3 - 3x3 그리드가 각각 1~9 사이의 값을 가질 수 있도록 하는 부분
    fprintf(fp, "; Q3\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for (r = 0; r <= 2; r++)
    {
        fprintf(fp, "(and ");
        for (s = 0; s <= 2; s++)
        {
            fprintf(fp, "(and ");
            for (n = 1; n <= 9; n++)
            {
                fprintf(fp, "(or ");
                for (i = 1; i <= 3; i++)
                {
                    fprintf(fp, "(or ");
                    for (j = 1; j <= 3; j++)
                    {
                        fprintf(fp, "p%d%d%d ", 3 * r + i, 3 * s + j, n);
                    }
                    fprintf(fp, ")");
                }
                fprintf(fp, ")");
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q4 - 중복검사 - 하나의 좌표에 대한 9개의 명제 중에서 오직 하나만 참이 되도록 하는 부분
    fprintf(fp, "; Q4\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for (i = 1; i <= 9; i++)
    {
        fprintf(fp, "(and ");
        for (j = 1; j <= 9; j++)
        {
            fprintf(fp, "(and ");
            for (n = 1; n <= 8; n++)
            {
                fprintf(fp, "(and ");
                for (int m = n + 1; m <= 9; m++)
                {
                    fprintf(fp, "(not (and p%d%d%d p%d%d%d))", i, j, n, i, j, m);
                }
                fprintf(fp, ")");
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q5 - left top diagonal(all numbers in 1 to 9)
    fprintf(fp, "; Q5\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for (n = 1; n <= 9; n++)
    {
        fprintf(fp, "(or ");
        for (i = 1; i <= 9; i++)
        {
            fprintf(fp, "p%d%d%d ", i, i, n);
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q6 - left top diagonal(do not multiple value)
    fprintf(fp, "; Q6\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for (i = 1; i <= 9; i++)
    {
        fprintf(fp, "(and ");
        for (n = 1; n <= 8; n++)
        {
            fprintf(fp, "(and ");
            for (int m = n + 1; m <= 9; m++)
            {
                fprintf(fp, "(not (and p%d%d%d p%d%d%d))", i, i, n, i, i, m);
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q7 - right top diagonal(all numbers in 1 to 9)
    fprintf(fp, "; Q7\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for (n = 1; n <= 9; n++)
    {
        fprintf(fp, "(or ");
        for (i = 1; i <= 9; i++)
        {
            fprintf(fp, "p%d%d%d ", i, 10 - i, n);
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q8 - right top diagonal(do not multiple value)
    fprintf(fp, "; Q8\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for (i = 1; i <= 9; i++)
    {
        fprintf(fp, "(and ");
        for (n = 1; n <= 8; n++)
        {
            fprintf(fp, "(and ");
            for (int m = n + 1; m <= 9; m++)
            {
                fprintf(fp, "(not (and p%d%d%d p%d%d%d))", i, 10 - i, n, i, 10 - i, m);
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))");

    fprintf(fp, "(check-sat)\n(get-model)\n");

    // fclose(input); - 파일로 입력을 받을 경우 사용해야하는 부분
    fclose(fp);

    // print out sudokuX solution
    int solution[9][9] = {0}; // 결과값을 저장하는 2차원 배열

    FILE *fin = popen("z3 formula.txt", "r");
    FILE *result = fopen("solution.txt", "w");

    char buf[128];
    fscanf(fin, "%s %s", buf, buf);
    int rows, cols, value; // 가로좌표, 세로좌표, 값을 저장하는 변수
    while (!feof(fin))
    {
        fscanf(fin, "%s", buf);
        fprintf(result, "%s ", buf);
        fscanf(fin, "%s", buf); // 필요한 부분 -> 좌표 및 값 정보
        rows = (atoi(&buf[1]) / 100);
        cols = (atoi(&buf[1]) % 100) / 10;
        value = (atoi(&buf[1]) % 10);
        fprintf(result, "%s ", buf);
        fscanf(fin, "%s", buf);
        fprintf(result, "%s ", buf);
        fscanf(fin, "%s", buf);
        fprintf(result, "%s ", buf);
        fscanf(fin, "%s", buf); // 필요한 부분 -> true or false 정보
        if (strcmp(buf, "true)") == 0)
            solution[cols - 1][rows - 1] = value; // 솔루션에 대한 값 기입
        fprintf(result, "%s\n", buf);
    }
    pclose(fin);
    fclose(result);

    // 완성된 솔루션을 출력
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++) {
            // 솔루션을 찾지 못한 경우에 대한 예외처리
            if(solution[j][i] == 0) {
                printf("The Z3 couldn't find a solution about input sudokuX.\n");
                return 0;
            }
            printf("%d ", solution[j][i]);
        }
        printf("\n"); // 가독성을 위한 개행진행
    }
    return 0;
}