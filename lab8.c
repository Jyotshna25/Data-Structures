#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int ssn;
    char name[20], dept[20], desg[20], ph[20];
    float sal;
} EMPL;
struct node
{
    int ssn;
    char name[20], dept[20], desg[20], ph[20];
    float sal;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("Out of memory\n");
        exit(0);
    }
    return x;
}
NODE insert_front(EMPL item, NODE first)
{
    NODE temp;
    temp = getnode();
    temp->ssn = item.ssn;
    strcpy(temp->name, item.name);
    strcpy(temp->dept, item.dept);
    strcpy(temp->desg, item.desg);
    temp->sal = item.sal;
    strcpy(temp->ph, item.ph);
    temp->llink = temp->rlink = NULL;
    if (first == NULL)
        return temp;
    temp->rlink = first;
    first->llink = temp;
    return temp;
}
NODE insert_rear(EMPL item, NODE first)
{
    NODE temp, cur;
    temp = getnode();
    temp->ssn = item.ssn;
    strcpy(temp->name, item.name);
    strcpy(temp->dept, item.dept);
    strcpy(temp->desg, item.desg);
    temp->sal = item.sal;
    strcpy(temp->ph, item.ph);
    temp->llink = temp->rlink = NULL;
    if (first == NULL)
        return temp;
    cur = first;
    while (cur->rlink != NULL)
    {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}
NODE delete_front(NODE first)
{
    NODE second;
    if (first == NULL)
    {
        printf("Employee list is empty\n");
        return NULL;
    }
    if (first->rlink == NULL)
    {
        printf("Employee details deleted: ssn=%d\n", first->ssn);
        free(first);
        return NULL;
    }
    second = first->rlink;
    second->llink = NULL;
    printf("Employee details: ssn=%d\n", first->ssn);
    free(first);
    return second;
}
NODE delete_rear(NODE first)
{
    NODE cur, prev;
    if (first == NULL)
    {
        printf("List is empty cannot delete\n");
        return first;
    }
    if (first->rlink == NULL)
    {
        printf("Employee details deleted: ssn=%d\n", first->ssn);
        free(first);
        return NULL;
    }
    prev = NULL;
    cur = first;
    while (cur->rlink != NULL)
    {
        prev = cur;
        cur = cur->rlink;
    }
    printf("Employee details deleted: ssn=%d\n", cur->ssn);
    free(cur);
    prev->rlink = NULL;
    return first;
}
void display(NODE first)
{
    NODE cur;
    int count = 0;
    if (first == NULL)
    {
        printf("Employee list is empty\n");
        return;
    }
    cur = first;
    while (cur != NULL)
    {
 printf("SSN-%d\nSALARY-%f\nNAME-%s\nDEPARTMENT-%s\nDESIGNATION-%s\nPHONE-%s\n", cur->ssn, cur->sal, cur->name, cur->dept, cur->desg, cur->ph);
 cur = cur->rlink;
 count++;
    }
    printf("Number of employees=%d\n", count);
}
int main()
{
    NODE first;
    int choice;
    EMPL item;
    first = NULL;
    for (;;)
    {

printf("\n1.Insert_front\t2.Insert_rear\n3.Delete_front\t4.Delete_rear\n5.Display\t6.Exit\n");
printf("Enter your choice:\n");
 scanf("%d", &choice);
 switch (choice)
 {
        case 1:
            printf("SSN:");
            scanf("%d", &item.ssn);
            printf("NAME:");
            scanf("%s", &item.name);
            printf("DEPARTMENT:");
            scanf("%s", &item.dept);
            printf("SALARY:");
            scanf("%f", &item.sal);
            printf("DESIGNATION:");
            scanf("%s", &item.desg);
            printf("PHONE:");
            scanf("%s", &item.ph);
            first = insert_front(item, first);
            break;
        case 2:
            printf("SSN:");
            scanf("%d", &item.ssn);
            printf("NAME:");
            scanf("%s", &item.name);
            printf("DEPARTMENT:");
            scanf("%s", &item.dept);
            printf("SALARY:");
            scanf("%f", &item.sal);
            printf("DESIGNATION:");
            scanf("%s", &item.desg);
            printf("PHONE:");
            scanf("%s", &item.ph);
            first = insert_rear(item, first);
            break;
        case 3:
            first = delete_front(first);
            break;
        case 4:
            first = delete_rear(first);
            break;
        case 5:
            display(first);
            break;
        case 6:
            exit(0);
            break;
 }
    }
    return 0;
}