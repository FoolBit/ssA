#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

constexpr int MAXN = 600;
constexpr int MAXLEN = 60;

int value[27];
int lc[MAXLEN],rc[MAXLEN];
char op[MAXLEN];
char expre[MAXLEN];
int nc,deep;

int buildTree(char*s, int l, int r)
{
    int c1 = -1, c2 = -1, p = 0;
    int u;
    if(l == r)
    {
        u = ++nc;
        lc[u] = rc[u] = 0;
        op[u] = s[l];
        return u;
    }

    for(int i=l; i<=r; ++i)
    {
        switch(s[i])
        {
        case '(':
            ++p;break;
        case ')':
            --p;break;
        case '+':
        case '-':
            if(!p) c1 = i;
            break;
        case '*':
        case '/':
            if(!p) c2 = i;
            break;
        }
    }

    if(c1 < 0)
        c1 = c2;
    if(c1 < 0)
        return buildTree(s, l+1, r-1);

    u = ++nc;
    op[u] = s[c1];
    lc[u] = buildTree(s, l, c1-1);
    rc[u] = buildTree(s, c1+1, r);

    return u;
}

void postord(int root, int depth)
{
    if(!root)
        return;
    deep = max(depth, deep);
    postord(lc[root], depth+1);
    postord(rc[root], depth+1);
    cout << op[root];
}

char graph[MAXN][MAXN];

void generateGraph(int root, int pos, int line, int delta)
{
    graph[line][pos] = op[root];
    if(lc[root])
        graph[line+1][pos-1] = '/', generateGraph(lc[root], pos-delta, line+2, delta>>1);
    if(rc[root])
        graph[line+1][pos+1] = '\\', generateGraph(rc[root], pos+delta, line+2, delta>>1);

}

void printGraph()
{
    memset(graph, ' ', sizeof(graph));
    int len = 1 << (deep+1);
    int pos = (len-1) >> 1;

    int delta = 1 << (deep-1);
    generateGraph(1, pos, 0, delta);

    int lines = deep*2+1;
    for(int i=0;i<lines;++i)
    {
        for(int j=0; j<len; ++j)
            cout << graph[i][j];
        cout << endl;
    }
}

void init()
{
    cin >> expre;
    char c;
    int n,a;
    cin >> n;
    while(n--)
    {
        cin >> c >> a;
        value[c-'a'] = a;
    }
}

int calculate(int root)
{
    int l = lc[root], r = rc[root];
    if(!l)
        return value[op[root]-'a'];
    switch(op[root])
    {
    case '+':
        return calculate(l)+calculate(r);
    case '-':
        return calculate(l)-calculate(r);
    case '*':
        return calculate(l)*calculate(r);
    default:
        return calculate(l)/calculate(r);
    }
}

int main()
{
    init();
    buildTree(expre, 0, strlen(expre)-1);
    postord(1, 0);
    cout << endl;
    printGraph();
    cout << calculate(1);
}
