#include<bits/stdc++.h>
#define ll  long long int
#define pb push_back
#define fi first 
#define si second
#define pii pair<int,int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int32_t main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,val;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            cin>>val;
            arr.pb(val);
        }
        vector<int> infected;
        int c;
        for(int i=0;i<n-1;i++)
        {
            c=1;
            if(c==n) {
                infected.pb(c);
                break;
                }
            for(int j=i+1;j<n;j++)
            {
                if((arr[j]-arr[j-1]) <=2){
                    c++;
                    infected.pb(c);
                }
                else break;
            }
        }
        if(!infected.empty()) cout<<*min_element(infected.begin(),infected.end())<<" "<<*max_element(infected.begin(),infected.end());
        else cout<<1<<" "<<1;
    }
}