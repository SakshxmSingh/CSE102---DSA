#include <stdio.h>

void swap(int a[], int b[])
{
    int tempVal = a[0];
    int tempInd = a[1];
    a[0] = b[0];
    a[1] = b[1];
    b[0] = tempVal;
    b[1] = tempInd;
}

int partition(int arr[][2], int start, int end)
{
    int pivot = arr[end][0];
    int pivotInd = arr[end][1];

    int justGreater = start - 1;
    for (int i = start; i < end; i++)
    {
        if (arr[i][0] < pivot || (arr[i][0] == pivot && arr[i][1] < pivotInd))
        {
            justGreater++;
            swap(arr[i], arr[justGreater]);
        }
    }
    swap(arr[justGreater + 1], arr[end]);
    return justGreater + 1;
}

void quickSort(int arr[][2], int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int pivotInd = partition(arr, start, end);
    quickSort(arr, start, pivotInd - 1);
    quickSort(arr, pivotInd + 1, end);
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    int cumSum[n][2];
    memset(cumSum, 0, sizeof cumSum);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
            cumSum[j][0] += arr[i][j];
            cumSum[j][1] = j;
        }
    }

    quickSort(cumSum, 0, n - 1);

    int output[m][n];

    for (int j = 0; j < n; j++)
    {
        int colInd = cumSum[j][1];

        for (int i = 0; i < m; i++)
        {
            output[i][j] = arr[i][colInd];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", output[i][j]);
        }
        printf("\n");
    }
    return 0;
}