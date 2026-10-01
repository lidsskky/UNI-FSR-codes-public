#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int n;
    printf("The size of matrix: ");
    scanf("%d", &n);
    double ** mat = (double**)malloc(n * sizeof(double*));
    printf("The matrix:\n");
    for (int i=0; i<n; i++){
        mat[i] = (double*)malloc(n * sizeof(double));
        for (int j=0; j<n; j++){
            scanf("%lf", &mat[i][j]);
        }
    }

    double det = 1.0;
    int pi;
    int flag = 1;
    double tmp;
    for (int i=0; i<n; i++){
        if (flag){
            pi = i;
            for (int j=i+1; j<n; j++){
                if (fabs(mat[j][i]) > fabs(mat[pi][i])) pi = j;
            }
            if (fabs(mat[pi][i]) < 1e-9){
                det = 0.0;
                flag = 0;
            }
            if (i != pi){
                for (int j=0; j<n; j++){
                    tmp = mat[i][j];
                    mat[i][j] = mat[pi][j];
                    mat[pi][j] = tmp;
                }
                det *= (-1);
            }
            det *= mat[i][i];
            for (int j=i+1; j<n; j++){
                mat[i][j] /= mat[i][i];
            }
            for (int j=0; j<n; j++){
                if (j != i){
                    if (fabs(mat[j][i]) > 1e-9){
                        for (int t=i+1; t<n; t++){
                            mat[j][t] -= (mat[i][t] * mat[j][i]);
                        }
                    }
                }
            }
        }
    }
    printf("Determinator: %lf", det);
    for (int i=0; i<n; i++){
        free(mat[i]);
    }
    free(mat);
    return 0;
}
