#include <bits/stdc++.h>
#define int long long
using namespace std;

void print(vector<int> arr){
    for(auto a:arr) cout<<a<<" ";
    cout<<endl;
}

void printmap(map<int,int> m){
    for(auto it:m){
            cout<<it.first<<" "<<it.second<<endl;
        }
}

void solve()
{
    int n;
    cin>>n;
    //cout<<n<<endl;
    vector<int> A(n), B(n);
    map<int,int> m;
    int s=INT_MAX;

    for(int i=0;i<n;i++) {
        cin>>A[i];
        s=min(s,A[i]);
        m[A[i]]+=1;
    }
    for(int i=0;i<n;i++) {
        cin>>B[i];
        s=min(s,B[i]);
        m[B[i]]-=1;
    }
    // input ends here
    
    // print(A);
    // print(B);
    //printmap(m);


    for(auto it:m){
        if(abs(it.second)%2!=0){
            cout<<-1<<endl;
            return;
        }
    }

    int cost=0;
    map<int,int> dict;

    for(auto it:m){
        if(it.second!=0){
            dict[it.first]=abs(it.second)/2;
        }
    }

    // printmap(dict);
    // cout<<s<<endl;

    while(!dict.empty()){
        pair<int,int> x = *dict.begin();
        pair<int,int> y = *dict.rbegin();

        if(x.first==y.first){
            x.second /=2;
            cost+=min(2 * s * x.second, x.first * x.second);
            dict.erase(x.first);
        }

        else if(x.second>y.second){
            dict[x.first] = x.second - y.second;
            cost+=min(2 * s * y.second, x.first * y.second);
            dict.erase(y.first);
        }

        else if(x.second<y.second){
            dict[y.first] = y.second - x.second;
            cost+=min(2 * s * x.second, x.first * x.second);
            dict.erase(x.first);
        }
        else{
            cost+=min(2 * s * x.second, x.first * x.second);
            dict.erase(x.first);
            dict.erase(y.first);
        }
    }
    cout<<cost<<endl;
    dict.clear();
}

int32_t main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
        solve();
	}
	return 0;
}
