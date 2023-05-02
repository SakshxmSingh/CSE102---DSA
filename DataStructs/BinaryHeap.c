#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int leftx(int x){
//     return 2*x+1;
// }
int LinearSearch(int A[], int ele, int size){
    // int flag = 0;
    for(int i=0; i<size; i++){
        if(ele == A[i]){
            return i;
            break;
        }
    }
    return 0;
}

int FindMinHeap(int arr[]){
    return arr[0];
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp; 
}
int min(int a, int b){
    return a<b?a:b;
}
int LeftX(int arr[], int x, int size){
    int i = LinearSearch(arr, x, size);
    return arr[2*i+1];
}

int RightX(int arr[], int x, int size){
    int i = LinearSearch(arr, x, size);
    return arr[2*i+2];
}

int ParentX(int arr[], int x, int size){
    int i = LinearSearch(arr, x, size);
    return arr[(i-1)/2];
}

int ExtractMin(int arr[], int size){
    int min = arr[0];
    swap(&arr[0], &arr[size-1]);
    free(arr[size-1]);
    size--;
    *arr = realloc(arr, size*sizeof(int));
    // while(1==0){};

    return min;
}


int main(){
    int heap[] = {4,14,9,17,23,21,29,91,37,25,88,33};
    int size = sizeof(heap)/sizeof(heap[0]);

    // printf("index of 9: %d\n", LinearSearch(heap, 9, size));

    // printf("Min: %d\n", FindMinHeap(heap));
    // printf("Left of 9: %d\n", LeftX(heap, 9, size));
    // printf("Right of 9: %d\n", RightX(heap, 9, size));
    // printf("Parent of 9: %d\n", ParentX(heap, 9, size));

    return 0;
}