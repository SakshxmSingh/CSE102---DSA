#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp; 
}

void Heapify(int arr[], int size){
    for(int i = size/2 - 1; i >= 0; i--){
        int parent = i;

        while(1){
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;
            int smallest = parent;

            if (left < size && arr[left] < arr[smallest])
                smallest = left;

            if (right < size && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != parent){
                swap(&arr[parent], &arr[smallest]);
                parent = smallest;
            }
            else{
                break;
            }
        }
    }
}


// int ExtractMin(int* arr, int size){
//     int min = arr[0];
//     swap(&arr[0], &arr[size-1]);
//     size--;

//     int i = 0;
//     while ((arr[i] > arr[2*i+1] || arr[i] > arr[2*i+2]) && (2*i+2 < size && 2*i+1 < size)){
//         if (arr[2*i+1] < arr[2*i+2]){
//             swap(&arr[i], &arr[2*i+1]);
//             i = 2*i+1;
//         }
//         else{
//             swap(&arr[i], &arr[2*i+2]);
//             i = 2*i+2;
//         }
//     }

//     Heapify(arr, size);
//     return min;
// }

int ExtractMin(int* arr, int size){
    int min = arr[0];
    swap(&arr[0], &arr[size-1]);
    size--;

    int i = 0;
    while (((arr[i] > arr[2*i+1]) || (arr[i] > arr[2*i+2])) && ((2*i+2 < size) && (2*i+1 < size))){
        if (arr[2*i+1] < arr[2*i+2]){
            swap(&arr[i], &arr[2*i+1]);
            i = 2*i+1;
        }
        else{
            swap(&arr[i], &arr[2*i+2]);
            i = 2*i+2;
        }
    }

    Heapify(arr, size);
    return min;
}



int main(){
    int size;
    scanf("%d", &size);
    int arr[size];
    for(int i=0; i<size; i++){
        scanf("%d", &arr[i]);
    }

    Heapify(arr, size);

    for(int i=0; i<size; i++){
        printf("%d ", ExtractMin(arr, size - i));
    }

    free(arr);
    return 0;
}
