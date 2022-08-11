#include<bits/stdc++.h>
using namespace std;

class priqueue
{
public:
vector<int> item;    
int variable;                                                                                               

priqueue()
{

}

void Max_insert(int x)
{
    item.push_back(x);
    int i=item.size()-1;
    while(i>0)
    {
        // heapify(i);
        int p = (i-1)/2;
        if(item[i]>item[p])
        swap(item[i],item[p]);
        else break;
        i = p;
    }

}


int Max_pop()  
{


    swap(item.front(),item.back());
    variable=item.back();
    item.pop_back();
    int i=0;
    if(item.size()%2==1)
    {
        while(i<item.size()/2)
        {
            if(item[i]<max(item[2*i+1],item[2*i+2]))
            {
                if(item[2*i+1]>item[2*i+2])
                {
                    swap(item[i],item[2*i+1]);
                    i=2*i+1;
                }
                else
                {
                    swap(item[i],item[2*i+2]);
                    i=2*i+2;
                }
            }


        }
        return variable;
    }
    else
    {
        while(i<item.size()/2)
        {
            if(i==(item.size()-1)/2)
            {
                if(item[i]<item[2*i+1])
                {
                        swap(item[i],item[2*i+1]);
                        i=item.size();
                }
                i++;

            }
            else
            {
            
                if(item[i]<max(item[2*i+1],item[2*i+2]))
                {
                    if(item[2*i+1]>item[2*i+2])
                    {
                        swap(item[i],item[2*i+1]);
                        i=2*i+1;
                    }
                    else
                    {
                           swap(item[i],item[2*i+2]);
                            i=2*i+2;
                    }
                }
            }
        }
        return variable;
    }
        
}

void heapify(int x)
{
    int c1 = 2*x+1,c2 =2*x+2;

    if( c1>=item.size() || item[x]>item[c1])
    if( c2>=item.size() || item[x]>item[c2])
    return;

    if(c2>=item.size())
    if(item[c1]>item[x])
    {

        swap(item[c1],item[x]);
        heapify(c1);
    }
    else return;


    if(item[c1]>item[c2])
    {
        swap(item[c1],item[x]);
        heapify(c1);

    }
    else
    {
        swap(item[c2],item[x]);
        heapify(c2);

    }
}

int pop()
{
    swap(item.back(),item.front());
    int ans = item.back();
    item.pop_back();
    if(item.size())
    heapify(0);
    
    // for(int i=0;i<item.size();i++)
    // cout<<item[i]<<' ';
    // cout<<endl;
    return ans;
}
    
    


};

// int Min_erase()
// {
//     swap(item[0],item[item.size()-1]);
//     variable=item[item.size()-1];
//     item.pop_back();
//     while(i<=item.size()/2)
//     {
//         if(item[2*i+1]<item[2*i+2])
//         {
//             if(item[i]<item[2*i+1])
//             {
//                 swap(item[i],item[2*i+1]);
//                 i=2*i+1;
//             }
//             else
//                 return variable;
            
//         }
//         else
//         {
//             if(item[i]<item[2*i+2])
//             {
//                 swap(item[i],item[2*i+2]);
//                 i=2*i+2;
//             }
//             else
//                 return variable;
            

//         }
//     }
    

    
// }









int main()
{
    priqueue x;
    int sz=1000 ;
    for(int i=0;i<sz;i++)
    {
        x.Max_insert(rand());
    }

    // for(int i=0;i<sz;i++)
    // cout<<x.item[i]<<' ';
    // cout<<endl;
    // return 0;

    // return 0;
    vector<int> a;
    for(int i=0;i<sz;i++)
    {
        a.push_back(x.pop());
        cout<<a.back()<<' ';
    }

    auto b=a;
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());

    for(int i=0;i<sz;i++)
    if(a[i]!=b[i])
    {

        cout<<endl<<a[i]<<' '<<b[i];
        cout<<"Not ";
        break;
    }

    cout<<"Sorted";

    // if(a==b)
    // cout<<"Sorted"<<endl;
    // else
    // cout<<"Not Sorted"<<endl;



    return 0;
}