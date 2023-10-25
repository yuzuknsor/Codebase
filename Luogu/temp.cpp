#include <stdio.h>
#include <malloc.h>
#define LEN sizeof(struct list)
struct list
{
    int num;
    struct list *next;
};
int n;
struct list *create(void)
{
    struct list *head;
    struct list *p1, *p2;
    n = 0;
    p1 = p2 = (struct list*)malloc(LEN); // (1) 分配一个结构体大小的内存空间，并将p1和p2指向该空间
    scanf("%d", &p1->num);
    head = NULL;
    while (p1->num != -1)
    {
        n++;
        if (n == 1)
            head = p1;
        else
            p2->next = p1; // (2) 将p2的next指向p1
        p2 = p1;
        p1 = (struct list *)malloc(LEN);
        scanf("%d", &p1->num);
    }
    p2->next = NULL;
    return head;
}
struct list *delnode(struct list *h, int x)
{
    struct list *head, *p, *q;
    head = (struct list *)malloc(LEN);
    head->next = h;
    p = head->next;
    q = head;
    while (p != NULL)
    {
        if (p->num == x)
        {
            q->next = p->next; // (3) 将q的next指向p的next
            free(p);
            p = q->next;
        }
        else
        {
            q = p;
            p = p->next;
        }
    }
    q = head;
    head = head->next;
    free(q); // (4) 释放head指向的内存空间
    return head;
}
void print(struct list *head)
{
    int tmp[20];
    int i, j;
    struct list *p;
    p = head;
    if (head != NULL)
    {
        i = 0;
        while (p != NULL)
        {
            tmp[i++] = p->num;
            p = p->next;
        }
        for (j = i - 1; j >= 0; j--)
            printf("%d ", tmp[j]);
    }
}
int main()
{
    struct list *head;
    int x;
    head = create(); // (5) 调用create函数，将返回值赋给head
    scanf("%d", &x);
    head = delnode(head, x);
    print(head);
    return 0;
}