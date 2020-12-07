#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

struct tEj {
    long int id, peri, acum;

    bool operator >(tEj const& ej) const {
        return acum > ej.acum || acum == ej.acum && id > ej.id;
    }
};

bool r()
{
    long int n,k;
    cin>>n;
    if(n>0)
    {
        priority_queue<tEj, vector<tEj>, greater<tEj>> v;
        tEj aux;

        while (n--) {
            cin >> aux.id >> aux.peri;
            aux.acum = aux.peri;
            v.push(aux);
        }
        cin >> k;
        while (k--) {
            aux = v.top();
            v.pop();
            cout << aux.id << '\n';
            aux.acum += aux.peri;
            v.push(aux);
        }
        cout << "---\n";
        return true;
    }
    return false;
}

int main() {
    long int n, k;

    while(r());
    return 0;
}
