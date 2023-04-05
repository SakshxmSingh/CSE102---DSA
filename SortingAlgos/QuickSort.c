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

int main(){
    // int array[] = {6,2,8,5,10,9,12,1,15,7,3,13,4,11,16,14};
    int array[] = {2,4,4,239734,374,2324,45,23,45,232,4,45,6,5645,34,6,67,12234,6546};
    int n = sizeof(array)/sizeof(array[0]);
    quicksort(array, 0, n-1);

    for(int i=0; i<n; i++){
        printf("%d ", array[i]);
    }
    return 0;
}


//gfg:
// void swap(int* a, int* b) {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }
 
// // Partition the array using the last element as the pivot
// int partition(int arr[], int low, int high) {
//     int pivot = arr[high];
//     int i = (low - 1);
  
//     for (int j = low; j <= high - 1; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return (i + 1);
// }
 
// // Function to implement Quick Sort
// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         int pi = partition(arr, low, high);
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }