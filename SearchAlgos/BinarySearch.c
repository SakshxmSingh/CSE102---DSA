#include <stdio.h>

void InsertionSort(int arr[], int n){
    for(int i = 0; i<n; i++){
        int j = i-1;
        int x = arr[i];
        while(j>-1 && arr[j]>x){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
}

int RecursiveBinarySearch(int arr[], int low, int upp, int key){
    if(upp==low){
        if(arr[low]==key){
            return low;
        }
        else{
            return 0;
        }
    }
    else{
        int mid;
        if((upp+low)%2==0){
            mid=(upp+low)/2;
        }
        else{
            mid=(upp+low+1)/2;
        }
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            return RecursiveBinarySearch(arr, low, mid-1, key);
        }
        else{
            return RecursiveBinarySearch(arr, mid+1, upp, key);
        }
    }
}

int main(){
    int arr[] = {10, 12, 34, 54, 23, 45, 667, 822, 91, 32, 59, 69, 6969, 100, 345, 540, 23, 23, 23};
    InsertionSort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int k=0; k<sizeof(arr)/sizeof(arr[0]); k++){
        printf("%d  ",arr[k]);
    }

    printf("\n%d\n", RecursiveBinarySearch(arr, 0, sizeof(arr)/sizeof(arr[0])-1, 23));

    // int low=0, upp=sizeof(arr)/sizeof(arr[0])-1, key=23;
    return 0;
}