#include <iostream>
#include <cstring>
using namespace std;

void readline()
{
    char line[10];
    cin.getline(line,9);
}
int getExpression();
int getTerm();
int getFactor();
bool isNum(char c)
{
    if(c>='0' && c<='9')
        return 1;
    return 0;
}

int main()
{
    int N;
    cin >> N;
    while(N--)
    {
        readline();
        cout << getExpression() << endl;
    }
}

int getExpression()
{
    char c;
    int a;
    a = getTerm();
    while(c = cin.peek())
    {
        if(c!='+' && c!='-')
            break;
        cin >> c;
        if(c == '+')
            a += getTerm();
        else if(c == '-')
            a -= getTerm();
    }
    return a;
}

int getTerm()
{
    char c;
    int a;
    a = getFactor();
    while(c = cin.peek())
    {
        if(c!='*' && c!='/')
            break;
        cin >> c;
        if(c == '*')
            a *= getFactor();
        else if(c == '/')
            a /= getFactor();
    }
    return a;
}

int getFactor()
{
    char c;
    int a;
    c = cin.peek();
    if(isNum(c))
        cin >> a;
    else
    {
        cin >> c;
        a = getExpression();
        cin >> c;
    }
    return a;
}