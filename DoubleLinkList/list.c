#include "list.h"

struct Node
{
    ElementType Element;
    Position Next;
    Position Previous;
};

List MakeEmpty(List L)
{
    L =(Node *) malloc(sizeof(struct Node));
    if (L == NULL)
        exit(0);
    L->Next = NULL;
    L->Previous = NULL;
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
    Position P;

    P = Find(X, L);
    if (!IsLast(P, L))
    {
        P->Next->Previous = P->Previous;
        P->Previous->Next = P->Next;
        free(P);
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
    TmpCell->Previous = P;
    P->Next = TmpCell;
    TmpCell->Next->Previous = TmpCell;
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
