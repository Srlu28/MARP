#include <iostream>
using namespace std;
#include <algorithm>
#include <functional>
#include <queue>

struct tCl
{
    long int caja,tiempo;

    bool operator > (tCl const & cl)const{
        return tiempo> cl.tiempo || (tiempo==cl.tiempo && caja>cl.caja);
    }
};

bool r()
{
    long int numCajas,numCl;
    cin>>numCajas>>numCl;
    priority_queue<tCl,vector<tCl>,greater<tCl>> pq;
    if(numCajas==0 && numCl==0)return false;
    else
    {
        tCl aux;
        long int time=0;
        long int cli;
        for(int i=0;i<numCajas;i++)pq.push({i+1,0});
        for(int i=0;i<numCl;i++)
        {
            cin>>cli;
            aux=pq.top();
            pq.pop();
            aux.tiempo+=cli;
            pq.push(aux);
        }
        cout<<pq.top().caja<<endl;
        return true;
    }
    
}

int main()
{
    while(r());
    return 0;
}