/*
 * Algorithm Analysis HW2
 * MCM Problem Solving Program
 * Writer : 21700760 Juyoung Ha
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 2147483647 // the maximum value of integer type

// print the MCM problem solution
void printSolution(int **s, int i, int j);

// The main function
int main()
{
	int *p;          // the matrix chain info
	int **m;         // the minimum number of scalar multiplication
	int **s;         // the split value of MCM
	int q;           // cost value (the number of multiplication)
	int n;           // the number of matrix
	int i, j, l, k;  // for loop variable

	// enter the length of matrix-chain
	printf("Enter the matrix-chain length : ");
	scanf("%d", &n);
	// enter the matrix info
	p = (int*)malloc(sizeof(int) * (n+1));
	printf("Enter the matrix-chain value. (A1.rows, A1.columns, A2.columns, A3.columns ... )\n  => ");
	for(i=0 ; i<=n ; i++)
		scanf("%d", &p[i]);
    // for test - print the input result
    printf("----------------------------------------\n");
    printf("         <The matrix List>\n\n");
    for(i=1 ; i<=n ; i++)
        printf("Matrix %d : %d X %d\n", i, p[i-1], p[i]);
    printf("----------------------------------------\n");

	// allocate the memory space
    m = (int**)malloc(sizeof(int*) * (n+1)); // for index matching - 1
    s = (int**)malloc(sizeof(int*) * (n+1)); // for index matching - 2
    for(i=1 ; i<n+1 ; i++) {
        m[i] = (int*)malloc(sizeof(int) * (n+1));
        s[i] = (int*)malloc(sizeof(int) * (n+1));
    }

    // initiate each table value (by using negative number)
    for(i=1 ; i<=n ; i++) {
        for(j=1 ; j<=n ; j++) {
            m[i][j] = -1;
            s[i][j] = -1;
        }
    }

    // Dynamic Programming (bottom-up approach + memoization)
    // case1 : matrix-chain length == 1
    for(i=1 ; i<=n ; i++)
        m[i][i] = 0;
    // case2 : matrix-chain length > 1
    for(l=2 ; l<=n ; l++) {
        for (i=1 ; i<=n-l+1 ; i++) {
            j = i+l-1;
            m[i][j] = MAX; // set the max value in integer range
            for (k=i ; k<=j-1 ; k++) {
                q = m[i][k] + m[k+1][j] + (p[i-1] * p[k] * p[j]);
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // print the matrix table - 1
    printf("      <The matrix table m[i, j]>\n\n");
    for(i=1 ; i<=n ; i++) {
        for(j=1 ; j<=n ; j++) {
            printf("%7d", m[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------------\n");

    // print the matrix table - 2
    printf("      <The matrix table s[i, j]>\n\n");
    for(i=1 ; i<=n ; i++) {
        for(j=1 ; j<=n ; j++) {
            printf("%7d", s[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------------\n");

    // print the solution
    printf("Solution : ");
    printSolution(s, 1, n);
    printf("\n"); // for readability
    printf("the minimum calculation : %d\n", m[1][n]);
    printf("----------------------------------------\n");

	// deallocate memory space
	free(p);
	for(i=1 ; i<=n ; i++) {
        free(m[i]);
        free(s[i]);
	}
	free(m);
	free(s);

	return 0;
}

// print the MCM problem solution
void printSolution(int** s, int i, int j)
{
    if(i == j)
        printf("A%d", i);
    else {
        printf("(");
        printSolution(s, i, s[i][j]);
        printSolution(s, s[i][j]+1, j);
        printf(")");
    }
}