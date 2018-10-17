#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    while(~scanf("%d", &n))
    {
        if(n==0) break;
        int a[n+1], b[n+1];
        for(int j=1; j<=n; j++) cin>>a[j];
        for(int j=1; j<=n; j++) cin>>b[j];
        sort(a+1, a+n+1);
        sort(b+1, b+n+1);
        int l1=1, l2=1, r1=n, r2=n, ans=0;
        while(l1<=r1 && l2<=r2)
        {
            if(a[r1] > b[r2])
            {
                ans ++;
                r1--;
                r2--;
                continue;
            }
            else if(a[r1] < b[r2])
            {
                ans --;
                l1++;
                r2--;
                continue;
            }
            else if(a[r1] == b[r2])
            {
                if(a[l1] > b[l2])
                {
                    ans++;
                    l1++;
                    l2++;
                }
                else if(a[l1] < b[l2])
                {
                    ans--;
                    l1++;
                    r2--;
                }
                else if(a[l1] == b[l2])
                {
                    if(a[l1] < b[r2]) ans--;
                    l1++;
                    r2--;
                }
                continue;
            }
        }
        cout<<ans*200<<endl;
    }
    return 0;
}