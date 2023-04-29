#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    MergeSort(arr, n);

    int sum=0, count =0;
    for(int i=n-1; i>=0; i--){
        sum+=arr[i];
        count++;
        if (sum>=k){
            printf("%d", count);
            break;
        }
    }
    if(sum<k){
        printf("-1");
    }
    return 0;
}