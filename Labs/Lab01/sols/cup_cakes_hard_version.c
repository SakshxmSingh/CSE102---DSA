// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pre[50001][101];
int check(int arr[], int n, int i, int mid, int un)
{
    if (mid < i)
        return 0;
    for (int k = 0; k < 101; ++k)
    {
        if (pre[mid][k] - pre[i][k] + (arr[i] == k) > 0)
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
    for (int m = 0; m < 101; ++m)
    {
        if (arr[0] == m)
            pre[0][m] = 1;
        else
            pre[0][m] = 0;
    }
    for (int i = 1; i < n; ++i)
    {
        for (int m = 0; m < 101; ++m)
        {
            if (arr[i] == m)
                pre[i][m] = 1 + pre[i - 1][m];
            else
                pre[i][m] = pre[i - 1][m];
        }
    }
    while (q--)
    {
        int r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", solve(arr, n, l, r, k));
    }
    return 0;
}