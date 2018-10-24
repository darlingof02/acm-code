#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#define N 4000
using namespace std;
int A[N], B[N], C[N], D[N];
int o[N*N], p[N*N];

bool binary(int a[], int left, int right, int x)
{
    int mid = left+(right-left)/2;
    if(left > right) return false;
    if(x>a[mid]) return binary(a, mid+1, right, x);
    else if(x<a[mid]) return binary(a, left, mid-1, x);
    else return true;
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>A[i]>>B[i]>>C[i]>>D[i];
    }
    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            o[cnt++] = A[i] + B[j];
        }
    }
    cnt = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            p[cnt++] = C[i] + D[j];
        }
    }
    cnt=0;
    sort(p, p+n*n);
    for(int i=0; i<n*n; i++)
    {
        if(binary(p, 0, n*n-1, 0-o[i]))
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}