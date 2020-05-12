#include <bits/stdc++.h>
using namespace std;

vector<int> ar;
vector<vector<int>> final_arr;

bool din(vector<int> ar1, vector<int> ar2)
{
    return ar1.size() > ar2.size();
}

void printSwaps(vector<int> &ar)
{
    for (auto c : ar)
    {
        cout << c << " ";
    }
    cout << endl;
}

void shift(int a, int b, int c)
{
    int A = ar[a];
    int B = ar[b];
    int C = ar[c];

    ar[a] = C;
    ar[b] = A;
    ar[c] = B;
}

void club_cycles(pair<int, int> a, pair<int, int> b)
{
    shift(a.first, b.second, a.second);
    shift(b.first, b.second, a.second);
    vector<int> one({a.first + 1, b.second + 1, a.second + 1});
    vector<int> two({b.first + 1, b.second + 1, a.second + 1});
    vector<vector<int>> ans;
    final_arr.push_back(one);
    final_arr.push_back(two);
}

void helper(vector<pair<int, int>> cycles)
{

    if (cycles.empty())
    {
        return;
    }
    
    for (int j = 0; j < cycles.size(); j += 2)
    {
        auto c = cycles[j];
        auto d = cycles[j + 1];
        int a = c.first;
        int b = c.second;
        int e = d.first;
        int f = d.second;
        assert(b == e);
        shift(a, f, b);
        vector<int> xyz({a + 1, f + 1, b + 1});
        final_arr.push_back(xyz);
    }
}

void find_swaps()
{
    final_arr.clear();
    int n, k;
    cin >> n >> k;
    ar.resize(n);

    for (auto &c : ar)
    {
        cin >> c;
        c--;
    }

    int p = 0;
    int th = 0;
    vector<int> vis(n, false);
    vector<vector<pair<int, int>>> all_pairs;
    vector<vector<int>> threes;

    for (int i = 0; i < n; i++)
    {
        vector<pair<int, int>> pairs;
        vector<int> loops;
        if (vis[i])
        {
            continue;
        }

        int temp = i;
        vis[i] = true;
        while (ar[temp] != i)
        {
            temp = ar[temp];
            vis[temp] = true;
            loops.push_back(temp);
        }

        loops.push_back(i);
        reverse(loops.begin(), loops.end());

        if (loops.size() == 3)
        {
            vector<int> tp{loops[0] + 1, loops[2] + 1, loops[1] + 1};
            threes.push_back(tp);
            shift(loops[0], loops[2], loops[1]);
        }
        else
        {
            for (int i = 1; i < loops.size(); i++)
            {
                pairs.push_back({loops[i - 1], loops[i]});
            }
        }
        all_pairs.push_back(pairs);
    }
    vector<pair<int, int>> combine_loops;
    int total = 0;

    for (int i = 0; i < all_pairs.size(); i++)
    {
        auto c = all_pairs[i];
        for (auto d : c)
        {
            total++;
        }
    }

    if (total & 1)
    {
        cout << -1 << endl;
        return;
    }

    for (auto &c : all_pairs)
    {
        int sz = c.size();
        if (sz & 1)
        {
            combine_loops.push_back(c.back());
            c.pop_back();
        }
        helper(c);
    }

    int t = combine_loops.size();
    int i = 0;
    int j = t / 2;
    while (j < t)
    {
        club_cycles(combine_loops[i], combine_loops[j]);
        i++;
        j++;
    }

    for (auto c : threes)
    {
        final_arr.push_back(c);
    }

    if (final_arr.size() > k)
    {
        cout << -1 << endl;
        return;
    }
    cout << final_arr.size() << endl;
    for (auto c : final_arr)
    {
        printSwaps(c);
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (ar[i] != i)
        {
            flag = false;
        }
    }
    assert(flag);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        find_swaps();
    }
}