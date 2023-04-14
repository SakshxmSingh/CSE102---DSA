#include <stdio.h>
#include <stdlib.h>

int findMin(int arr[], int start, int end) {
    int minVal = arr[start];
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

int calculateArea(int *grid[], int i, int j, int k, int m) {
    int slen = k - j + 1;
    if (slen >= 0) {
        int minVal = findMin(grid[i], j, k);
        int area = 2 * (minVal + slen);
        return area;
    }
    return 0;
}

int findMaxRectangle(int *grid[], int m, int n) {
    int prod = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int k = j;
            int tempMin = grid[i][j];
            while (k < n && grid[i][k] != 0) {
                int area = calculateArea(grid, i, j, k, m);

                if (area > prod) {
                    prod = area;
                }
                k++;
            }
        }
    }
    return prod - 1;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int **grid = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        grid[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = m - 1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            char c;
            scanf(" %c", &c);
            if (c == 'X') {
                grid[i][j] = 0;
            } else if (c == '.') {
                grid[i][j] = 1;
                if (i < m - 1) {
                    grid[i][j] += grid[i + 1][j];
                }
            }
        }
    }

    int maxRectangle = findMaxRectangle(grid, m, n);

    printf("%d\n", maxRectangle);

    for (int i = 0; i < m; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
