#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define mod 998244353

void solve()
{
    //code here
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    multiset<int> map;
    arr[0] = 0; //1 based index
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        map.insert(arr[i]);
    }

    int p = 1, q = n;
    int cnt = 1;
    while (p <= q)
    {

        if (*map.begin() == arr[p])
        {
            p++;
            map.erase(map.lower_bound(*map.begin()));
        }
        else if (*map.begin() == arr[q])
        {
            q--;
            map.erase(map.lower_bound(*map.begin()));
        }
        else
        {
            while (p <= q and arr[p] != *map.begin())
            {
                map.erase(map.lower_bound(arr[p]));
                p++;
            }
            cnt = p;
        }
    }
    cout << cnt-1 << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
