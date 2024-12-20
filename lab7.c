#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int USN, SEM, PHNO;
    char NAME[20], BRANCH[10];
    struct node *link;
};
typedef struct node *NODE;
NODE first = NULL;
int count = 0;
int USN, SEM, phno;
char name[20], branch[10];
NODE insert_front()
{
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    printf("Enter student details:\n");
    printf("USN\t Name\tBranch\tSem\tPhno.\n");
    scanf("%d\t%s\t%s\t%d\t%d", &USN, name, branch, &SEM, &phno);
    temp->USN = USN;
    strcpy(temp->NAME, name);
    strcpy(temp->BRANCH, branch);
    temp->SEM = SEM;
    temp->PHNO = phno;
    temp->link = first;
    count++;
    return temp;
}
void create()
{
    int i, n;
    printf("Enter number of students:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        first = insert_front();
    }
}
NODE delete_front()
{
    NODE temp;
    if (first == NULL)
    {
        printf("List is empty cannot delete\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf("Student usn=%d,name=%s\n", temp->USN, temp->NAME);
    free(temp);
    count--;
    return first;
}
NODE insert_rear()
{
    NODE temp;
    NODE cur;
    temp = (NODE)malloc(sizeof(struct node));

    printf("Enter student details:\n");
    printf("USN\tName\tBranch\tSem\tPhno\n");
    scanf("%d %s %s %d %d", &USN, name, branch, &SEM, &phno);
    temp->USN = USN;
    strcpy(temp->NAME, name);
    strcpy(temp->BRANCH, branch);
    temp->SEM = SEM;
    temp->PHNO = phno;
    temp->link = NULL;
    if (first == NULL)
    {
        first = temp;
        count++;
        return first;
    }
    cur = first;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = temp;
    count++;
    return first;
}
NODE delete_rear()
{
    NODE temp, cur, prev;
    if (first == NULL)
    {
        printf("List is empty cannot delete\n");
        return first;
    }
    if (first->link == NULL)
    {
        printf("Student USN=%d;name=%s\n", first->USN, first->NAME);
        count--;
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->link != NULL)
    {
        prev = cur;
        cur = cur->link;
    }
    printf("Student USN=%d;name=%s\n", cur->USN, cur->NAME);
    free(cur);
    prev->link = NULL;
    count--;
    return first;
}
void display()
{
    NODE temp;
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("The contents of singly linked list:\n");
    temp = first;
    while (temp != NULL)
    {
        printf("%d\t%s\t%s\t%d\t%d\n", temp->USN, temp->NAME, temp -> BRANCH, temp->SEM, temp->PHNO);
        temp = temp->link;
    }
    printf("The number of nodes in singly linked list=%d\n", count);
}
int main()
{
    int choice;
    for (;;)
    {

printf("\n1.Create\t2.Display\n3.Insert_rear\t4.Delete_rear\n5.Demonstration of stack Insert_front,Delete_front\nEnter your choice:\n");
 scanf("%d", &choice);
 switch (choice)
 {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            first = insert_rear();
            break;
        case 4:
            first = delete_rear();
            break;
        case 5:
            printf("Push\n");
            first = insert_front();
            printf("Pop\n");
            first = delete_front();
            break;
        default:
            printf("INVALID CHOICE\n");
            exit(0);
 }
    }
    return 0;
}