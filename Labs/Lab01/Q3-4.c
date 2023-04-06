#include <stdio.h>

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

int CountSubArrs(int arr[], int left, int right, int val){
    int count=0, i=left, j=left, dinct=0;
    int freq[101]={0};
    while (j<=right+1){
        if(freq[arr[j]]==0){
            dinct++;
        }
        freq[arr[j]]++;

        while (dinct>val){
            freq[arr[i]]--;
            if(freq[arr[i]]==0){
                dinct--;
            }
            i++;
        }
        if (dinct==val){
            count+=1;
        }
        j++;
    }
    if (j==right+1){
        while(i<=right+1){
            freq[arr[i]]--;
            if(freq[arr[i]]==0){
                dinct--;
            }
            i++;
            if (dinct==val){
                count+=1;
            }
        }
    }
    return count;
}

int main(){
    int n,q;
    scanf("%d",&n);
    scanf("%d", &q);

    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }

    int attrs[q][3];
    for(int i=0;i<q;i++){
        scanf("%d",&attrs[i][0]);
        scanf("%d",&attrs[i][1]);
        scanf("%d",&attrs[i][2]);
    }

    MergeSort(A,n);

    for (int i = 0; i < q; i++){
        printf("%d\n", CountSubArrs(A, attrs[i][0]-1, attrs[i][1], attrs[i][2]));
    }
    //lol
    return 0;
}