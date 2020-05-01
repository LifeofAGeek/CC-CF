#include<bits/stdc++.h>
#define ll  long long int
#define pb push_back
#define fi first 
#define si second
#define pii pair<int,int>
#define map unordered_map<char,int>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,q;
        string s;
        cin>>n>>q;
        cin>>s;
        map m;
        for (int i = 0; i < n; i++) m[s[i]]+=1;
        //for (auto it =m.begin();it !=m.end();++it) cout << it->first << " = "<< it->second << '\n';
        //cout<<endl;
        while (q--)
        {
            int c;
            cin>>c;
            int size=0;
            for(auto it =m.begin();it !=m.end();++it){ 
                if(it->second > c) {
                    //cout<<"ele="<<it->first<<" "<<"freq="<<it->second<<endl;
                    size+=it->second - c;
                    //cout<<"curr size="<<size<<endl;
                    }
            }
            cout<<size<<endl;
        }
    }
    
}