#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 20

void matrixChain(int p[], int n, int m[][MAX_SIZE], int s[][MAX_SIZE]) {
    int i, l, j, k, q;

    for (i = 1; i <= n; i++) {
        m[i][i] = 0;
    }

    for (l = 2; l <= n; l++) {
        for (i = 1; i <= n - l + 1; i++) {
            j = i + l - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print(int s[][MAX_SIZE], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        print(s, i, s[i][j]);
        print(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    int matSize[MAX_SIZE];
    int n, i;
    printf("Enter the number of matrices: ");
    scanf("%d", &n);

    if (n <= 1 || n > MAX_SIZE) {
        printf("Invalid number of matrices. Please enter a number between 2 and %d\n", MAX_SIZE);
        return 1;
    }

    printf("Enter the dimensions of the matrices (separated by spaces):\n");
    for (i = 0; i <= n; i++) {
        scanf("%d", &matSize[i]);
    }

    int m[MAX_SIZE][MAX_SIZE], s[MAX_SIZE][MAX_SIZE];

    matrixChain(matSize, n, m, s);

    printf("Minimum number of multiplications: %d\n", m[1][n]);
    printf("Optimal Parenthesization: ");
    print(s, 1, n);
    printf("\n");

    return 0;
}
