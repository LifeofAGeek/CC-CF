#include <bits/stdc++.h>
using namespace std;
#define int long long

void helper(int s, int k, vector<int> d)
{
    int j, diff ;
    j = s - 1, diff = s;
    k--;
    while (k--)
    {
        if (d[s] < d[j])
        {
            s++, diff = s;
        }
        else
            diff = j--;
    }
    cout << diff << ' ';
}

int solve()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> d(n+1);
    d[0] = INT_MAX;
	d[n] = INT_MAX;
	for(int i = 1; i < n; i++) cin >> d[i];

    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
    {
        A[i] = i;
    }

    vector<bool> vis(n + 1, false);

    while (Q--)
    {
        int s, k;
        cin >> s >> k;
        helper(s, k, d);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout<<endl;
    }
    return 0;
}