// 变成一个区间覆盖问题
#include <iostream>
#include <cstring>
using namespace std;

int in[16][65536];
int query[16][65536];
int p[17];
int N,M;

void read()
{
    int a;
    int base = 1;

    for(int i=0; i<17; ++i)
    {
        p[i] = base;
        base = base << 1;
    }

    for(int k=0; k<N; ++k)
    {
        cin >> a;
        for(int i=0; i<16; ++i)
        {
            int tmp = a%p[i+1];
            int l,r;
            if(tmp < p[i])
            {
                l = p[i] - tmp;
                r = p[i+1] - tmp;
            }
            else
            {
                ++in[i][0];
                r = p[i+1] - tmp;
                l = p[i+1] + p[i] - tmp;
            }
            ++in[i][l];
            --in[i][r];
        }
    }
}

void preProcess()
{
    for(int i=0; i<16; ++i)
    {
        int k = 0;
        for(int j=0; j<p[i+1]; ++j)
        {
            k += in[i][j];
            query[i][j] = k;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> N >> M;
    read();
    preProcess();

    char c;
    int n;
    int d = 0;
    while(M--)
    {
        cin >> c >> n;
        if(c == 'C')
        {
            d += n;
            d %= 65536;
        }
        else
        {
            int t = d % p[n+1];
            cout << query[n][t]<<endl;
        }
    }
}
