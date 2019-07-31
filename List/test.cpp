#include "list.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    List L;
    L = MakeEmpty(L);

    if (!IsEmpty(L))
    {
        cerr << "List no Empty" << endl;
        return 1;
    }

    Position P;
    Insert(1, L, L);
    P = Find(1, L);
    Insert(2, L, P);
    P = Find(2, L);
    Insert(3, L, P);
    P = Find(3, L);
    Insert(4, L, P);
    P = Find(4, L);
    Insert(5, L, P);
    P = Find(5, L);
    if (IsLast(P, L))
        cout << " 5 Is Last Node" << endl;
    cout << endl;
    cout << endl;


    Insert(6, L, P);

    PrintList(L);

    cout << endl;
    cout << endl;

    Delete(1, L);
    Delete(3, L);
    Delete(6, L);
    PrintList(L);

    cout << endl;
    cout << endl;

    DeleteList(L);

    if (!IsEmpty(L))
    {
        cerr << "List no Empty" << endl;
        return 1;
    }
 
    return 0;
}
