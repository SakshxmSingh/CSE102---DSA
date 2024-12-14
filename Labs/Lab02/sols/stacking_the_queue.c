#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node
{
    int val;
    struct queue_node *next;
} queue;

typedef struct stack_node
{
    queue *q;
    struct stack_node *next;
} stack;

stack *Push(stack *st, int k)
{
    if (st == NULL)
    {
        st = (stack *)malloc(sizeof(stack));
        st->next = NULL;
    }
    else
    {
        stack *node = (stack *)malloc(sizeof(stack));
        node->next = st;
        st = node;
    }
    st->q = (queue *)malloc(sizeof(queue));
    st->q->next = NULL;
    st->q->val = k;
    return st;
}

stack *Pop(stack *st)
{
    if (st != NULL)
    {
        st = st->next;
    }
    return st;
}

stack *Enqueue(stack *st, int k)
{
    if (st == NULL)
    {
        return Push(st, k);
    }
    queue *temp = st->q;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = (queue *)malloc(sizeof(queue));
    temp->next->next = NULL;
    temp->next->val = k;
    return st;
}

stack *Dequeue(stack *st)
{
    if (st == NULL)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n", st->q->val);
        st->q = st->q->next;
        if (st->q == NULL)
        {
            st = Pop(st);
            if (st == NULL)
            {
                printf("-1\n");
            }
        }
    }
    return st;
}

stack *MaxSumPairs(stack *st, int k)
{
    int count = 0;
    if (st == NULL || st->q == NULL)
    {
        printf("%d\n", count);
        return st;
    }
    int prev = st->q->val;
    queue *temp = st->q;
    int ans = 0;
    while (temp != NULL && temp->next != NULL)
    {
        if (temp->next->val + prev >= k)
        {
            count++;
        }
        else
        {
            ans = (count > ans ? count : ans);
            count = 0;
        }
        prev = temp->next->val;
        temp = temp->next;
    }
    ans = (count > ans ? count : ans);
    printf("%d\n", ans);
    return Pop(st);
}

int main()
{
    int q;
    scanf("%d", &q);

    stack *st = NULL;

    while (q--)
    {
        char str[20];
        scanf("%s", str);

        // for Push and Pop operation
        if (str[0] == 'P')
        {

            // Push
            if (str[1] == 'u')
            {
                int k;
                scanf("%d", &k);
                st = Push(st, k);
            }
            // Pop
            else
            {
                st = Pop(st);
            }
        }
        // Enqueue
        else if (str[0] == 'E')
        {
            int k;
            scanf("%d", &k);
            st = Enqueue(st, k);
        }
        // Dequeue
        else if (str[0] == 'D')
        {
            st = Dequeue(st);
        }
        // MAXSUMPAIRS
        else
        {
            int k;
            scanf("%d", &k);
            st = MaxSumPairs(st, k);
        }
    }
    return 0;
}