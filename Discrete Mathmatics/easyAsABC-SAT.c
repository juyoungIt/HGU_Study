#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문자 1개를 입력받게 이에 대응하는 정수코드를 반환
int charToInt(char c) {
    if(c == 'A') return 1;
    if(c == 'B') return 2;
    if(c == 'C') return 3;
    if(c == 'D') return 4;
    if(c == 'E') return 5;
    return 0;
}

int main() {

    FILE *fp = fopen("formula.txt", "w"); // 명제논리 방정식
    // FILE *input = fopen("input.txt", "r"); // 초기 input

    // 1. input.txt로 부터 grid의 사이즈를 불러옴
    int size; // 사용하는 그리드의 사이즈 정보를 저장
    // fscanf(input, "%d", &size);
    scanf("%d", &size);

    // 1-1. input.txt 로부터 top, bottom, left, right 정보 리딩
    char top[15], bottom[15], left[15], right[15]; // 사전 제약조건 세팅 정보
    // fscanf(input, "%s", top); // top의 정보를 읽어옴
    // fscanf(input, "%s", bottom); // bottom의 정보를 읽어옴
    // fscanf(input, "%s", left); // left의 정보를 읽어옴
    // fscanf(input, "%s", right); // right의 정보를 읽어옴
    scanf("%s", top);
    scanf("%s", bottom);
    scanf("%s", left);
    scanf("%s", right);

    // 리딩한 정보를 화면상에 표시
    printf("<The reading information>\n");
    printf("size   : %dx%d\n", size, size);
    printf("top    : %s\n", top);
    printf("bottom : %s\n", bottom);
    printf("left   : %s\n", left);
    printf("right  : %s\n\n", right);

    // grid 바깥쪽의 제약조건과 관련된 명제 생성
    for(int i=0 ; i<size ; i++) {
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(declare-const t%d%d Bool)\n", i, c); // top
            fprintf(fp, "(declare-const b%d%d Bool)\n", i, c); // bottom
            fprintf(fp, "(declare-const l%d%d Bool)\n", i, c); // left
            fprintf(fp, "(declare-const r%d%d Bool)\n", i, c); // right
        }
    }

    // 방정식 작성을 위한 명제논리 작성(6*size*size개)
    // A - 1 / B - 2 / C - 3 / D - 4 / E - 5
    for(int i=0 ; i<size ; i++) {
        for(int j=0 ; j<size ; j++) {
            for(int c=1 ; c<=5 ; c++) {
                fprintf(fp, "(declare-const p%d%d%d Bool)\n", i, j, c);
            }
        }
    }

    // Q0
    // grid 외곽에 대한 정보에 대한 formula 를 작성
    char t_tmp, b_tmp, l_tmp, r_tmp; // 읽어온 단일문자를 임시저장
    fprintf(fp, "; Q0\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        t_tmp = top[i];
        b_tmp = bottom[i];
        l_tmp = left[i];
        r_tmp = right[i];
        if(t_tmp !=  '_')
            fprintf(fp, "t%d%d ", i, charToInt(t_tmp));
        if(b_tmp !=  '_')
            fprintf(fp, "b%d%d ", i, charToInt(b_tmp));
        if(l_tmp !=  '_')
            fprintf(fp, "l%d%d ", i, charToInt(l_tmp));
        if(r_tmp !=  '_')
            fprintf(fp, "r%d%d ", i, charToInt(r_tmp));
    }
    fprintf(fp, "))\n");

    // 본래 값을 지키기 위해서 처리해주는 부분
    fprintf(fp, "; Q0\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(not (or ");
    for(int i=0 ; i<size ; i++) {
        t_tmp = top[i];
        b_tmp = bottom[i];
        l_tmp = left[i];
        r_tmp = right[i];
        if(t_tmp == '_') {
            for(int j=1 ; j<=5 ; j++)
                fprintf(fp, "t%d%d ", i, j);
        }
        else {
            for(int j=1 ; j<=5 ; j++)
                if(charToInt(t_tmp) != j)
                    fprintf(fp, "t%d%d ", i, j);
        }
        if(b_tmp == '_') {
            for(int j=1 ; j<=5 ; j++)
                fprintf(fp, "b%d%d ", i, j);
        }
        else {
            for(int j=1 ; j<=5 ; j++)
                if(charToInt(b_tmp) != j)
                    fprintf(fp, "b%d%d ", i, j);
        }
        if(l_tmp == '_') {
            for(int j=1 ; j<=5 ; j++)
                fprintf(fp, "l%d%d ", i, j);
        }
        else {
            for(int j=1 ; j<=5 ; j++)
                if(charToInt(l_tmp) != j)
                    fprintf(fp, "l%d%d ", i, j);
        }
        if(r_tmp == '_') {
            for(int j=1 ; j<=5 ; j++)
                fprintf(fp, "r%d%d ", i, j);
        }
        else {
            for(int j=1 ; j<=5 ; j++)
                if(charToInt(r_tmp) != j)
                    fprintf(fp, "r%d%d ", i, j);
        }
    }
    fprintf(fp, ")))\n");

    // Q1
    // 각 row가 5개의 명제 중에서 적어도 하나를 참으로 가져야 함
    fprintf(fp, "; Q1\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(or ");
            for(int j=0 ; j<size ; j++) {
                fprintf(fp, "p%d%d%d ", i, j, c);
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q2
    // 각 cols가 6개의 명제 중에서 적어도 하나를 참으로 가져야 함
    fprintf(fp, "; Q2\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int j=0 ; j<size ; j++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(or ");
            for(int i=0 ; i<size ; i++) {
                fprintf(fp, "p%d%d%d ", i, j, c);
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q3
    // 각 셀이 하나의 문자만을 참으로 가지도록 함
    fprintf(fp, "; Q3\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int j=0 ; j<size ; j++) {
            fprintf(fp, "(and ");
            for(int c=1; c<=4 ; c++) {
                fprintf(fp, "(and ");
                for(int k=c+1 ; k<=5 ; k++) {
                    fprintf(fp, "(not (and p%d%d%d p%d%d%d))", i, j, c, i, j, k);
                }
                fprintf(fp, ")");
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q4 -> A ~ E 문자가 각 row, cols에서 고유하게 나타나도록 함
    fprintf(fp, "; Q4\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(and ");
            for(int j=0 ; j<size-1 ; j++) {
                fprintf(fp, "(and ");
                for(int m=j+1 ; m<size ; m++) {
                    fprintf(fp, "(not (and p%d%d%d p%d%d%d))", i, j, c, i, m, c);
                }
                fprintf(fp, ")");
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q5 각 cols에 대해서 고유하게 문자가 나타날 수 있도록 하는 부분
    fprintf(fp, "; Q5\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(and ");
            for(int j=0 ; j<size-1 ; j++) {
                fprintf(fp, "(and ");
                for(int m=j+1 ; m<size ; m++) {
                    fprintf(fp, "(not (and p%d%d%d p%d%d%d))", j, i, c, m, i, c);
                }
                fprintf(fp, ")");
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q6 top에 대한 제약조건을 처리하는 부분
    // 해당 문자가 유효한 영역에 들어올 수 있도록 하는 부분
    fprintf(fp, "; Q6\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(or ");
            for(int k=0 ; k<=size-5 ; k++) {
                fprintf(fp, "(=> t%d%d p%d%d%d)", i, c, k, i, c);
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q7  bottom에 대한 제약조건을 처리하는 부분
    // 해당 문자가 유효한 영역에 들어올 수 있도록 하는 부분
    fprintf(fp, "; Q7\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(or ");
            for(int k=size-1 ; k >= 4 ; k--) {
                fprintf(fp, "(=> b%d%d p%d%d%d)", i, c, k, i, c);
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q8 left에 대한 제약조건을 처리하는 부분
    // 해당 문자가 유효한 영역에 들어올 수 있도록 하는 부분
    fprintf(fp, "; Q8\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(or ");
            for(int k=0 ; k<=size-5 ; k++) {
                fprintf(fp, "(=> l%d%d p%d%d%d)", i, c, i, k, c);
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // Q9 right에 대한 제약조건을 처리하는 부분
    // 해당 문자가 유효한 영역에 들어올 수 있도록 하는 부분
    fprintf(fp, "; Q9\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(or ");
            for(int k=size-1 ; k>=4 ; k--) {
                fprintf(fp, "(=> r%d%d p%d%d%d)", i, c, i, k, c);
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");
/*
    // Q10 top에 대한 부분
    fprintf(fp, "; Q10\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(or ");
            for(int k=0 ; k<=size-5 ; k++) {
                fprintf(fp, "(and ");
                for(int m=1 ; m<=5 ; m++) {
                    fprintf(fp, "(=> t%d%d (not p%d%d%d))", i, c, k, i, m);
                }
                fprintf(fp, ")");
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // bottom에 대한 부분
    fprintf(fp, "; Q11\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(or ");
            for(int k=size-1 ; k>=4 ; k--) {
                fprintf(fp, "(and ");
                for(int m=1 ; m<=5 ; m++) {
                    fprintf(fp, "(=> b%d%d (not p%d%d%d))", i, c, k ,i, m);
                }
                fprintf(fp, ")");
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // left에 대한 부분
    fprintf(fp, "; Q12\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(or ");
            for(int k=0 ; k<=size-5 ; k++) {
                fprintf(fp, "(and ");
                for(int m=1 ; m<=5 ; m++) {
                    fprintf(fp, "(=> l%d%d (not p%d%d%d))", i, c, i, k, m);
                }
                fprintf(fp, ")");
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");

    // right에 대한 부분
    fprintf(fp, "; Q13\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            fprintf(fp, "(or ");
            for(int k=size-1 ; k>=4 ; k--) {
                fprintf(fp, "(and ");
                for(int m=1 ; m<=5 ; m++) {
                    fprintf(fp, "(=> r%d%d (not p%d%d%d))", i, c, i, k, m);
                }
                fprintf(fp, ")");
            }
            fprintf(fp, ")");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");
    */
/*
    // Q10 - top에 대한 예외 처리와 관련된 부분
    fprintf(fp, "; Q10\n");
    fprintf(fp, "(assert ");
    fprintf(fp, "(and ");
    for(int i=0 ; i<size ; i++) {
        fprintf(fp, "(and ");
        for(int c=1 ; c<=5 ; c++) {
            // 외부의 식과 관련된 부분
            fprintf(fp, "(=> t%d%d ", i, c);
            fprintf(fp, "(or ");
            for(int k=0 ; k<=size-5 ; k++) {
                fprintf(fp, "(and ");
                // 내부에서 반복되는 식과 관련된 부분
                for(int h=0 ; h<=k ; h++) {
                    if((k == 0 && h == 0) || k == h)
                        fprintf(fp, "p%d%d%d ", h, i, c);
                    else
                        fprintf(fp, "(not p%d%d%d) ", h, i, c);
                }
                fprintf(fp, ")");
            }
            fprintf(fp, "))");
        }
        fprintf(fp, ")");
    }
    fprintf(fp, "))\n");
*/
    fprintf(fp, "(check-sat)\n(get-model)\n");

    // 사용한 파일 스트림을 닫음
    fclose(fp);
    // fclose(input);


    // 솔루션을 구하고 출력하는 파트
    int solution[10][10] = {0};

    FILE *fin = popen("z3 formula.txt", "r");
    FILE *result = fopen("solution.txt", "w");

    char buf[128];
    fscanf(fin, "%s %s", buf, buf);
    int rows, cols, value; // 가로좌표, 세로좌표, 값을 저장하는 변수
    char buf2[128]; // 비교연산을 위한 임시저장용
    while (!feof(fin))
    {
        fscanf(fin, "%s", buf);
        fprintf(result, "%s ", buf);
        fscanf(fin, "%s", buf); // 필요한 부분 -> 좌표 및 값 정보
        strcpy(buf2, buf);
        rows = (atoi(&buf[1]) / 100);
        cols = (atoi(&buf[1]) % 100) / 10;
        value = (atoi(&buf[1]) % 10);
        fprintf(result, "%s ", buf);
        fscanf(fin, "%s", buf);
        fprintf(result, "%s ", buf);
        fscanf(fin, "%s", buf);
        fprintf(result, "%s ", buf);
        fscanf(fin, "%s", buf); // 필요한 부분 -> true or false 정보
        if (buf2[0] == 'p' && strcmp(buf, "true)") == 0)
            solution[cols][rows] = value; // 솔루션에 대한 값 기입
        fprintf(result, "%s\n", buf);
    }

    pclose(fin);
    fclose(result);

    // 완성된 솔루션을 화면에 출력
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++) {
            if(solution[j][i] == 0) {
                printf("_ ");
            }
            else if(solution[j][i] == 1)
                printf("A ");
            else if(solution[j][i] == 2)
                printf("B ");
            else if(solution[j][i] == 3)
                printf("C ");
            else if(solution[j][i] == 4)
                printf("D ");
            else if(solution[j][i] == 5)
                printf("E ");
            else
                printf("? ");
        }
        printf("\n"); // 가독성을 위한 개행진행
    }
    return 0;
}
