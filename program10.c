#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data ;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

//CALL BY VALUE

void Display(PNODE first)
{}

int Count (PNODE first)
{
    return 0;
}

//CALL BY ADDRESS

void InsertFirst(PPNODE first, int no)
{}

void InsertLast(PPNODE first, int no)
{}

void InsertAtPos(PPNODE first, int no, int pos)
{}

int main()
{
    PNODE head = NULL;
    
    Display(head);
    Count(head);

    InsertFirst(&head,11);
    InsertLast(&head,11);
    InsertAtPos(&head,51,5);

    return 0;
}