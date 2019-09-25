#include <iostream>
#include <queue>
using namespace std;

int m,n;
int error;
deque<int> q;

void init()
{
    ios::sync_with_stdio(0);
    cin >> m;
}

void process()
{
    q.clear();
    cin >> n;

    error = 0;
    string oper;
    int num;

    while(n--)
    {
        cin >> oper;
        if(oper == "push")
        {
            cin >> num;
            q.push_front(num);
        }
        else
        {
            if(q.empty())
            {
                error = 1;
                continue;
            }
            q.pop_front();
        }
    }

}

void print()
{
    if(error)
    {
        cout << "error" << endl;
        return;
    }

    if(q.empty())
        return;

    cout << q.back();
    q.pop_back();
    while(q.size())
    {
        cout << ' ' << q.back();
        q.pop_back();
    }
    cout << endl;
}

void run()
{
    while(m--)
    {
       process();
       print();
    }

}

int main()
{
    init();
    run();
}