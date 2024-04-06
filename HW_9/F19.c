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

int average_of_trace (int m, int n,int a[m][n]){
    int i, k, trace;

    m > n ? (k = n) : (k = m);

    for (i = 0; i < k; i++){
        trace += a[i][i];
    }
    return trace/k;
}

int num_of_max (int m, int n, int a[m][n]){
    int cnt = 0;
    int average = average_of_trace(m, n, a);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] > average)
                cnt++;
        }
    }
    return cnt;
}

int main(){
    enum{MAX_SIZE = 100};
    int s;

    printf ("Enter the square matrix size (one number):\n");
    scanf ("%d", &s);

    if (s>MAX_SIZE)
        return 0;

    int matrix[s][s];

    printf ("Enter the matrix of size [%dx%d]:\n", s, s);
    scan_matrix(s, s, matrix);
    print_matrix(s, s, matrix);

    printf ("\n%d", num_of_max(s, s, matrix));

    return 0;
}

