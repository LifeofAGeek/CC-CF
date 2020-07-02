#include <bits/stdc++.h>
using namespace std;
#define ll long long 

bool cmp(ll v, ll c){
    return v>c;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll v,c,n,m;
        cin>>v>>c>>n>>m;
        bool check = cmp(v,c);
        char t1,t2;
        string ans="";
        if(v==0 && c==0) cout<<"No"<<endl;
        else{
            if(check) t1='v', t2='c';
            else t1='c', t2='v';
            //cout<<t1<<" "<<t2<<endl;
            if(t1=='v' && t2=='c'){
                if(v>=n && c>=m) ans="Yes";
                else if(v+c>=n+m && v!=0 && c!=0){
                    ans="Yes";
                }
                else {
                    bool now= (v>=n) && (c>=m);
                    if(now) ans="Yes";
                    else ans="No";
                }
            }
            else{
                if(v>=m && c>=n) ans="Yes";
                else if(v+c>=n+m && v!=0 && c!=0){
                    ans="Yes";
                }
                else {
                    bool now = (c>=n) && (v>=m);
                    if(now) ans="Yes";
                    else ans="No";
                }
            }
            cout<<ans<<endl;
        }
    }
}