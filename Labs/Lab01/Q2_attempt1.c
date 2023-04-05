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

int isSorted(int sorted[], int colsum_unsort[], int len){
    for(int i=0; i<len; i++){
        if (sorted[i]!=colsum_unsort[i]){
            return 0;
        }
    }
    return 1;
}

int RecursiveBinarySearch(int arr[], int low, int upp, int key){
    if(upp==low){
        if(arr[low]==key){
            return low;
        }
        else{
            return 0;
        }
    }
    else{
        int mid;
        if((upp+low)%2==0){
            mid=(upp+low)/2;
        }
        else{
            mid=(upp+low+1)/2;
        }
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            return RecursiveBinarySearch(arr, low, mid-1, key);
        }
        else{
            return RecursiveBinarySearch(arr, mid+1, upp, key);
        }
    }
}

int main(){
    int m, n;
    scanf("%d ",&m);
    scanf("%d",&n);

    int colsum[n], indexes[n], matt[m][n], colsum_unsort[n];

    for (int i = 0; i < n; i++){
        colsum[i]=0;
        colsum_unsort[i]=0;
        indexes[i]=i;
    }

    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){
            scanf("%d", &matt[i][j]);
            colsum[j]+=matt[i][j];
            colsum_unsort[j]+=matt[i][j];

        }
    }

    quicksort(colsum, 0, n-1);

    // for(int i=0;i<n;i++){
    //     printf("%d ", colsum_unsort[i]);
    // }

    int i,j;
    while(isSorted(colsum, colsum_unsort, n)==0){
        for (i = 0; i < n; i++) {
            if (colsum_unsort[i] != colsum[i]) {
                j = RecursiveBinarySearch(colsum, 0, n-1, colsum_unsort[i]);

                int temp = indexes[j];
                indexes[j] = indexes[i];
                indexes[i] = temp;

                int temp2 = colsum_unsort[j];
                colsum_unsort[j] = colsum_unsort[i];
                colsum_unsort[i] = temp2;
            }
        }
    }

    for(int i=1;i<n;i++){
        if(colsum[i]==colsum[i-1]){
            if(indexes[i]<indexes[i-1]){
                swap(&indexes[i], &indexes[i-1]);
            }
        }
    }

    int output_matt[m][n];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            output_matt[i][j]=matt[i][indexes[j]];
        }
    }

    // printf("\n");
    // for(int i=0;i<n;i++){
    //     printf("%d ", indexes[i]);
    // }
    // printf("\n\n");

    printmatt(m,n,output_matt);


    // for(int i=0;i<n;i++){
    //     printf("%d ", colsum[i]);
    // }
 

    return 0;
}

