//https://codeforces.com/problemset/problem/1944/A
#include<bits/stdc++.h>
using namespace std;
#define with_test_case int test_no; cin>>test_no; for(int test_case=1;test_case<=test_no;test_case++)
#define coutcase cout<<"Case "<<test_case<<": " 
#define nl "\n" 




void solve(){

int n,k;
cin>>n>>k;

if(n-1<=k) cout<<1<<nl; //we disconnect 1 no iceland
else cout<<n<<nl;

}




int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
with_test_case solve();
return 0;
}