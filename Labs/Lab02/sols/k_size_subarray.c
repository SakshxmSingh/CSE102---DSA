#include <stdio.h>
const int mod = 1e9 + 7;
const int maxN = 1e5;
int head = 0;
int tail = 0;
void push(int p, int queue[])
{
    if (head == (tail + 1) % maxN)
    {
        printf("Queue if full\n");
        return;
    }
    queue[tail] = p;
    tail++;
    tail %= maxN;
}
int pop(int queue[])
{
    if (head == tail)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int p = queue[head];
    head++;
    head %= maxN;
    return p;
}
int main()
{

    int queue[maxN];
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int left = 0, right = 0;
    while (right < k)
    {
        while ((tail - head) > 0 && arr[queue[tail - 1]] <= arr[right])
            tail--;
        push(right, queue);
        right++;
    }
    int turn = 0; //  if 0:  ishu 1: rohu
    long ishu = arr[queue[head]];
    turn ^= 1;
    long rohu = 0;
    while (right < n)
    {
        left++;
        while ((tail - head) > 0 && arr[queue[tail - 1]] <= arr[right])
            tail--;
        while ((tail - head) > 0 && queue[head] < left)
            head++;

        push(right, queue);
        if (turn == 0)
            ishu += arr[queue[head]];
        else
            rohu += arr[queue[head]];
        turn ^= 1;
        right++;
    }
    if (rohu == ishu)
    {
        printf("draw\n");
    }
    else if (rohu > ishu)
        printf("rohu\n");
    else
        printf("ishu\n");
}w