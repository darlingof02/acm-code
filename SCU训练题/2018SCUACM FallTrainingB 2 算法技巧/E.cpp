#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<deque>
using namespace std;

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    scanf("%d", &n);
    deque<int> ans;
    int cur = 1;
    while(n>=1)
    {
        if(n == 3)
        {
            ans.push_back(cur);
            ans.push_back(cur);
            ans.push_back(3*cur);
            break;
        }
        for(int i=0; i<=n; i++)
        {
            if(i%2 != 0)
            {
                ans.push_back(cur);
            }
        }
        cur *= 2;
        n /= 2;
    }
    
    
    while(!ans.empty())
    {
        cout<<ans.front()<<' ';
        ans.pop_front();
    }
    return 0;
}