#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;
    while (i < j) {
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quicksort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quicksort(arr, left, pi-1);
        quicksort(arr, pi + 1, right);
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

    int colsum[n];

    int matt[m][n];
    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){
            scanf("%d", &matt[i][j]);
            colsum[j]+=matt[i][j];
        }
    }
    




    printmatt(m,n,matt);

    return 0;
}

