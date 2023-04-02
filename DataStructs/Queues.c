#include <stdio.h>
const int size = 10;
int head = 0, tail = 0;
void Enqueue(int queue[], int ele);
int Dequeue(int queue[]);
int Front(int queue[]);
int QLength();
void printQ(int queue[]);

int isEmpty=1;
int isFull=0;
int FLAG= -1530494976;

int main(){
    int Q[size];

    Enqueue(Q,8);
    Enqueue(Q,3);
    Dequeue(Q);
    Enqueue(Q,2);
    Enqueue(Q,5);
    Dequeue(Q);
    Dequeue(Q);
    Enqueue(Q,9);
    Enqueue(Q,1);

    // printf("%d %d\n",head,tail);
    
    printQ(Q);
    return 0;
}

void Enqueue(int queue[], int ele){
    if(head == (tail+1)%size && isFull){
        printf("\nerror: overflow\n");
    }
    queue[tail] = ele;
    isEmpty=0;
    if(tail == size){
        tail = 0;
    }
    else{
        tail += 1;
    }
    if(head==tail){
        isFull=1;
    }
}

int Dequeue(int queue[]){
    if(head==tail && isEmpty==1){
        printf("\nerror: underflow\n");
        return FLAG;
    }
    else{
        int tmp = queue[head];
        head = (head+1)%size;
        if (head==tail){
            isEmpty=1;
        }
        return tmp;
    }
}

int QLength(){
    if (head<tail){
        return tail-head;
    }
    else if(head>tail){
        return size - head + tail;
    }
    else if (head==tail && isEmpty){
        return 0;
    }
    else if (head==tail && isFull){
        return size;
    }
    else{
        return FLAG;
    }
}

int Front(int queue[]){
    if(isEmpty){
        printf("queue is empty, ");
        return FLAG;
    }
    return queue[head];
}

void printQ(int queue[]){
    if(isEmpty){
        printf("Queue is empty");
    }
    else if(isEmpty==0 && head<tail){
        for (int i = head; i < tail; i++){
            printf("%d ",queue[i]);
        }
    }
    else if(isEmpty==0 && head>=tail){
        for (int i = head; i < size; i++){
            printf("%d ",queue[i]);
        }
        for (int i = 0; i < tail; i++){
            printf("%d ",queue[i]);
        }
    }
}