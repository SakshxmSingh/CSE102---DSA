// #include <stdio.h> 
// unsigned int Fact(int n);
// long long int ThreeXPlusOne(long long int n);

// int main(void){
//     // float z = 10/5;
//     // printf("%f",z);
//     long long int n;
//     printf("Enter number: ");
//     scanf("%lld",&n);
//     ThreeXPlusOne(n);
//     printf("\n");

//     return 0;

// }

// unsigned int Fact(int n){
//     if (n<=1){
//         return 1;
//     }
//     else{
//     return n*Fact(n-1);
//     }
// }

// long long int ThreeXPlusOne(long long int n){
//     printf("%lld ",n);
//     if(n==1){
//         return 0;
//     }
//     else if(n%2==0){
//         return ThreeXPlusOne(n/2);
//     }
//     else if(n%2!=0){
//         return ThreeXPlusOne(3*n +1);
//     }
//     else{
//         return 0;
//     }
// }

// struct Record{
//     int A;
//     int B;
//     int nums[20];
//     int nummss[20];
//     char tree[4];
//     char trees[5];
//     float yo;
//     float yoyo;
//     float yooo[20];
// } example1;

// int main(){
//     printf("%lu/n",sizeof(example1));
//     return 0;
// }


// #include <stdio.h>

// void swap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }
// void Merge(int A[], int l, int mid, int h)
// {
//     int i = l, j = mid + 1, k = l;
//     int B[100];

//     while (i <= mid && j <= h)
//     {
//         if (A[i] < A[j])
//             B[k++] = A[i++];
//         else
//             B[k++] = A[j++];
//     }
//     for (; i <= mid; i++)
//         B[k++] = A[i];
//     for (; j <= h; j++)
//         B[k++] = A[j];

//     for (i = l; i <= h; i++)
//         A[i] = B[i];
// }
// void MergeSort(int A[], int l, int h)
// {
//     int mid;
//     if (l < h)
//     {
//         mid = (l + h) / 2;
//         MergeSort(A, l, mid);
//         MergeSort(A, mid + 1, h);
//         Merge(A, l, mid, h);
//     }
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     int A[n], B[n];
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &A[i]);
//     }

//     for (int i = 0; i < n; i++)
//     {
//         B[i] = A[i];
//     }
//     MergeSort(A, 0, n);

//     for(int i=0; i<n; i++){
//         printf("%d ",A[i]);
//     }

//     int swaps = 0;
//     int j;
//     for (int i = 0; i < n; i++)
//     {
//         if (A[i] != B[i])
//         {
//             for (j = i + 1; j < n; j++)
//             {
//                 if (B[i] == A[j])
//                 {
//                     int temp = A[j];
//                     break;
//                 }
//             }

//             swap(&B[i], &B[j]);
//             swaps++;
//         }
//         // printf("%d\n", A[i]);
//     }
//     // printf("%d\n", swaps - 1);

//     return 0;
// }



#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[h-l];

    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}
void MergeSort(int A[], int l, int h)
{
    int mid;
    if (l < h)
    {
        mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}
int main()
{
    int n;
    int B[n];
    int A[n];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++)
    {
        B[i] = A[i];
    }
    
    MergeSort(A, 0, n);

    for(int i=0; i<n; i++){
        printf("%d ",A[i]);
    }

    int swaps = 0;
    int j;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != B[i])
        {
            for (j = i + 1; j < n; j++)
            {
                if (B[i] == A[j])
                {
                    int temp = A[j];
                    break;
                }
            }

            swap(&B[i], &B[j]);
            swaps++;
        }
    }
    printf("%d", swaps);

    return 0;
}