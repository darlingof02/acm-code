#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#define ll long long 
using namespace std;

bool cmp(ll a, ll b)
{
    return a<b;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int m;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int n;
        cin>>n;
        ll *a = new ll[n];
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        sort(a, a+n, cmp);
        while(n > 3)
        {
            sum += min(a[0]+2*a[1]+a[n-1], a[n-1]+a[n-2]+2*a[0]);
            n -= 2;
        }
        if(n == 3)
        {
            sum += a[0] + a[1] + a[2];
        }
        else if(n == 2)
        {
            sum += a[1];
        }
        else if(n == 1)
        {
            sum += a[0];
        }
        cout<<sum<<endl;
    }
    return 0;
}