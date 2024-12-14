#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 500

int stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int value) {
    if (isFull()) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (isEmpty()) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}

int max(int a, int b)
{
    return a>b?a:b;
}

int getPerimeter(int histogram[], int n);
int getPerimeterBetter(int histogram[], int n);
int* getHistogram(int histogram[], char* currRow, int n);
int solve(char matrix[][MAX_SIZE], int m, int n);

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    char matrix[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < m; i++)
    {
        scanf("%s", matrix[i]);
    }

    printf("%d", solve(matrix, m, n));
}

int getPerimeter(int histogram[], int n)
{
    int perimeter = 0;
    int h, w;

    for (int i = 0; i < n; i++)
    {
        h = histogram[i];
        w = 1;

        for (int j = i + 1; j < n; j++)
        {
            if (histogram[j] < h)
            {
                break;
            }
            w++;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            if (histogram[j] < h)
            {
                break;
            }
            w++;
        }

        if (h != 0)
        {
            perimeter = perimeter > (2 * (h + w)) ? perimeter : (2 * (h + w));
        }
    }
    return perimeter;
}

int getPerimeterBetter(int histogram[], int n)
{
    int maxPerimeter = 0;
    int width, i = 0;
 
    while (i < n) {
           
        if (isEmpty() || histogram[peek()] <= histogram[i])
            push(i++);
           
        else {
            int height = histogram[peek()]; 
            pop();
            int width = (isEmpty()==1)?i:i-peek()-1;

            if(height*width!=0)
            {
                maxPerimeter = max(maxPerimeter, 2*(height+width));
            }
        }
    }
  
    while (isEmpty() != 1) {
            int height = histogram[peek()]; 
            pop();
            int width = (isEmpty()==1)?i:i-peek()-1;

            if(height*width!=0)
            {
                maxPerimeter = max(maxPerimeter, 2*(height+width));
            }
    }
    return maxPerimeter;
}

int* getHistogram(int histogram[], char* currRow, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (currRow[i] == '.')
        {
            histogram[i]++;
        }
        else if (currRow[i] == 'X')
        {
            histogram[i] = 0;
        }
    }
    return histogram;
}

int solve(char matrix[][MAX_SIZE], int m, int n)
{
    int histogram[MAX_SIZE] = { 0 };
    int maxFriends = 0;

    for (int i = 0; i < m; i++)
    {
        char* currRow = matrix[i];
        getHistogram(histogram, currRow, n);
        maxFriends = max(maxFriends, getPerimeter(histogram, n));
    }
    return maxFriends - 1;
}