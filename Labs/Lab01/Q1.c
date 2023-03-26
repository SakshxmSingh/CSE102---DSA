#include<stdio.h>

void Merge(int mer[], int left[], int leftlen, int right[], int rightlen){
    int i=0, j=0, k=0;
    while(i<leftlen && j<rightlen){
        if (left[i]<=right[j]){
            mer[k]=left[i];
            k++, i++;
        }
        else{
            mer[k]=right[j];
            k++, j++;
        }
    }
    while (i<leftlen){
        mer[k] = left[i];
        k++, i++;
    }
    while (j<rightlen){
        mer[k] = right[j];
        k++, j++;
    }
}

void MergeSort(int arr[], int len){
    if(len<2){
        return;
    }
    int mid = len/2;
    int left[mid], right[len-mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < len; i++) {
        right[i - mid] = arr[i];
    }
    MergeSort(left, mid);
    MergeSort(right, len - mid);

    Merge(arr, left, mid, right, len-mid);
}

int main(){
    // int arr[5] = {5,1,10,7,2};
    // int n = sizeof(arr) / sizeof(arr[0]);
    int n;
    scanf("%d\n",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int arrTmp[n];
    for(int i=0; i<n; i++){
        arrTmp[i]=arr[i];
    }

    MergeSort(arr, n);

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    int i, j, sorts = 0;
    for (i = 0; i < n; i++) {
        if (arrTmp[i] != arr[i]) {
            for (j = i + 1; j < n; j++) {
                if (arrTmp[j] == arr[i]) {
                    break;
                }
            }
            int temp = arrTmp[i];
            arrTmp[i] = arrTmp[j];
            arrTmp[j] = temp;
            sorts++;
        }
    }
    printf("%d\n",sorts);
    return 0;
}