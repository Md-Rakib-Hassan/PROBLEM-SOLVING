//https://cses.fi/problemset/task/1084
#include<bits/stdc++.h>
using namespace std;
#define with_test_case int test_no; cin>>test_no; for(int test_case=1;test_case<=test_no;test_case++)
#define coutcase cout<<"Case "<<test_case<<": "
#define ll long long 
#define rep(i,x,n) for(int i=x;i<n;i++)
#define vin(v,ll,n) int n;cin>>n;vector<ll>v;rep(i,0,n){ll x; cin>>x;v.pb(x);
#define vinn(v,ll,n)vector<ll>v;rep(i,0,n){ll x; cin>>x;v.pb(x);}
#define all(we) we.begin(),we.end()
#define pb push_back
#define ff first
#define ss second
#define nl "\n"

void solve()
{

    ll applicants, appartments, differences;
    cin >> applicants >> appartments >> differences;
    vinn(applicants_arr, ll, applicants);
    vinn(appartments_arr, ll, appartments);
    sort(all(appartments_arr));
    sort(all(applicants_arr));
    ll ans = 0, i = 0, j = 0;

    while (i < applicants && j < appartments)
    {
        if (abs(applicants_arr[i] - appartments_arr[j]) <= differences)
        {
            i++;
            j++;
            ans++;
        }
        else if (applicants_arr[i] < appartments_arr[j])
        {
            i++;
        }

        else
            j++;
    }

    cout << ans << nl;
}

int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
solve();
return 0;
}