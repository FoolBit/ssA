#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;

int read()
{
    int x=0, t=1;
    char c = getchar();
    while(c<'0'||c>'9')
    {
        if(c == '-')
            t = -1;
        c = getchar();
    }

    while(c>='0'&&c<='9')
    {
        x = x*10 + c-'0';
        c = getchar();
    }

    return x*t;
}

priority_queue<int, vector<int>, greater<int> > q;
int sum;

void init()
{
    int n = read();
    int a;
    while(n--)
    {
        a = read();
        q.push(a);
    }
}

void process()
{
    int a,b;
    while(q.size()>1)
    {
        a = q.top();q.pop();
        b = q.top();q.pop();

        sum += (a+b);
        q.push(a+b);
    }
}

void print()
{
    printf("%d", sum);
}

int main()
{
    init();
    process();
    print();
}