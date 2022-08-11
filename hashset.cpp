#include<bits/stdc++.h>
using namespace std;

bool debug=0;

class unset
{
    public:
    vector<vector<int>> items;
    int a,b,c,n,size;
    double lf=1.0;

    unset(int k=10,double f=1.0)
    {
        lf =f;
        size=k;
        n=0;
        items.resize(k);
        srand(time(0));
        a=rand();
        b=rand();
        c=rand();
    }

    int hash(int x)
    {
        int v= (a*x*x+b*x+c);
        v%=size;
        v+=size;
        return v%size;
    }
    void insert(int x)
    {   
        if(n>lf*size)
        expand();
        if(search(x))
        return;
        items[hash(x)].push_back(x);
        n++;    
        if(debug)
        cout<<"Inserted "<<x<<endl;

    }
    
    bool search(int x)
    {
        int bucket_number= hash(x);
        for(auto i:items[bucket_number])
        if(i==x)
        return 1;
        return 0;
    }

    void erase(int x)
    {
        if(!search(x))
        return;

        int k=hash(x);

        items[k].erase(find(items[k].begin(),items[k].end(),x));

    }

    void expand()
    {   
        if(debug)
        cout<<"doubled size from "<<size<<" to "<<2*size<<endl;
        size*=2;
        vector<vector<int>> item2 = items;
        items.clear();
        items.resize(size);
        n=0;
        for(auto v: item2)
        for(auto i:v)
        insert(i);
    }


};

int main()
{  
    int n=1000; 
    unset x;
    // unset x(1e5);
    for(int i=0;i<n;i++)
    {
        x.insert(i);
    }
    for(int i=0;i<n;i++)
    {
        x.search(i);
        // if(x.search(i))
        // cout<<"found "<<i<<endl;
        // else
        // cout<<"Not found "<<i<<endl;
        
    }
    for(int i=0;i<n;i++)
    {
        x.erase(i);
    }

    return 0;
}
