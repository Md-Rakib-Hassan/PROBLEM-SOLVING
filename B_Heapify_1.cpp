//https://codeforces.com/contest/2195/problem/B

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(we) we.begin(),we.end()
#define pb push_back
#define ff first
#define ss second
#define nl "\n" 


int root(int x) {
    while(x%2==0) x/=2;
    return x;
}


int main()
{




int t;
cin>>t;

while(t--){
    int n,val;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        cin>>val;
        v.pb(val);
    }

    bool ans=true;

    for (int i=1; i<=n; i++) {
            if (root(i)!=root(v[i-1])) {
                ans=false;
                break;
            }
        }

    if(ans)cout<<"YES"<<nl;
    else cout<<"NO"<<nl;

}




return 0;
}
