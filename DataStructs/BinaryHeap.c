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

int ExtractMin(int* arr, int size){
    int min = arr[0];
    swap(&arr[0], &arr[size-1]);
    // free(arr[size-1]);
    size--;
    // *arr = realloc(arr, size*sizeof(int));

    int i=0;
    while (arr[i]>arr[2*i+1] || arr[i]>arr[2*i+2] && 2*i+2<size && 2*i+1<size){
        if (arr[2*i+1]<arr[2*i+2]){
            swap(&arr[i], &arr[2*i+1]);
            i = 2*i+1;
        }
        else{
            swap(&arr[i], &arr[2*i+2]);
            i = 2*i+2;
        }
    }

    return min;
}

void InsertX(int arr[], int x, int size){
    size++;
    *arr = realloc(arr, size*sizeof(int));
    arr[size-1] = x;

    int i = size-1;
    while (arr[i]<arr[(i-1)/2] && i>0){
        swap(&arr[i], &arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void Heapify(int arr[], int size){
    for(int i=size-1; i>=0; i--){
        while (arr[i]>arr[2*i+1] || arr[i]>arr[2*i+2] && 2*i+2<size && 2*i+1<size){
            if (arr[2*i+1]<arr[2*i+2]){
                swap(&arr[i], &arr[2*i+1]);
                i = 2*i+1;
            }
            else{
                swap(&arr[i], &arr[2*i+2]);
                i = 2*i+2;
            }
        }
    }
}




int main(){
    int heap = {4,14,9,17,23,21,29,91,37,25,88,33};
    // int size = sizeof(heap)/sizeof(heap[0]);



    // for(int i=0; i<size; i++){
    //     printf("%d", ExtractMin(heap, size));
    // }

    // int arr[] = {2,3,7,1,8,6,5,4};

    // printf("index of 9: %d\n", LinearSearch(heap, 9, size));

    // printf("Min: %d\n", FindMinHeap(heap));
    // printf("Left of 9: %d\n", LeftX(heap, 9, size));
    // printf("Right of 9: %d\n", RightX(heap, 9, size));
    // printf("Parent of 9: %d\n", ParentX(heap, 9, size));

    return 0;
}