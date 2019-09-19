#include <iostream>
#include <cstring>
using namespace std;

struct BigInt
{
    int v[1000];
    int length=0;

    BigInt()
    {
        memset(v,0,sizeof(v));
    };
    BigInt(int n)
    {
        if(n==0)
        {
            v[length++] = 0;
            return;
        }
        while(n)
        {
            v[length++] = n%10;
            n /= 10;
        }
    }

    BigInt(string s)
    {
        int len = s.length();
        for(int i=len-1; i>=0; --i)
        {
            v[length++] = s[i] - '0';
        }
    }

    friend ostream& operator << (ostream &os, const BigInt& a)
    {
        for(int i=a.length-1; i>=0; --i)
        {
            os << a.v[i];
        }
        return os;
    }

    friend BigInt operator*(const BigInt& a, const BigInt& b)
    {
        int lena = a.length;
        int lenb = b.length;
        BigInt c;
        c.length = lena + lenb;

        for(int i=0; i<lena; ++i)
        {
            for(int j=0; j<lenb; ++j)
            {
                c.v[i+j] += a.v[i] * b.v[j];
                c.v[i+j+1] += c.v[i+j] / 10;
                c.v[i+j] %= 10;
            }
        }

        while(!c.v[c.length-1] && c.length>1)
        {
            --c.length;
        }
        return c;
    }
};

int main()
{
    string a,b;
    cin >> a >> b;
    cout << BigInt(a)*BigInt(b);
}
