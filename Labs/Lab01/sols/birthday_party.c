#include <stdio.h>

void merge(int arr[][2], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int left[n1][2];
    int right[n2][2];

    for (int i = 0; i < n1; i++)
    {
        left[i][0] = arr[l + i][0];
        left[i][1] = arr[l + i][1];
    }

    for (int i = 0; i < n2; i++)
    {
        right[i][0] = arr[mid + 1 + i][0];
        right[i][1] = arr[mid + 1 + i][1];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i][0] <= right[j][0])
        {
            arr[k][1] = left[i][1];
            arr[k++][0] = left[i++][0];
        }
        else
        {
            arr[k][1] = right[j][1];
            arr[k++][0] = right[j++][0];
        }
    }

    while (i < n1)
    {
        arr[k][1] = left[i][1];
        arr[k++][0] = left[i++][0];
    }

    while (j < n2)
    {
        arr[k][1] = right[j][1];
        arr[k++][0] = right[j++][0];
    }
}

void merge_sort(int arr[][2], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int minSwaps(int arr[][2], int n)
{
    merge_sort(arr, 0, n - 1);

    int swap_nums = 0;
    int i = 0;
    while (i < n)
    {
        int index = arr[i][1];
        if (index != i)
        {
            // swap current placed index to its correct position
            int temp = arr[i][1];
            arr[i][1] = arr[index][1];
            arr[index][1] = temp;

            // increase swap num
            swap_nums++;
        }
        else
        {
            // case where current placed index is on correct position
            // i.e. arr[i][1] == i
            i++;
        }
    }
    return swap_nums;
}

int main()
{
    int total_deadline;
    scanf("%d", &total_deadline);

    int deadline[total_deadline][2];
    for (int i = 0; i < total_deadline; i++)
    {
        scanf("%d", &deadline[i][0]);
        deadline[i][1] = i;
    }

    printf("%d\n", minSwaps(deadline, total_deadline));
    return 0;
}
