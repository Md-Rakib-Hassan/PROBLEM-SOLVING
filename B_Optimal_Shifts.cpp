//https://codeforces.com/problemset/problem/2176/B
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
int n,maxDist=0,ans=0;
string s;
cin>>n>>s;

for(int i=0;i<2*n-1;i++){
    if(s[i%n]=='1')maxDist=0;
    else{
        maxDist++;
        ans=max(ans,maxDist);
    }
}

cout<<ans<<nl;



}






return 0;
}
