#include<iostream>
#include <queue>
#include <algorithm>
using namespace std;
#include <cmath>

struct tEj{
    long int numT,numAtr,musAtr;

    bool operator >(tEj const & el)const {return musAtr>el.musAtr;}

    bool operator <(tEj const & el)const {return musAtr<el.musAtr;}
};


bool r()
{
    long int p,n;
    cin>>p>>n;
    if(cin)
    {
        priority_queue<tEj> pq;
        pair<int,int> par;
        for(int i=0;i<n;i++)
        {
            int aux;
            cin>>aux;
            pq.push({aux,1,aux});//1 atril
        }
        int restantes= p-n;
        for(int i=0;i<restantes;i++)
        {
            //Repartimos los atriles.
            tEj el=pq.top();
            pq.pop();
            tEj el1={el.numT,el.numAtr+1,(long int) ceil((((long double)el.numT)/(el.numAtr+1)))};
            pq.push(el1);
        }
        tEj el= pq.top();
        cout<<el.musAtr<<endl;
        return true;
    }
    return false;
}

int main()
{
    while(r());
    return 0;
}