#include<bits/stdc++.h>
using namespace std;
#define with_tc int test_no; cin>>test_no; for(int tc=1;tc<=test_no;tc++)
#define coutcase cout<<"Case "<<tc<<": " 
#define nl "\n" 




void solve(int tc){

int m,n,k;
cin>>n>>m>>k;
int ans=0;
if(min(min(n,k),m)==m){
    ans= m+min((n-m)/2,k-m);
}
else ans= min(n,k);

coutcase<<ans<<nl;

}




int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
freopen("katryoshka.in","r",stdin);
with_tc solve(tc);
return 0;
}