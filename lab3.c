#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int s[MAX], item, top = -1;
void push()
{
    if (top == MAX - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    top++;
    s[top] = item;
}
int pop()
{
    if (top == -1)
        return -1;
    return s[top--];
}
void display()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Contents of the stack:\n");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", s[i]);
    }
}
void palindrome()
{
    int i, j;
    for (i = 0, j = top; i <= j; i++, j--)
    {
        if (s[i] != s[j])
        {
            printf("Not palindrome\n");
            return;
        }
    }
    printf("Palindrome\n");
}
int main()
{
    int ch;
    while (1)
    {
        printf("MENU\n");
        printf("1.Push\t2.Pop\t3.Check palindrome\t4.Display\t5.Exit\n");
        printf("--------------------\n");
        printf("Enter your choice:\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the item:");
            scanf("%d", &item);
            push();
            break;
        case 2:
            printf("Popped value=%d\n", pop());
            break;
        case 3:
            palindrome();
            break;
        case 4:
            display();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
