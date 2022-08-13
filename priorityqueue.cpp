#include<bits/stdc++.h>
using namespace std;

class priqueue
{
public:
vector<int> a;    

void push(int x)
{
    a.push_back(x);
    int i=a.size()-1;
    while(i>0)
    {
        int p = (i-1)/2;
        if(a[i]>a[p])
        swap(a[i],a[p]);
        else break;
        i = p;
    }
}

void heapify(int x)
{
    int c1 = 2*x+1,c2 =2*x+2;

    if(c1>=a.size())
    return;

    if(c2>=a.size())
    if(a[c1]>a[x])
    {
        swap(a[c1],a[x]);
        heapify(c1);
        return;
    }
    else return;

    if(a[c2]>a[c1])
    swap(c1,c2);

    if(a[x]<a[c1])
    {
    swap(a[c1],a[x]);
    heapify(c1);
    }
}

int top()
{
    return a.front();
}
void pop()
{
    swap(a.back(),a.front());
    a.pop_back();
    if(a.size())
    heapify(0);
}
};


int main()
{
    priqueue x;
    // priority_queue<int> x;
    srand(time(0));
    int sz=1e6 ;
    for(int i=0;i<sz;i++) x.push(rand());
    vector<int> a;

    for(int i=0;i<sz;i++)
    {
    a.push_back(x.top());
    x.pop();
    }
    auto b=a;

    sort(b.rbegin(),b.rend());
    if(a!=b)
    cout<<"Not ";
    cout<<"Sorted";
    return 0;
}