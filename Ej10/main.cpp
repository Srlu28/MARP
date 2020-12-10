#include <iostream>
using namespace std;
#include "grafo.h"
#include <stack>
#include <unordered_set>
#include <fstream>

bool r()
{
    int numV;
    cin >> numV;
    if (cin)
    {
        Grafo graph = Grafo(numV);
        int numA;
        cin >> numA;
        for (int i = 0; i < numA; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            graph.ponArista(v1, v2);
        }
        int numVisit = 1;
        vector<bool> marked(graph.V());
        //unordered_set<int> marked;
        vector<int> edgeTo(graph.V(), -1);
        stack<int> adyacentes;

        marked[0]=true;
        adyacentes.push(0);

        bool esCiclico = false; //Tenemos que comprobar que es conexo y que no es cíclico
        while (!esCiclico && adyacentes.size())
        {
            int elem = adyacentes.top();
            adyacentes.pop();

            auto listaAdy = graph.ady(elem);
            for (int ady : listaAdy)
            {
                if (!marked[ady])
                {
                    marked[ady]=true;
                    numVisit++;
                    adyacentes.push(ady);
                    edgeTo[ady] = elem;
                }
                else if (edgeTo[elem] != ady)
                    esCiclico = true;
            }

        }
        if (!esCiclico && numVisit == marked.size())cout << "SI\n";
        else cout << "NO\n";

        return true;
    }
    return false;

}

int main()
{
    //ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (r());

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}