//https://codeforces.com/contest/2184/problem/B
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

ll t;
cin>>t;
 while (t--) {
        ll s,k,m;
        cin>>s>>k>>m;
        ll r=m%k;
        ll ans;
        
        if (s<=k)ans = max(s-r,0LL);
         else {
            ll q=m/k;
            if (q%2==0)ans=s-r;
             else ans=k-r;
            
        }
        
        cout << ans << nl;
    }
return 0;

}

