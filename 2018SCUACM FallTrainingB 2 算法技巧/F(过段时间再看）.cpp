#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;
const int MAX = 2*1e5+1;
int h[MAX];
int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n, k, maxhight=0;
    memset(h, 0, sizeof(h));
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d", &x);
        h[x]++;
        maxhight = max(maxhight, x);
    }
    int mov=0;
    int curk = 0;
    for(int curh = maxhight; curh>=0; curh--)
    {
        if(h[curh] == n)
        {
            if(curk) mov++;
            break;
        }
        else
        {
            if(curk + h[curh]<=k)
            {
                curk += h[curh];
            }
            else
            {
                curk = h[curh];
                mov++;
            }
            h[curh-1] += h[curh];   //此处需注意
        }
    }
    cout<<mov<<endl;
    return 0;
}