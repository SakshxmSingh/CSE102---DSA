#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int RecursiveBinarySearch(int arr[], int low, int upp, int key){
//     if(upp==low){
//         if(arr[low]==key){
//             return low;
//         }
//         else{
//             return 0;
//         }
//     }
//     else{
//         int mid;
//         if((upp+low)%2==0){
//             mid=(upp+low)/2;
//         }
//         else{
//             mid=(upp+low+1)/2;
//         }
//         if(arr[mid]==key){
//             return mid;
//         }
//         if(arr[mid]>key){
//             return RecursiveBinarySearch(arr, low, mid-1, key);
//         }
//         else{
//             return RecursiveBinarySearch(arr, mid+1, upp, key);
//         }
//     }
// }

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

int main(){
    int n, q;
    scanf("%d %d",&n,&q);

    int nums[n], quer[q];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &quer[i]);
    }

    int ind, newInd;

    for (int i = 0; i < q; i++) {
        ind = binarySearch(nums, 0, n-1, quer[i]);
        if (ind < n && nums[ind] == quer[i]) {
            newInd = ind - 1;
            while (ind > 0 && nums[newInd] == quer[i]) {
                newInd--;
                ind--;
            }
            printf("%d\n", ind);
        } 
        else {
            printf("%d\n", ind);
        }
    }
    return 0;
}