#include <bits/stdc++.h>
#define int long long
using namespace std;

void print(vector<int> arr)
{
    for (auto a : arr)
        cout << a << " ";
    cout << endl;
}

void printmap(map<int, int> m)
{
    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> A(n);
    for (auto &a : A)
        cin >> a;
    //input ends here

    //print(A);
    //cout<<mx<<" "<<mi;

    int days = 0;
    sort(A.begin(), A.end());

    if (x >= A[n - 1])
    {
        cout << n << endl;
        return;
    }
    else
    {
        int lb = lower_bound(A.begin(), A.end(), x) - A.begin(); //lower bound of x in A
        int now, index, res;
        if (lb != 0)
            now = A[lb - 1];
        res = lb;
        index = lb - 1;
        for (int it = lb; it < n; it++)
        {
            while (x < A[it])
            {
                x <<= 1;
                res++;
            }
            res++;
            x = A[it] * 2;
        }
        if (lb != 0)
        {
            for (int it = lb; it < n; it++)
            {
                while (now < A[it])
                {
                    now <<= 1;
                    index++;
                }
                index++;
                now = A[it] * 2;
            }
        }
        if (lb)
            cout << min(res, index) << endl;
        else
            cout << res << endl;
    }
}

int32_t main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
