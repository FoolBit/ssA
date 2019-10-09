#include <string>
#include <cstring>
#include <iostream>

using namespace std;

#define MAX 1000002

int N, p[MAX];
string s;

void kmp()
{
    s = " " + s;
    p[1] = 0;
    int j = 0;
    for(int i=2; i<=N; ++i)
    {
        while(s[j+1]!=s[i] && j)
            j = p[j];
        if(s[j+1] == s[i])
            ++j;
        p[i] = j;
    }
}

void process()
{
    for(int i=2;i<=N;++i)
    {
        if(!p[i])
            continue;
        int k = i-p[i];

        if( !(i%k) )
            cout << i << ' ' << i/k << endl;
    }
}

int main()
{
    int cnt = 0;
    while(cin >> N)
    {
        ++cnt;
        if(!N)
            break;
        if(cnt!=1)
            cout << endl;
        cin >> s;
        cout << "Test case #" << cnt << endl;
        kmp();
        process();
    }
}