//https://codeforces.com/problemset/problem/2193/C

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
    int n,q,v;
    cin>>n>>q;
    vector<int>a,b;

    for(int i=0;i<n;i++){
        cin>>v;
        a.pb(v);
    }
    for(int i=0;i<n;i++){
        cin>>v;
        b.pb(v);
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1)a[i]=max(a[i],b[i]);
        else a[i]=max(max(a[i+1],a[i]),b[i]);
    }

     for(int i=1;i<n;i++){
        a[i]+=a[i-1]; //prefix sum
    }
    

    while(q--){
        int l,r;
        cin>>l>>r;
        int ans=l-2<0?a[r-1]:a[r-1]-a[l-2];
        cout<<ans<<" ";
    }
    cout<<nl;
}






return 0;
}
