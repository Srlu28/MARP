#include <iostream>
#include <functional>
#include <algorithm>
#include <set>
using namespace std;

struct tEj{
    long int ini,fin;

    bool operator >(tEj const & el) const{
        return ini>=el.fin;
    }
    bool operator <(tEj const & el) const{
        return fin<=el.ini;
    }
    bool operator ==(tEj const & el){
        return (ini<=el.ini && fin>el.fin) || (ini<el.fin && fin>=el.fin)||(ini<=el.fin && fin>=el.fin);
    }
};

bool r()
{
    long int n,m,t;
    cin>>n>>m>>t;
    if(cin)
    {
        bool ok=true;
        set<tEj> el;
        for(int i=0;i<n;i++)
        {
            tEj aux;
            cin>>aux.ini>>aux.fin;
            if(aux.ini<t)
            {
                auto  a= el.insert(aux);
                ok &=a.second;
            }
            
        }
        for(int i=0;i<m;i++)
        {
            tEj aux;
            int per;
            cin>>aux.ini>>aux.fin>>per;
            while(ok && aux.ini<t)
            {
                auto  a= el.insert(aux);
                ok &=a.second;

                aux.ini += per;
 				aux.fin = aux.fin + per;

            }
        }
        if(ok)cout<<"NO\n";
        else cout<<"SI\n";
        return true;
    }
    return false;
}

int main()
{
    while(r());
    return 0;
}