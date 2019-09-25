#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int v,p;
    Node(int v_, int p_):v(v_),p(p_){};
};

int a[1000002];
deque<Node> q;
int n,k;



void init()
{
    cin >> n >> k;
    k = min(n, k);
    for(int i=0; i<n; ++i)
        cin >> a[i];
}

void printmin()
{
    int l=0,r=0;
    for( ; r<k; ++r)
    {
        while(q.size() && a[r]<q.front().v)
            q.pop_front();
        q.push_front(Node(a[r], r));
    }

    cout << q.back().v;

    for(++l; r<n; ++l,++r)
    {
        if(q.back().p < l)
            q.pop_back();
        while(q.size() && a[r]<q.front().v)
            q.pop_front();
        q.push_front(Node(a[r], r));
        cout << ' ' << q.back().v;
    }

    cout << endl;
}

void printmax()
{
    q.clear();
    int l=0,r=0;
    for( ; r<k; ++r)
    {
        while(q.size() && a[r]>q.front().v)
            q.pop_front();
        q.push_front(Node(a[r], r));
    }

    cout << q.back().v;

    for(++l; r<n; ++l,++r)
    {
        if(q.back().p < l)
            q.pop_back();
        while(q.size() && a[r]>q.front().v)
            q.pop_front();
        q.push_front(Node(a[r], r));
        cout << ' ' << q.back().v;
    }

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    init();
    printmin();
    printmax();
}