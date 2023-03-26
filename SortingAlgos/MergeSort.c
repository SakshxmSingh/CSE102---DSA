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
    int arr1[5] = {1,3,8,9,10};
    int arr2[8] = {1,2,6,7,10,12,13,16};
    int arr3[sizeof(arr1)/sizeof(arr1[0])+sizeof(arr2)/sizeof(arr2[0])];

    Merge(arr3, arr1, sizeof(arr1)/sizeof(arr1[0]), arr2, sizeof(arr2)/sizeof(arr2[0]));

    int arr4[22] = {5,6,7,23,2,6,8,2,3,5,7,8,34,55,623,223,677,45,23,909,343,56};

    MergeSort(arr4, sizeof(arr4)/sizeof(arr4[0]));

    for(int i=0; i<sizeof(arr3)/sizeof(arr3[0]); i++){
        printf("%d ", arr3[i]);
    } printf("\n");

    for(int i=0; i<sizeof(arr4)/sizeof(arr4[0]); i++){
        printf("%d ", arr4[i]);
    } printf("\n");

    return 0;
}