#include <stdio.h>
void scan_matrix (int m,int n,int a[m][n]){
    int i, j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++)
            scanf ("%d ", &a[i][j]);
    }
}

void print_matrix(int m, int n, int a[m][n]){
    int i, j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            printf ("%-5d ", a[i][j]);
        }
    printf ("\n");
    }
}

int trace_of_matrix (int m, int n,int a[m][n]){
    int i, k, trace;

    m > n ? (k = n) : (k = m);

    for (i = 0; i < k; i++){
        trace += a[i][i];
    }
    return trace;
}

int main(){
    enum{MAX_SIZE = 100};
    int m, n;

    scanf ("%d%d", &m, &n);

    if ((m>MAX_SIZE)&&(n>MAX_SIZE))
        return 0;

    int matrix[m][n];

    scan_matrix(m, n, matrix);
    print_matrix(m, n, matrix);
    printf ("\n%d", trace_of_matrix(m, n, matrix));

    return 0;
}

