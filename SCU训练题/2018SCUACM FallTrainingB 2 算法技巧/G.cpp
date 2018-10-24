#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#define ll long long
#define MAX (int)(1e5+1)
using namespace std;

struct noise{
    int s;
    int h;
    string str;
};

bool cmp(noise a, noise b)
{
    return (ll)a.s*b.h>(ll)a.h*b.s;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    noise set[MAX];
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>set[i].str;
        set[i].s = 0;
        set[i].h = 0;
        for(int j=0; j<set[i].str.length(); j++)
        {
            if(set[i].str[j] == 's') set[i].s++;
            if(set[i].str[j] == 'h') set[i].h++;
        }
    }
    sort(set, set+n, cmp);
    string a;
    a.clear();
    ll len=0;
    for(int i=0; i<n; i++)
    {
        a += set[i].str;
    }
    len = a.length();
    ll sum=0, ans=0;
    for(int i=0; i<len; i++)
    {
        if(a[i] == 's') sum++;
        if(a[i] == 'h') ans += sum;
    }
    cout<<ans<<endl;
    return 0;
}