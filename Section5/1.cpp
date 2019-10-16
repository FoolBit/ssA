#include <cstring>
#include <iostream>
using namespace std;
constexpr int MAXN = 65540*2;
int seq[MAXN];

int getIdx(int a, int l)
{
    while(seq[l]!=a)
        ++l;
    return l;
}


void rebuild(int mid_l, int mid_r, int post_l, int post_r)
{
    if(mid_l > mid_r)
        return;
    int val_root = seq[post_r];
    cout << val_root << ' ';

    if(mid_l==mid_r)
        return;

    int mid_root = getIdx(val_root, mid_l);
    int len_right = mid_r - mid_root;

    rebuild(mid_l, mid_root-1, post_l, post_r - len_right - 1);
    rebuild(mid_root+1, mid_r, post_r-len_right, post_r-1);
}


int main()
{
    int cnt = 0;
    while(cin >> seq[cnt])
        ++cnt;
    --cnt;
    int mid = cnt >> 1;
    rebuild(0, mid, mid+1, cnt);
}