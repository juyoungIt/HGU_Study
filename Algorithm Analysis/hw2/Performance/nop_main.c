/*
 * Algorithm Analysis HW2
 * MCM Problem Solving Program
 * Writer : 21700760 Juyoung Ha
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 2147483647 // the maximum value of integer type

// print the MCM problem solution
void printSolution(int** s, int i, int j);
int calCost(int *p, int i, int j);

// The main function
int main()
{
	int *p;          // the matrix chain info
	int **m;         // the minimum number of scalar multiplication
	int **s;         // the split value of MCM
	int q;           // cost value (the number of multiplication)
	int n;           // the number of matrix
	int i, j, l, k;  // for loop variable
    int min; // the minimum value

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
    s = (int**)malloc(sizeof(int*) * (n+1)); // for index matching
    for(i=1 ; i<n+1 ; i++)
        s[i] = (int*)malloc(sizeof(int) * (n+1));

    // initiate each table value (by using negative number)
    for(i=1 ; i<=n ; i++)
        for(j=1 ; j<=n ; j++)
            s[i][j] = -1;
	
	clock_t start = clock();
    for(l=2 ; l<=n ; l++) {
        for (i=1 ; i<=n-l+1 ; i++) {
            j = i+l-1;
            min = MAX; // set the max value in integer range
            for (k=i ; k<=j-1 ; k++) {
                q = calCost(p, i, k) + calCost(p, k+1, j) + (p[i-1] * p[k] * p[j]);
                if (q < min) {
                    min = q;
                    s[i][j] = k;
                }
            }
        }
    }
	clock_t end = clock();
    
    // print the solution
    printf("Solution : ");
    printSolution(s, 1, n);
    printf("\n"); // for readability
    printf("the minimum calculation : %d\n", min);
    printf("----------------------------------------\n");
    
	// deallocate memory space
	free(p);
	for(i=1 ; i<=n ; i++)
        free(s[i]);
	free(s);

	printf("Time: %lf sec\n", (double)(end - start)/CLOCKS_PER_SEC);

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

int calCost(int *p, int i, int j)
{
    int min = MAX;
    int tmp;

    if(i == j)
        return 0;
    else {
        for(int k=i ; k<j ; k++) {
            tmp = calCost(p, i, k) + calCost(p, k+1, j) + p[i-1]*p[k]*p[j];
            if(tmp < min)
                min = tmp;
        }
        return min;
    }
}
