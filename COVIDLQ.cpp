#include<bits/stdc++.h>
using namespace std;

string checkqueue(queue<int> q)
{
    int c=0;
    bool flag=false;
    int s=q.size();
    while (!q.empty())
    {
        if(q.front()==1)
        {
            q.pop();
            ++c;
        }
        if(q.front()==0)
        {
            q.pop();
            ++c;
        }
    }
    if(flag=true) return "YES";
    else return "NO";
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        queue<int> q;
        int A;
        for (int i = 1; i<=n; i++)
        {
            cin >> A;
            q.push(A);
        }
        cout<<checkqueue(q)<<endl;
    }
}