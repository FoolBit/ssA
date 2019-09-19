#include <iostream>
using namespace std;

int answer(int m, int n, int lb)
{
    if(m < lb)
        return 0;
    if(n == 1)
        return 1;

    int ub = m - n + 1;
    int sum = 0;

    for(int i=lb; i<=ub; ++i)
    {
        sum += answer(m-i, n-1, i);
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int M,N;
        cin >> M >> N;
        cout << answer(M,N,0) << endl;
    }
}