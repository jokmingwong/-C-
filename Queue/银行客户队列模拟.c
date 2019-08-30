#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef struct
{
    int time;
    int item;
} member;

typedef struct temp
{
    member m[MAXSIZE];
    int count;
    int front;
    int rear;
} * queue;

void initialize(queue T)
{
    T->count = 0;
    T->front = T->rear = 0;
}

int isFull(queue T)
{
    return T->count == MAXSIZE;
}

int isEmpty(queue T)
{
    return T->count == 0;
}

void enqueue(queue q, int x)
{
    if (isFull(q))
        return; //q满，终止程序
    q->count++;
    q->m[q->rear].item = x;
    q->m[q->rear].time = 0;
    q->rear = (q->rear + 1) % MAXSIZE; //循环队列设计，防止内存浪费,rear不存储数据
}

void deque(queue T)
{
    if (isEmpty(T))
        return;
    T->count--;
    T->front = (T->front + 1) % MAXSIZE;
}

int judgeOpenWindows(int win_num, int amount)
{
    return amount / win_num >= 7;
}

int main()
{
    queue tasks = malloc(sizeof(struct temp));
    initialize(tasks);
    //READ AND CALCULATE THE TOTAL AMOUNT
    int times, sum = 0;
    scanf("%d", &times);
    int Q[times];
    int i;
    for (i = 0; i < times; i++)
    {
        scanf("%d", Q + i);
        sum += Q[i];
    }
    //MODULE
    //index means the index_st person
    int index = 1;
    int windows_num = 3;
    int times_enqueue = 0;
    int times_deque = 0;
    while (times_deque < sum)
    {
        int j;
        //enqueue
        if (times_enqueue < times)
        {
            for (j = 0; j < Q[times_enqueue]; j++)
            {
                enqueue(tasks, index);
                index++;
            }
            times_enqueue++;
            //Only the reflection of client make the company change the solution
            while (!isEmpty(tasks) && judgeOpenWindows(windows_num, tasks->count) && windows_num != 5)
            {
                windows_num++;
            }
        }

        //Deque
        for (j = 0; !isEmpty(tasks) && j < windows_num; j++)
        {
            printf("%d : %d\n", tasks->m[tasks->front].item, tasks->m[tasks->front].time);
            deque(tasks);
            times_deque++;
        }
        while (!judgeOpenWindows(windows_num, tasks->count) && windows_num > 3)
        {
            windows_num -= 1;
        }

        //Add time
        for (j = tasks->front; j != tasks->rear;)
        {
            tasks->m[j].time += 1;
            j = (j + 1) % MAXSIZE;
        }
    }
    return 0;
}