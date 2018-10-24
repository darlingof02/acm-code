#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int m, n;
        cin>>m>>n;
        if(m>n) swap(m, n);
        int sum = 0;
        for(int j=m/2*2+1; j <= n; j += 2)
        {
            sum += j;
        }
        cout<<sum<<endl;
    }
    return 0;
}