//https://codeforces.com/contest/2195/problem/C

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
    int n,val;
    cin>>n;
    vector<int>v,idx;
    for(int i=0;i<n;i++){
        cin>>val;
        v.pb(val);
    }
    int ans=0;
    for(int i=0; i<n-1;i++){
        if(v[i]+v[i+1]==7 || v[i]==v[i+1]){
            ans++;
            i++;
        }
    }
    


    cout<<ans<<nl;
    
 

}




return 0;
}
