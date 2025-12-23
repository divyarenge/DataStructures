#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first, PPNODE last , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first  = newn;
        *last = newn;
    }
    else
    {
        newn -> next = *first;
        (*first) -> prev = newn;
        *first = newn;
    }

    (*last) -> next = *first;
    (*first) -> next = *last;
}

void Insertlast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn -> data = no;
    newn -> next = NULL;
    newn -> prev = NULL;

    if(*first == NULL && *last == NULL)
    {
        *first  = newn;
        *last = newn;
    }
    else
    {
        (*last) -> next = newn;
        newn -> prev = *last;
        *last = newn;
    }

    (*last) -> next = *first;
    (*first) -> next = *last;
}

void DeleteFirst(PPNODE first, PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first = *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *first = (*first) -> next;
        free((*first) -> next); 

        (*last) -> next = *first;
        (*first) -> next = *last;
    }


}

void DeleteLast(PPNODE first, PPNODE last)
{
    if(*first == NULL && *last == NULL)
    {
        return;
    }
    else if(*first = *last)
    {
        free(*first);
        *first = NULL;
        *last = NULL;
    }
    else
    {
        *last = (*last) -> next;
        free((*last) -> next); 

        (*first) -> next = *last;
        (*last) -> next = *first;
        
    }    
}

void Display(PNODE first, PNODE last)
{
    //IMPORTANT
    if(first == NULL && last == NULL)//LL is empty
    {
        printf("LinkedList is Empty\n");
        return;
    }

    printf(" <=> ");
    
    do
    {
        printf("| %d | <=> ",first -> data);
        first = first -> next;
    } while (first != last -> next);

    printf("\n");
}

int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    if(first == NULL && last == NULL)   //LL is empty
    {
        return 0;
    }

    do
    {
        iCount++;
        first = first -> next;
    } while (first != last -> next);

    return iCount;
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    int iCount, i = 0;
    PNODE temp = 0;
    PNODE newn = NULL;
    
    iCount = Count(*first,*last);

    if(pos< 1 || pos > iCount+1)
    {
        printf("Invalid Position");
        return;
    }

    if(pos == 1)
    {
        InsertFirst(first, last , no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(first, last, no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn -> data = no;
        newn -> next = NULL;
        newn -> prev = NULL;
        temp = *first;

        for(i =1; i< pos-1; i++)
        {
            temp = temp-> next;
        }

        newn -> next = temp -> next;
        newn -> next -> prev = newn;

        temp -> next = newn;
        newn -> next = temp;
    }
}

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    int iCount, i = 0;
    PNODE temp = 0;
    
    iCount = Count(*first,*last);

    if(pos< 1 || pos > iCount)
    {
        printf("Invalid Position");
        return;
    }

    if(pos == 1)
    {
        DeleteFirst(first, last);
    }
    else if(pos == iCount)
    {
        DeleteLast(first, last);
    }
    else
    {
        temp = *first;

        for(i =1; i< pos-1; i++)
        {
            temp = temp-> next;
        }

        temp -> next = temp -> next -> next;
        free(temp -> next -> prev);
        temp -> next -> prev = temp;
    }    
}

int main()
{
    int iRet = 0;

    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);

    Insertlast(&head,&tail,101);
    Insertlast(&head,&tail,111);
    Insertlast(&head,&tail,121);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);

    DeleteFirst(&head, &tail);
    DeleteLast(&head, &tail);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);

    InsertAtPos(&head,&tail,105,3);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);

    DeleteAtPos(&head,&tail,3);

    Display(head,tail);
    iRet = Count(head,tail);
    printf("Number of Nodes : %d\n",iRet);
    
    return 0;
}