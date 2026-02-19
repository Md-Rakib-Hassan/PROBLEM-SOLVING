//https://codeforces.com/contest/2195/problem/A

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
    int n,v,is67=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v;
        if(v==67)is67=1;
    }
    if(is67)cout<<"YES"<<nl;
    else cout<<"NO"<<nl;

}




return 0;
}
