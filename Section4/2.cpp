#include <cstring>
#include <iostream>
using namespace std;

void handleString()
{
    char c;
    cout << '"';
    while(1)
    {
        cin.get(c);
        cout << c;
        if(c == '\\')
        {
            cin.get(c);
            cout << c;
            continue;
        }
        if(c == '"')
            break;
    }
}

void handleNotion()
{
    char c;
    cin >> c;
    while(1)
    {
        cin >> c;
        if( c == '*')
        {
            if(cin.peek()=='/')
            {
                cin >> c;
                break;
            }
        }
    }
}

int main()
{
    char c;
    while(cin.get(c))
    {
        if(c == '"')
        {
            handleString();
            continue;
        }
        else if(c == '/')
        {
            if(cin.peek() == '*')
                handleNotion();
            continue;
        }
        cout << c;
    }

}