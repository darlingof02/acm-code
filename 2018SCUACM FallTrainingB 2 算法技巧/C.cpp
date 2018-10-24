#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
#define MAX 100001

using namespace std;
int n;
char a[MAX];
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &n);
    scanf("%s", a);
    sort(a, a+n);
    cout<<a<<endl;
    return 0;
}