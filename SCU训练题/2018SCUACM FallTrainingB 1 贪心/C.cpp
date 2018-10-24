#include<iostream>
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

struct nm{
    ll val;
    friend bool operator <(nm a, nm b)
    {
        return a.val>b.val;
    }
};


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    cin>>n;
    priority_queue<nm> a;
    for(int i=0; i<n; i++){
        nm x;
        cin>>x.val;
        a.push(x);
    }
    ll sum=0;
    while(!a.empty())
    {
        nm x = a.top();
        a.pop();
        sum += x.val;
        if(a.empty()){
            break;
        }
        nm y = a.top();
        a.pop();
        sum += y.val;
        if(a.empty()){
            break;
        }
        nm result;
        result.val = x.val+y.val;
        a.push(result);
    }
    cout<<sum<<endl;
    return 0;
}