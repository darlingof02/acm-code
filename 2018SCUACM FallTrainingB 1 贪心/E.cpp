#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdio>
#define ll long long

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n;
    cin>>n;
    double *a = new double[n];
    for(int i=0; i< n; i++)
    {
        cin>>a[i];
    }
    sort(a, a+n);
    for(int j=n-1; j>0; j--)
    {
        a[j-1] = 2*sqrt(a[j]*a[j-1]);
    }
    printf("%.3f\n", a[0]);
    delete []a;
    return 0;
}