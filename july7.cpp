#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define mod 998244353

void print(vector<int> arr)
{
    for (int i = 1; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int BE(int base, int power) //Modular Exponentiation -> mod value
{
    int ans = 1;
    while (power)
    {
        if (power & 1)
            ans = (ans * base) % mod, power--;
        else
            base = (base * base) % mod, power /= 2;
    }
    //cout<<"Computed value is = "<<ans<<endl;
    return ans;
}

//taken from geekforgeeks
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0LL)
    {
        *x = 0LL;
        *y = 1LL;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    // m is added to handle negative x
    int res = (x % m + m) % m;
    return res;
}
//taken from geekforgeeks

int calc(int i, int j, int x, vector<int> A, vector<int> pre)
{
    int ans;
    int X = modInverse(BE(x, i - 1), mod);
    ans = ((A[i]) % mod + ((pre[j] - pre[i]) * X) % mod) % mod;
    return ans;
}

void solve2(vector<int> A, int n, int x)
{
    vector<int> pre(n + 1);
    pre[1] = A[1];
    for (int i = 2; i <= n; i++)
    {
        pre[i] = ((pre[i - 1]) % mod + (A[i] * BE(x, i - 1)) % mod) % mod;
    }

    int p = 1;
    for (int i = 1, c = n; i <= n && c > 0; i++, c--)
    {
        p = ((p % mod) * (BE(pre[i], 2 * c)) % mod) % mod;
    }

    cout << p << endl;
}

void solve1(vector<int> A, int n, int x, int p)
{
    vector<int> pre(n + 1);
    pre[1] = A[1];
    for (int i = 2; i <= n; i++)
    {
        pre[i] = ((pre[i - 1]) % mod + (A[i] * BE(x, i - 1)) % mod) % mod;
    }
    //print(pre);

    for (int i = 2; i <= n; i++)
    {
        p = ((p % mod) * (pre[i] % mod)) % mod;
    }

    //int p = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            p = ((p % mod) * (calc(i, j, x, A, pre)) % mod) % mod;
        }
    }

    int ans = BE(p,2)%mod;
    cout << ans << endl;
}

int32_t main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> A(n + 1);
        unordered_map<int, int> st;
        int p = 1;
        bool flag = true;
        for (int i = 1; i < A.size(); i++)
        {
            cin >> A[i];
            p = ((p % mod) * (A[i] % mod)) % mod;
            st[A[i]] += 1;
        }
        if (p == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            if (st[A[1]] < n)
            {
                solve1(A, n, x, p);
            }
            else
            {
                solve2(A, n, x);
            }
        }
    }
    return 0;
}
