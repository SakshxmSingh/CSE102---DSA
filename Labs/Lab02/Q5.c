#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int arr[], int left, int right){
    int max=0;
    for(int i = left; i<=right; i++){
        if(arr[i]>max) max=arr[i];
    }
    return max;
}

int max_comp(int a, int b){
    return a>=b ? a : b;
}


int main(){
    int n, k;
    scanf("%d %d",&n,&k);
    int arr[n], ishu=0, rohu=0, left=0, right=k-1, turn=0;

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int maxv = max(arr,left,right);

    while(right<n){
        if(turn%2==0){
            ishu+=maxv;
        }
        else{
            rohu+=maxv;
        }
        if (maxv==arr[left]){
            maxv=max(arr,left+1,right+1);
        }
        else{
            maxv=max_comp(maxv,arr[right+1]);
        }
        left++; right++; turn++;
    }

    if(ishu>rohu){
        printf("ishu\n");
    }
    else if(rohu>ishu){
        printf("rohu\n");
    }
    else if(rohu==ishu){
        printf("draw\n");
    }

    return 0;
}