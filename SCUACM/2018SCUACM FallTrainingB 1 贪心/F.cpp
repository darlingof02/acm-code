#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#define ll long long

using namespace std;

struct nm{
    ll l, r;
    friend bool cmp(nm a, nm b);
};

bool cmp(nm a, nm b)
{
    if(a.l==b.l) return a.r<b.r;
    else return a.l<b.l;
}

ll max(ll a, ll b)
{
    return a>b?a:b;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, T;
    scanf("%d %d", &n, &T);
    nm *a = new nm[n];
    for(int i=0; i<n; i++)
    {
        scanf("%lld %lld", &a[i].l, &a[i].r);
    }
    sort(a, a+n, cmp);
    int t=0, s=0, cnt=0, j=0;
    while(j<n && t<T)
    {
        if(a[j].l > s+1) break;
        while(j<n && a[j].l <= s+1)
        {
            if(a[j].r > t) t = max(t, a[j].r);
            j++;
        }
        cnt++;
        s = t;
    }
    if(t == T) cout<<cnt<<endl;
    else cout<<-1<<endl;
    return 0;
}