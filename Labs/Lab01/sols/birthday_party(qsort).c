#include <stdio.h>
#include <stdlib.h>
typedef struct deadline
{
    int data;
    int index;
} deadline;

void swap(int *a, int *b)
{
    int t = *b;
    *b = *a;
    *a = t;
}
int compare(const void *a, const void *b)
{
    deadline x = *(const deadline *)a;
    deadline y = *(const deadline *)b;
    int xx = x.data;
    int yy = y.data;

    if (xx < yy)
        return -1;
    if (xx > yy)
        return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    deadline D[n];
    for (int i = 0; i < n; i++)
    {
        D[i].data = arr[i];
        D[i].index = i;
    }

    qsort(D, n, sizeof(deadline), compare);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d %d\n", D[i].data, D[i].index);
    // }

    int min_swaps = 0;
    int i = 0;
    while (i < n)
    {
        // elements at its right position
        if (D[i].index == i)
        {
            ++i;
            continue;
        }
        else
        {
            // swap the value
            swap(&D[i].data, &D[D[i].index].data);

            // update the index
            swap(&D[i].index, &D[D[i].index].index);
            if (D[i].index != i)
                i--;
        }
        min_swaps++;
        ++i;
    }
    printf("%d \n", min_swaps);
}
