//https://codeforces.com/contest/2203/problem/A

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(we) we.begin(),we.end()
#define pb push_back
#define ff first
#define ss second
#define nl "\n" 




int main()
{

int t;
cin>>t;
while(t--){
int n,m,d;
cin>>n>>m>>d;
int towermx=(d/m)+1;
int ans=(n/towermx);
if(n%towermx>0)ans++;

cout<<ans<<nl;



}







return 0;
}
