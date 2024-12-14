#include <stdio.h>
const int maxN = 1e5;
typedef struct point
{
    int x, y, t;
} point;

int head = 0;
int tail = 0;
void push(point p, point queue[])
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
point pop(point queue[])
{
    if (head == tail)
    {
        printf("Queue is empty\n");
        point temp = {-1, -1, -1};
        return temp;
    }
    point p = queue[head];
    head++;
    head %= maxN;
    return p;
}
int main()
{
    point queue[maxN];

    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 1)
            {
                point p = {i, j, 0};
                push(p, queue);
            }
        }
    }
    int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    int ans = 0;
    while (head != tail)
    {
        point p = pop(queue);
        if (p.t > ans)
            ans = p.t;
        for (int i = 0; i < 8; i++)
        {
            int x = p.x + dx[i];
            int y = p.y + dy[i];

            if (x < 0 || y < 0 || x >= m || y >= n || matrix[x][y] > 0)
                continue;
            matrix[x][y] = p.t + 1;
            point next = {x, y, p.t + 1};
            push(next, queue);
        }
    }
    printf("%d\n", ans);
}