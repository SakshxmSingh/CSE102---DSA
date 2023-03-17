#include <stdio.h>

void BubbleSort(int A[], int n){
    int flag;
    for(int i=0; i<n-1; i++){
        flag=0;
        for(int j=0; j<n-1-i; j++){
            if(A[j]>A[j+1]){
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                flag = 1;
            }
        }
        if (flag==0) break;
    }
}


int main(){
    int arr[] = {8,5,7,3,2};
    BubbleSort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        printf("%d ", arr[i]);
    }
    return 0;
}