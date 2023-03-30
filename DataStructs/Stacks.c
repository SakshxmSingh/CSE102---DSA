#include <stdio.h>

int topS = -1;
int size;
int FLAG= -1530494976;


int isEmpty(int s);
int isFull(int s);
void Push(int stuck[], int ele);
int Pop(int stuck[]);

int main()
    {
    size = 10;
    int stck[size];

    // Push(stck, 25);
    // Push(stck, 39);
    // Push(stck, 69);
    Push(stck, 25);
    Push(stck, 39);
    Push(stck, 69);
    Push(stck, 25);

    Pop(stck);

    for(int i=0; i<=topS; i++){
        printf("%d  ",stck[i]);
    }

    // printf("%d",topS);

    return 0;
    }


int isEmpty(int s)
    {
        if (s ==-1)
        {
            return 1;
        }
        return 0;
    }

int isFull(int s)
    {
        {
        if (s == size-1)
        {
            return 1;
        }
        return 0;
        }
    }

void Push(int stuck[], int ele)
    {
        if (isFull(topS)){
            printf("\nerror: overflow\n");
        }
        else{
            topS+=1;
            stuck[topS] = ele;
        }
    }

int Pop(int stuck[])
    {
        if(isEmpty(topS)){
            printf("\nerror: Underflow\n");
            return FLAG;
        }
        else{
            topS = topS -1;
            return stuck[topS+1];
        }
    }