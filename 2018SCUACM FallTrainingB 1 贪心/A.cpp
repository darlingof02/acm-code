#include<iostream>
#include<algorithm>
#include<vector>
#define MAXSIZE 10000
using namespace std;

struct nm{
    int num;
    char C;
public:
    nm(){num=1; C='#';}
    ~nm(){};
};

char itpt(char c)
{
    if(c>='A'&&c<='Z')
        return c+'a'-'A';
    else return c;
}

bool isfind(char c, int l, nm A[], int &x)
{
    int flag = false;
    for(int i=0; i<l; i++)
    {
        if(A[i].C == c) {
            flag = true;
            x = i;
            break;
        }
        else continue;
    }
    return flag;
}

bool cmp(nm x, nm y)
{
    return x.num>=y.num;
}

int calculate(nm A[], int cnt)
{
    int val = 26;
    int sum=0;
    sort(A, A+cnt, cmp);
    for(int i=0; i<cnt; i++)
    {
        if(val != -1)
            sum += A[i].num*(val--);
        else break;
    }
    return sum;
}

void valuate(string a)
{
    int cnt = 0;
    nm *A = new nm[MAXSIZE];
    for(int i=0; i<a.length(); i++)
    {
        int t=-1;
        a[i] = itpt(a[i]);
        if(isfind(a[i], cnt, A, t))
        {
            A[t].num++;
        }
        else A[cnt++].C = a[i];
    }
    int ret = calculate(A, cnt);
    cout<<ret<<endl;
}

int main()
{//   freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    string a;
    cin>>a;
    valuate(a);
    return 0;
}