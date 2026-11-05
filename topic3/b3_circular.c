#include <stdio.h>
int data[6], front = 0, rear = 0, cap = 6;
void enq(int x)
{
    data[rear] = x;
    rear = (rear + 1) % cap;
}
int deq(void)
{
    int x = data[front];
    front = (front + 1) % cap;
    return x;
}
void show(void)
{
    printf("data:");
    for (int i = 0; i < 6; i++)
        printf(" %d", data[i]);
    printf("  front=%d rear=%d  queue:", front, rear);
    for (int i = front; i != rear; i = (i + 1) % cap)
        printf(" %d", data[i]);
    printf("\n");
}
int main(void)
{
    enq(4);
    enq(1);
    enq(5);
    enq(2);
    enq(6);
    deq();
    deq();
    show();
    enq(8);
    show();
    enq(3);
    show();
    return 0;
}
