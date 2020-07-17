#include <bits/stdc++.h>
#define int long long int
using namespace std;
string arr;

int solve(int s, int e, char ch)
{
    int i, cnt = 0, cnt2 = 0;
    for (i = s; i <= (s + e) / 2; i++)
    {
        if (arr[i] != ch)
            cnt++;
    }
    //cout<<cnt<<" "<<cnt2<<endl;
    if (s == e)
        return cnt;
    cnt += solve((s + e) / 2 + 1, e, ch + 1);
    for (i = (s + e) / 2 + 1; i <= e; i++)
    {
        if (arr[i] != ch)
            cnt2++;
    }
    //cout<<cnt<<" "<<cnt2<<endl;
    cnt2 += solve(s, (s + e) / 2, ch + 1);
    //cout<<cnt<<" "<<cnt2<<endl;
    return min(cnt, cnt2);
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cin >> arr;
        cout << solve(0, n - 1, 'a') << endl;
    }
}
