#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Term
{
    int a,p;
    Term(){};
    Term(int a_, int p_):a(a_),p(p_){};

    bool operator < (const Term& t) const
    {
        return p < t.p;
    }
}expression[700], output[302];

int t;

int main()
{
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--)
    {
        int n = 0;

        while(1)
        {
            cin >> expression[n].a >> expression[n].p;
            if(expression[n].p < 0)
                break;
            ++n;
        }

        while(1)
        {
            cin >> expression[n].a >> expression[n].p;
            if(expression[n].p < 0)
                break;
            ++n;
        }

        sort(expression, expression+n);

        --n;
        int m = 0;
        while(1)
        {
            Term tmp = expression[n--];
            int a = tmp.a;
            int p = tmp.p;

            while(n >= 0 && expression[n].p == p)
            {
                a += expression[n].a;
                --n;
            }

            if(a)
            {
                output[m].a = a;
                output[m].p = p;
                ++m;
            }

            if(n<0)
                break;
        }

        --m;
        for(int i=0; i<m; ++i)
        {
            cout << "[ " << output[i].a << " " << output[i].p << " ] ";
        }
        cout << "[ " << output[m].a << " " << output[m].p << " ]" << endl;

    }
}