// Online C compiler to run C program online
#include <stdio.h>

int check(int arr[], int n, int i, int mid, int un)
{
    int f[101];
    for (int k = 0; k < 101; ++k)
        f[k] = 0;
    for (int k = i; k <= mid; ++k)
        f[arr[k]]++;
    // int res = 1;
    for (int k = 0; k < 101; ++k)
    {
        if (f[k] > 0)
        {
            un--;
        }
    }
    if (un == 0)
        return 1;
    else if (un > 0)
        return 2;
    return 0;
}

int find_occur(int arr[], int num, int l, int r)
{
    int left = l, right = r;
    int f = 0;
    int ans = 0;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == num)
        {
            ans = mid;
            f = 1;
            right = mid - 1;
        }
        else if (arr[mid] < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    if (f)
        return r - ans + 1;
    return ans;
}

int solve(int arr[], int n, int l, int r, int un)
{
    int ans = 0;
    for (int i = l; i <= r; ++i)
    {
        int left = i, right = r;
        int j = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int v = check(arr, n, i, mid, un);
            if (v == 1)
            {
                j = mid;
                left = mid + 1;
            }
            else if (v == 2)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        if (j != -1)
            ans += find_occur(arr, arr[j], i, j);
        // if(ans<j-i+1) ans = j-i+1;
    }
    return ans;
}

int main()
{
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    int arr[n];
    int freq[101];
    for (int i = 0; i < 101; i++)
        freq[i] = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
    }
    int l = 0;
    for (int i = 0; i < 101; ++i)
    {
        while (l < n)
        {
            if (freq[i] == 0)
                break;
            arr[l++] = i;
            freq[i]--;
        }
    }
    // printf("%d", solve(arr, n));
    while (q--)
    {
        int r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", solve(arr, n, l, r, k));
    }
    return 0;
}