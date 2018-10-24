#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include <cstdio>
#define ll long long
using namespace std;

struct sk{
    double q;
    double p;
    double val;
};

bool cmp(sk x, sk y)
{
    return x.val<y.val;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n;
    double m;
    while(cin>>m>>n)
    {
        if(m==-1 && n==-1) break;
        sk a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i].q>>a[i].p;
            a[i].val = a[i].p/a[i].q;
        }
        sort(a, a+n, cmp);
        double current=0, sum=0;
        int i=0;
        while( i<n && m>current )
        {
            if(fabs(m-current<=1e-6)) break;
            if(m-current-a[i].p >= 1e-6) {
                current += a[i].p;
                sum += a[i].q;
                i++;
                continue;
            }
            else {
                double t = a[i].val;
                sum += (m-current)/a[i].val;
                break;
            }
        }
        printf("%.3f\n", sum);
    }
    return 0;
}