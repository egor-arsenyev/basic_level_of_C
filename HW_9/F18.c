#include <stdio.h>
#include <limits.h>
void scan_matrix (int m,int n,int a[m][n]){
    int i, j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++)
            scanf ("%d ", &a[i][j]);
    }
}

void print_matrix(int m, int n, int a[m][n]){
    int i, j;
    printf ("\n");
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            printf ("%-5d ", a[i][j]);
        }
    printf ("\n");
    }
}

int sum_of_max (int m, int n, int a[m][n]){
    int sum = 0;
    int max = INT_MIN;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] > max)
                max = a[i][j];
        }
        sum += max;
        max = INT_MIN;
    }
    return sum;
}

int main(){
    enum{SQR_MATR_SIZE = 10};
    int s = SQR_MATR_SIZE;
    int matrix[s][s];

    scan_matrix(s, s, matrix);
    print_matrix(s, s, matrix);
    printf ("\n%d", sum_of_max(s, s, matrix));

    return 0;
}

