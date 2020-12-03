#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
//#include "header.h"
#include <queue>
using namespace std;

bool r()
{
    long int n;
    cin>>n;
    if(n>0){
        priority_queue<long int, std::vector<long int>, std::greater<long int> > pq;
        for(long int i=0;i<n;i++)
        {
            long int elem;
            cin>>elem;
            pq.push(elem);
        }
        //vector<int> result;
        long int suma_t=0;
        while(pq.size()>1)
        {
            //while(!pq.empty())
            //{
                long int elem1=pq.top();
                pq.pop();
                long int elem2=pq.top();
                pq.pop();
                long int res=elem1+elem2;
                //if(!pq.empty())
                pq.push(res);
                suma_t+=res;
            //}
        }
        cout<<suma_t<<endl;
        return true;
    }
    else return false;
}
 
// Min Heap C++ Implementation
int main()
{
    while(r());
    return 0;
}