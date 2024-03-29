//https://codeforces.com/problemset/problem/1946/A
#include<bits/stdc++.h>
using namespace std;


int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


int t;
cin>>t;

for(int i=0; i<t; i++){

    int n;
    cin>>n;

    vector<int>v;

    for(int j=0; j<n; j++){
        int value;
        cin>>value;
        v.push_back(value);

    }
    sort(v.begin(),v.end());

    int mid= (n-1)/2;
    int ans=0;

    for(int k=mid; k<n; k++){
        if(v[k]==v[mid])ans++;
        else break;
    }
    cout<<ans<<'\n';


}


return 0;
}