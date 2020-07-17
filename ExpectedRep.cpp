#include <bits/stdc++.h>
#define int long long
using namespace std;
#define mod 998244353
string str;                 //fucked up string
int w[26];                  //given weight
map<string, int> occur, sw; // no. of occurrence of a substr, sub-string weight


bool valid(string r, string str)
{
    int n1 = (int)str.size(), n2 = (int)r.size();
    for (int it = 0; it < n1; it++)
    {
        if (str[it] != r[it % n2])
            return false;
    }
    return true;
}

int helper(string str)
{
    int sum = 0LL;
    for (auto i : str) sum += w[i - 'a'];
    return sum;
}

int handler(string str)
{
    int sum = 0LL, n = (int)str.size();
    for (int it = 1; it <= n; it++)
    {
        if (valid(str.substr(0, it), str) == true) {
            sum += sw[str.substr(0, it)];
        }
    }
    return sum;
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

void solve()
{
    cin >> str;
    for (int i = 0; i < 26; i++)
        cin >> w[i];

    //print(w);

    int n = (int)str.length();
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j + i <= n; j++)
        {
            if (occur.find(str.substr(i, j)) == occur.end())
            {
                sw[str.substr(i, j)] = helper(str.substr(i, j));
            }
            occur[str.substr(i, j)] += 1;
        }
    }

    int power = 0LL;
    for (auto it : occur)
    {
        (power += handler(it.first) * it.second) %= mod;
    }
    int ans = (power * modInverse((n * (n + 1))/2, mod)) % mod;
    cout << ans << endl;

    occur.clear();
    sw.clear();
    memset(w, 0, sizeof(w));
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