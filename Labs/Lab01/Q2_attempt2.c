#include <stdio.h>

typedef struct colsum{
    int data;
    int index;
} colsum;


void swap(colsum* a, colsum* b) {
    colsum t = *a;
    *a = *b;
    *b = t;
}
 
int partition(colsum arr[], int low, int high) {
    int pivot = arr[high].data;
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].data < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(colsum arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printmatt(int m, int n, int matt[m][n]){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", matt[i][j]);
        }
        printf("\n");
    }
}


int main(){
    int m, n;
    scanf("%d ",&m);
    scanf("%d",&n);

    colsum colsum_arr[n];
    int matt[m][n];

    for (int i = 0; i < n; i++){
        colsum_arr[i].data=0;
        // colsum_unsort[i]=0;
        colsum_arr[i].index=i;
    }


    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){
            scanf("%d", &matt[i][j]);
            colsum_arr[j].data += matt[i][j];
        }
    }

    quickSort(colsum_arr, 0, n-1);

    for(int k=0; k<20; k++){
        for(int i=1;i<n;i++){
            if(colsum_arr[i].data==colsum_arr[i-1].data){
                if(colsum_arr[i].index<colsum_arr[i-1].index){
                    swap(&colsum_arr[i], &colsum_arr[i-1]);
                }
            }
        }
    }

    // printmatt(m,n,matt);

    // printf("\n\n");
    // for(int i = 0; i<n; i++){
    //     printf("%d ",colsum_arr[i].data);
    // }
    // printf("\n");
    // for(int i = 0; i<n; i++){
    //     printf("%d ",colsum_arr[i].index);
    // }
    // printf("\n\n");

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", matt[i][colsum_arr[j].index]);
        }
        printf("\n");
    }

    return 0;
}

