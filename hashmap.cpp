#include<bits/stdc++.h>
using namespace std;

class unmap
{

public:
vector<vector<pair<int,int> > > item;
int a,b,c,n,size;
double lf=1.0;

unmap(int k=100, double ff=1.0)
{
    size=k;
    lf=ff;
    n=0;
    item.resize(k);
    srand(time(0));
    a=rand();
    b=rand();
    c=rand();
}

int hash(int x)
{
    int v = a*x*x+b*x+c;
    v%=size;
    v+=size;
    return v%size ;
}

void insert(int key,int x)
{
    if(n>lf*size)
    expand();
    int k=hash(key);
    for(int i=0;i<item[k].size();i++)
    if(item[k][i].first==key)
    {
        item[k][i].second=x;
        return;
    }
        
    item[k].push_back({key,x});
    n++;
}

void erase(int key)
{
    int k=hash(key);
    for(int i=0;i<item[k].size();i++)
    if(item[k][i].first==key)
    {
        item[k].erase(item[k].begin()+i);
        return;
    }

}

void expand()
{
    size*=2;
    vector<vector<pair<int ,int>>> item2= item;
    item.clear();
    n=0;
    item.resize(size);
    for(auto v:item2)
    for(auto i:v)
    insert(i.first,i.second);
}

bool find_value_for_key(int key)
{
    int k=hash(key);
    for(int i=0;i<item[k].size();i++)
    if(item[k][i].first==key)
    {
        return item[k][i].second;        
        // if this returns 0
    }
    item[k].push_back({key,0});
    return 0;

}


};

int main()
{
    int n=1e6;
    unmap m(10,4);
    // unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    m.insert(i,i+1);
    for(int i=0;i<n;i++)
    m.find_value_for_key(i);
    return 0;

}