#include <stdio.h>

void SelectionSort(int A[], int n){
    for(int i=0; i<n; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(A[min]>A[j]){
                min=j;
            }
        }
        int temp = A[i];
        A[i] = A[min];
        A[min] = temp;
    }
}

int main(){
    int arr[] = {8,5,7,3,2};
    SelectionSort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}