#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define MAX 100005
using namespace std;

char str[MAX];
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%s", str+1);
    int len = strlen(str+1);
    int cnt = 0, flag = 0;
    char a = 'a';
    for(int i = 1; i<=len; i++)
    {
        if(str[i] == 'a'){
            flag = i;
            break;
        }
    }
    if(!flag) {cout<<-1<<endl; return 0;}
    if(flag != 0)
    {
        for(int i=flag; i<=len; i++)
        {
            if(str[i] <= a)
            {
                str[i] = (char)a;
                a++;
                cnt++;
                if(cnt>=26) break;
            }
        }
    }
    else {
        cout<<-1<<endl;
        return 0;
    }
    if(cnt == 26)
    {
        for(int i=1; i<=len; i++)
        {
            cout<<str[i];
        }
        cout<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}