#include <bits/stdc++.h>
#define int long long int
using namespace std;
#define mod 1000000007


int32_t main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        map<pair<int,int>,vector<pair<int>>> mp;
        if(m){
            while (m--)
            {
                int x,y,r;
                vector<int> temp;
                cin>>x>>y>>r;
                if(r){
                    while (r--)
                    {
                        int p,e;
                        cin>>p>>e;
                        temp.push_back({p,e});
                    }
                    mp[{x,y}]=temp;
                }
                else{
                    temp.push_back({0,0});
                    mp[{x,y}]=temp;
                }
                temp.clear();
            }
        }
        else {
            cout<<-1<<endl;
        }
    }
    
}