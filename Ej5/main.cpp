#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>

struct Paciente
{
    long int gravedad;
    string name;
    //char tipEv;
    long int orden_ll;

    bool operator<(const Paciente & p) const
    {
        if(gravedad == p.gravedad)return orden_ll>p.orden_ll;
        return gravedad<p.gravedad;
    }

    bool operator>(const Paciente & p) const
    {
        if(gravedad == p.gravedad)return orden_ll<p.orden_ll;
        return gravedad>p.gravedad;
    }
};

bool r()
{
    int n;cin>>n;
    if(n)
    {
        priority_queue<Paciente> pq;
        for(int i=0;i<n;i++)
        {
            char t;
            cin>>t;
            if(t=='I')
            {
                string name;long int grav;
                cin>>name>>grav;
                Paciente p;
                p.gravedad=grav;
                p.name=name;
                p.orden_ll=i;
                pq.push(p);
            }
            else
            {
                cout<<pq.top().name<<endl;
                pq.pop();
            }
        }
        cout<<"---"<<endl;
        return true;
    }
    return false;
}

int main()
{
    while(r());
    return 0;
}