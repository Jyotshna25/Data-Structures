#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day
{
    char *name;
    int date;
    char *activity;
};
struct Day *calendar[7];
void create()
{
    int i;
    for (i = 0; i < 7; i++)
    {
        calendar[i] = (struct Day *)malloc(sizeof(struct Day));
        calendar[i]->name = (char *)malloc(20 * sizeof(char));
        calendar[i]->activity = (char *)malloc(100 * sizeof(char));
    }
}
void read()
{
    int i;
    for (i = 0; i < 7; i++)
    {
        printf("Enter day name:");
        scanf("%s", calendar[i]->name);
        printf("Enter Date:");
        scanf("%d", &calendar[i]->date);
        printf("Enter activity:");
        scanf("%s", calendar[i]->activity);
        printf("\n");
    }
}
void display()
{
    int i;
    printf("Weekly activity details:\n");
    for (i = 0; i < 7; i++)
    {
        printf("Day%d:%s--%d,\tActivity:%s\n", i + 1, calendar[i] -> name, calendar[i]->date, calendar[i]->activity);
    }
}
int main()
{
    int i;
    printf("Creating calendar:\n");
    create();
    printf("Reading calendar:\n");
    read();
    printf("Displaying calendar:\n");
    display();
    for (i = 0; i < 7; i++)
    {
        free(calendar[i]->name);
        free(calendar[i]->activity);
        free(calendar[i]);
    }
    return 0;
}
