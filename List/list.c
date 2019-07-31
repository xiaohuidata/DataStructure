#include "list.h"

struct Node
{
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L)
{
    L =(Node *) malloc(sizeof(struct Node));
    if (L == NULL)
        exit(0);
    L->Next = NULL;
    return L;
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P, List L)
{
    return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
    Position P;

    P = L->Next;
    while (P != NULL && P->Element != X)
        P = P->Next;

    return P;
}

void Delete(ElementType X, List L)
{
    Position P, TmpCell;

    P = FindPrevious(X, L);
    if (!IsLast(P, L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

Position FindPrevious(ElementType X, List L)
{
    Position P;
    P = L;
    while (P->Next != NULL && P->Next->Element != X)
        P = P->Next;
    return P;
}

void Insert(ElementType X, List L, Position P)
{
    Position TmpCell;
    TmpCell = (Node*)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        exit(0);

    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L)
{
    Position P, Tmp;

    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

Position Header(List L)
{
    return L;
}

Position First (List L)
{
    return L->Next;
}

Position Advance(Position P)
{
    return P;
}

ElementType Retrieve(Position P)
{
    return P->Element;
}

void PrintList(List L)
{
    Position P;
    P = L->Next;
    while (P != NULL)
    {
        printf("%d\n", P->Element);
        P = P->Next;
    }
}
