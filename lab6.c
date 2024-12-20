#include <stdio.h>
#include <stdlib.h>
#define QUE_SIZE 5
char item;
int count, q[QUE_SIZE], front, rear;
void insertQ()
{
    if (count == QUE_SIZE)
    {
        printf("Queue Overflow\n");
        return;
    }
    rear = (rear + 1) % QUE_SIZE;
    q[rear] = item;
    count++;
}
char deleteQ()
{
    if (count == 0)
        return -1;
    int item = q[front];
    front = (front + 1) % QUE_SIZE;
    count--;
    return item;
}
void display()
{
    if (count == 0)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Contents of the queue are:\n");
    int i, f;
    for (i = 0, f = front; i < count; i++)
    {
        printf("%c\n", q[f]);
        f = (f + 1) % QUE_SIZE;
    }
}
int main()
{
    int choice;
    front = 0;
    rear = -1;
    for (;;)
    {
        printf("1.Insert\t 2.Delete\n");
        printf("3.Display\t 4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf(" %c", &item);
            insertQ();
            break;
        case 2:
            item = deleteQ();
            if (item == -1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Item deleted from queue is %c\n", item);
            }
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
