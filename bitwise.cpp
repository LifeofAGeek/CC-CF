#include <bits/stdc++.h>
using namespace std;

#define int long long int

int x, y, l, r;
int mask;

int f(int z)
{
    int ans;
    ans = (x & z) * (y & z);
    return ans;
}

int remove_bit(int x, int k)
{
    int one = 1;
    x = x ^ (one << k);
    return x;
}

int add(int x, int k)
{
    int one = 1;
    x = x | (one << k);
    return x;
}

int find_msb(int x)
{
    int k = log2(x);
    return k;
}

bool has_bit(int x, int k)
{
    int one = 1;
    return (x & (one << k));
}

void save_z(int x)
{
    if (x < l || x > r)
    {
        return;
    }
    if (f(x) > f(mask))
    {
        mask = x;
    }
    else if (f(x) == f(mask))
    {
        mask = min(mask, x);
    }
}

int set_bit(int x, int k)
{

    int one = 1;
    x = x ^ (x & (one << k));
    x = x | (one << k);
    return x;
}

int unset_bit(int x, int k)
{
    int one = 1;
    x = x ^ (x & (one << k));
    return x;
}

void findZ()
{
    cin >> x >> y >> l >> r;
    int p = x | y;

    mask = l;

    int k1 = find_msb(l);
    int k2 = find_msb(r);
    while (p > r)
    {
        int m = find_msb(p);
        if (m == k2)
        {
            break;
        }
        else if (m > k2)
        {
            p = remove_bit(p, m);
        }
    }

    int k = k2;
    for (k = k2; k >= 0; k--)
    {
        if (has_bit(r, k) == has_bit(l, k))
        {
            if (has_bit(r, k))
            {
                p = set_bit(p, k);
            }
            else
            {
                p = unset_bit(p, k);
            }
        }
        else
        {
            break;
        }
    }
    save_z(p);

    int hold = p;

    p = set_bit(p, k);

    for (int i = k; i >= 0; i--)
    {
        if (!has_bit(p, i) && !has_bit(r, i))
        {
            continue;
        }

        if (has_bit(p, i) && has_bit(r, i))
        {
            int tmp = remove_bit(p, i);
            save_z(tmp);
        }
        else if (has_bit(p, i))
        {
            p = remove_bit(p, i);
        }
        else
        {
            break;
        }
    }
    save_z(p);

    p = hold;
    p = unset_bit(p, k);
    for (int i = k; i >= 0; i--)
    {
        if (has_bit(l, i) == has_bit(p, i))
        {
            continue;
        }

        if (has_bit(l, i))
        {
            assert(!has_bit(p, i));
            p = add(p, i);
        }
        else
        {
            break;
        }
    }

    save_z(p);

    assert(mask >= l);
    assert(mask <= r);

    cout << mask << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        findZ();
    }
}