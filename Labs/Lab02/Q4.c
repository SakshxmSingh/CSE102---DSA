#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct one_coords{
    int x;
    int y;
}one_coords;

int max(int a, int b){
    return a>=b ? a : b;
}

int min_arr(int arr[], int n){
    int min=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]<=min) min = arr[i];
    }
    return min;
}

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    int mat[m][n];
    one_coords *ones = malloc(sizeof(one_coords));
    int one_count=0;

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &mat[i][j]);
            if (mat[i][j]==1){
                ones[one_count].x=j;
                ones[one_count].y=i;
                one_count+=1;
                ones = realloc(ones, (1+one_count)*sizeof(one_coords));
            }
        }
    }

    int count = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if (mat[i][j]==0){
                int tmp[one_count];
                for(int k=0; k<one_count; k++){
                    tmp[k] = max(abs(ones[k].x - j) , abs(ones[k].y - i));
                }
                count = min_arr(tmp,one_count) >= count ? min_arr(tmp, one_count) : count;
            }
        }
    }

    printf("%d\n", count);

    free(ones);

    return 0;
}