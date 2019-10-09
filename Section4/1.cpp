#include <iostream>
#include <cstring>
#include <string>
#include <set>
using namespace std;

struct Pattern
{
    int size;
    set<int> p[51];

    void init(string s)
    {
        size = 0;
        int len = s.length();
        int i=0;
        for( ; i<len; ++i)
        {
            if(s[i]!='[')
            {
                p[size++].insert(tolower(s[i]));
                continue;
            }
            ++i;
            while(s[i]!=']')
               p[size].insert(tolower(s[i])), ++i;
            ++size;
        }
    }

    bool check(string s)
    {
        int len = s.length();
        if(len != size)
            return 0;
        for(int i=0; i<len; ++i)
            if(p[i].find(tolower(s[i]))==p[i].end())
                return 0;
        return 1;
    }
};

int N;
Pattern pattern;
string str[53];

void init()
{
    ios::sync_with_stdio(0);
    cin >> N;
    for(int i=0; i<N; ++i)
        cin >> str[i];
    cin >> str[N];

    pattern.init(str[N]);
}

void process()
{
    for(int i=0; i<N; ++i)
    {
        if(pattern.check(str[i]))
            cout << i+1 << ' ' << str[i] << endl;
    }
}

int main()
{
    init();
    process();
}