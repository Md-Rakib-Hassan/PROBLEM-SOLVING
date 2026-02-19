//https://codeforces.com/contest/2184/problem/C
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
        ll n,k;
        cin>>n>>k;

        queue<pair<ll,int>>q;
        q.push({n,0});
        bool found=false;
        int ans=-1;
        unordered_set<ll>vis;
        vis.insert(n);

        while(!q.empty()) {
            auto [pile,time]=q.front(); 
            q.pop();
            if(pile==k) {
                ans=time;
                found=true;
                break;
            }
            if(pile<k) continue;
            if(pile>1) {
                ll left=pile/2;
                ll right=pile-left;
                if(vis.find(left)==vis.end()) {
                    q.push({left,time+1});
                    vis.insert(left); }
                if(vis.find(right)==vis.end()) { 
                    q.push({right,time+1});
                    vis.insert(right); }
            }
        }

        cout<<ans<<nl;
    }
return 0;

}

