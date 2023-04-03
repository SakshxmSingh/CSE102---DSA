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

int isSorted(int sorted[], int unsorted[], int len){
    for(int i=0; i<len; i++){
        if (sorted[i]!=unsorted[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d\n",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int unsorted[n];
    for(int i=0; i<n; i++){
        unsorted[i]=arr[i];
    }

    MergeSort(arr, n);

    int i, j, sorts = 0;
    while(isSorted(arr, unsorted, n)==0){
        for (i = 0; i < n; i++) {
            if (unsorted[i] != arr[i]) {
                j = RecursiveBinarySearch(arr, 0, n-1, unsorted[i]);

                int temp = unsorted[j];
                unsorted[j] = unsorted[i];
                unsorted[i] = temp;
                sorts++;
            }
        }
    }
    printf("%d\n",sorts);
    return 0;
}