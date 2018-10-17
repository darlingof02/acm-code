#include<iostream>
#include<algorithm>
#define MAX 10
using namespace std;

bool cmp(double x, double y)
{
    return x<=y;
}

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int n, m;
    cin>>n>>m;
    double *a = new double [n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        a[i] /= m*1.0;
    }
    sort(a, a+n, cmp);
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=n-1; j>i; j--)
        {
            if(a[i]+a[j] <= 1) {
                cnt++;
                a[j] = MAX;
                a[i] = MAX;
            }
            else continue;
        } 
    }
    cout<<n-cnt;
    delete []a;
    return 0;
}