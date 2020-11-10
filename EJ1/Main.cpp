#include <iostream>
#include "bintree.h"
#include <algorithm>
#include <climits>
using namespace std;

typedef struct
{
    long int maxi, mini;
    bool ok;
}tRet1;
typedef struct
{
    bool eq;
    int al;
}tRet2;

tRet2 Completo(bintree<int> arbol)
{
    if (arbol.empty())return { true,0 };
    tRet2 retiz = Completo(arbol.left());
    tRet2 retder = Completo(arbol.right());
    if (abs(retiz.al - retder.al) <= 1 && retiz.eq && retder.eq)
        return { true,max(retiz.al,retder.al) + 1 };
    else return{ false,0 };
}
tRet1 Busqueda(bintree<int> arbol)
{
    tRet1 ret1 = { arbol.root(),arbol.root() ,true };
    if (!arbol.left().empty())
    {
        tRet1 left = Busqueda(arbol.left());
        ret1.ok = left.ok && left.maxi < arbol.root();
        ret1.mini = left.mini;
    }
    if (!arbol.right().empty())
    {
        tRet1 right = Busqueda(arbol.right());
        ret1.ok &= right.ok && right.mini > arbol.root();
        ret1.maxi = right.maxi;
    }
    return ret1;
}

bool ej1(bintree<int> arbol)
{
    if (arbol.empty())return true;
    else
    {
        tRet1 r1 = Busqueda(arbol);
        tRet2 r2 = Completo(arbol);
        return r1.ok && r2.eq;
    }
}

void r()
{
    bintree<int> arbol = leerArbol(-1);
    bool r = ej1(arbol);
    if (r)cout << "SI\n";
    else cout << "NO\n";
}

int main()
{
    int numC;
    cin >> numC;
    for (int i = 0; i < numC; i++)
    {
        r();
    }
}