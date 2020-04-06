// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// Function to perform the given operation on arr[]
ll operations(vector<ll> arr, int n)
{
    make_heap(arr.begin(), arr.end());
    int year = 0;
    ll sum = 0;
    while (n)
    {

        // Pick largest non-zero element from Max-heap
        if (arr.front() - year > 0)
        {
            sum += arr.front() - year;
            year++;
            pop_heap(arr.begin(), arr.end());
            arr.pop_back();
            n--;
        }

        // Skip elements which are 0
        else
        {
            break;
        }
    }
    return sum%1000000007;
}

int main()
{
    int n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> arr;
        ll val;
        for (int i = 1; i <= n; i++)
        {
            cin >> val;
            arr.push_back(val);
        }
        cout<<operations(arr, n)<<endl;
    }
    return 0;
}
