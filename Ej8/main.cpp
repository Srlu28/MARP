#include "MedianHeap.h"
#include <iostream>
using namespace std;

bool r()
{
    int n,aux;
    cin>>n;
    while(cin)
    {
        MedianHeap mH;
        for(int i=0;i<n;i++)
        {
            cin>>aux;
            if(aux==0)
            {
                try{
                    long int a= mH.pop();
                    cout<<a<<" ";
                }
                catch(domain_error & e)
                {
                    cout<<"ECSA ";
                }
                
            }
            else
            {
                mH.push(aux);
            }
        }
        cout<<endl;
        return true;
    }
    return false;
}

int main()
{
    while(r());
    return 0;
}