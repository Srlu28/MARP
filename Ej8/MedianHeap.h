#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <queue>
#include <climits>
using namespace std;

class MedianHeap{
    priority_queue<long int,vector<long int>,less<long int>> minim;
    priority_queue<long int,vector<long int>,greater<long int>> maxim;
    long int median=LONG_MAX;

public:
    void push(long int const a)
    {
        if(a<median)minim.push(a);
        else maxim.push(a);

        balance();

        if(minim.size()>=maxim.size())median=minim.top();
        else median=maxim.top();
    }

    long int pop()
    {
        long int ret;
        if(minim.empty() && maxim.empty())throw domain_error("");
        else if(minim.size()>=maxim.size()){
            ret=minim.top();
            minim.pop();
        }
        else{
            ret=maxim.top();
            maxim.pop();
        }
        return ret;
    }
private:    

    void balance()
    {
        if(maxim.size()-minim.size()==2)
        {
            long int aux=maxim.top();
            maxim.pop();
            minim.push(aux);
        }
        if(minim.size()-maxim.size()==2)
        {
            long int aux=minim.top();
            minim.pop();
            maxim.push(aux);
        }
    }
};