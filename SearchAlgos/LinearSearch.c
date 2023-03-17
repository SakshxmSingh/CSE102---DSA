#include <stdio.h>

int LinearSearch(int A[], int ele){
    // int flag = 0;
    for(int i=0; i<sizeof(A)/sizeof(A[0]); i++){
        if(ele == A[i]){
            return i;
        }
    }
    return 0;
}

int main(){
    int arr[] = {10, 12, 34, 54, 23, 45, 667, 822, 91, 32, 59, 69, 6969, 100, 345, 540};
    printf("%d\n", LinearSearch(arr, 23));
}