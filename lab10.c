#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
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
        printf("out of memory\n");
        exit(0);
    }
    return x;
}
void preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d\n", root->info);
        preorder(root->llink);
        preorder(root->rlink);
    }
}
void postorder(NODE root)
{
    if (root != NULL)
    {
        postorder(root->llink);
        postorder(root->rlink);
        printf("%d\n", root->info);
    }
}
void inorder(NODE root)
{
    if (root != NULL)
    {
        inorder(root->llink);
        printf("%d\n", root->info);
        inorder(root->rlink);
    }
}
NODE insert(int item, NODE root)
{
    NODE temp, cur, prev;
    temp = getnode();
    temp->info = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    if (root == NULL)
        return temp;
    prev = NULL;
    cur = root;
    while (cur != NULL)
    {
        prev = cur;
        if (item < cur->info)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    if (item < prev->info)
        prev->llink = temp;
    else
        prev->rlink = temp;
    return root;
}
NODE search(int item, NODE root)
{
    if (root == NULL)
        return root;
    if (item == root->info)
        return root;
    if (item < root->info)
        return search(item, root->llink);
    return search(item, root->rlink);
}
void main()
{
    NODE root, cur;
    int choice, item;
    root = NULL;
    for (;;)
    {
        printf("1.Insert\t2.Preorder\t3.Postorder\t4.Inorder\t5.Search\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            root = insert(item, root);
            break;
        case 2:
            if (root == NULL)
            {
                printf("Tree is empty\n");
                break;
            }
            printf("The given tree in tree form\n");
            printf("Preorder traversal is\n");
            preorder(root);
            printf("\n");
            break;
        case 3:
            if (root == NULL)
            {
                printf("Tree is empty\n");
                break;
            }
            printf("The given tree in tree form\n");
            printf("Postorder traversal is\n");
            postorder(root);
            printf("\n");
            break;
        case 4:
            if (root == NULL)
            {
                printf("Tree is empty\n");
                break;
            }
            printf("The given tree in tree form\n");
            printf("Inorder traversal is\n");
            inorder(root);
            printf("\n");
            break;
        case 5:
            printf("Enter the item to be searched:\n");
            scanf("%d", &item);
            cur = search(item, root);
            if (cur == NULL)
                printf("Item not found\n");
            else
                printf("Item found\n");
            break;
        default:
            exit(0);
        }
    }
}
