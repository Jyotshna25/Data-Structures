#include <stdio.h>
#include <stdlib.h>
int a[20][20], q[20], visited[20], reach[20], n, i, j, f = 0, r = -1;
int count = 0;
void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (a[v][i] && !visited[i])
            q[++r] = i;
    if (f <= r)
    {
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}
void dfs(int v)
{
    int i;
    reach[v] = 1;
    for (i = 1; i <= n; i++)
    {
        if (a[v][i] && !reach[i])
        {
            printf("\n%d->%d", v, i);
            count++;
            dfs(i);
        }
    }
}
int main()
{
    int v, choice;
    printf("\nEnter the number of vertices:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }
    for (i = 1; i <= n - 1; i++)
        reach[i] = 0;
    printf("Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    printf("\n1.BFS\t2.DFS\t3.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        printf("\nEnter the starting vertex:\n");
        scanf("%d", &v);
        bfs(v);
        if (v < 1 || v > n)
        {
            printf("\nBFS not possible\n");
        }
        else
        {
            printf("\nThe nodes which are reachable from %d:", v);
            for (i = 1; i <= n; i++)
                if (visited[i])
                    printf("%d\t", i);
        }
        break;
    case 2:
        printf("\nEnter the starting vertex:\n");
        scanf("%d", &v);
        dfs(v);
        if (count == n - 1)
            printf("\nGraph is connected: ");
        else
            printf("\nGraph is not connected:");
        break;
    case 3:
        exit(0);
    default:
        printf("\nInvalid choice\n");
    }
    return 0;
}