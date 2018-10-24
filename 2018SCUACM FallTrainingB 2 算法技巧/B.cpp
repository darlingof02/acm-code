#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    char str[51], prefix[51], suffix[51];
    scanf("%s", str);
    int len = strlen(str);
    int repeatlen = 0;
    for(int k=len-1; k>=0; k--)
    {
        memset(prefix, 0, sizeof(prefix));
        memset(suffix, 0, sizeof(suffix));
        for(int i=0; i<k; i++)
        {
            prefix[i] = str[i];
        }
        for(int j=len-k, i=0; j<len; j++, i++)
        {
            suffix[i] = str[j];
        }
        if(!strcmp(prefix, suffix))
        {
            repeatlen = k;
            break;
        }
    }
    int startpos=0, strcnt=0;
    char ans[5001];
    memset(ans, 0, sizeof(ans));
    // cout<<prefix<<endl;
    // cout<<suffix<<endl;
    // cout<<repeatlen<<endl;
    while(strcnt<k)
    {
        for(int i=startpos, j=0; i<startpos + len; i++, j++)
        {
            ans[i] = str[j];
        }
        strcnt++;
        startpos = startpos + len - repeatlen;
    }
    cout<<ans<<endl;
    return 0;
}