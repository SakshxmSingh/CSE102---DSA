#include <stdio.h>

void InsertionSort(int A[], int n){
    for(int i = 0; i<n; i++){
        int j = i-1;
        int x = A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

int main(){
    int arr[] = {8,5,7,3,2};
    InsertionSort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}