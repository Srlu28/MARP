#include <iostream>
#include "conjuntosdisjuntos.h"
#include <algorithm>
using namespace std;

void r()
{
    int numVer,numAri;
    cin>>numVer>>numAri;
    int caminoMasLar=0;
    ConjuntosDisjuntos ejer=ConjuntosDisjuntos(numVer);
    for(int i=0;i<numAri;i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        ejer.unir(v1,v2);
        
    }
    for(int i=1;i<=numVer;i++)caminoMasLar=max(caminoMasLar,ejer.cardinal(i));
    cout<<caminoMasLar<<endl;
}

int main()
{
    int num;
    cin>>num;
    for(int i=0;i<num;i++)
    {
        r();
    }
}