//https://codeforces.com/contest/2203/problem/B

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
string s;
vector<int>v;
cin>>s;
int sum=0;
int first=s[0]-'0';
int focc=0;
for(int i=0;i<s.size();i++){
    int num=s[i]-'0';
v.pb(num);
sum+=num;
if(num==first)focc++;
}
bool is_reduced_first=false;
sort(all(v));
int ans=0;
for(int i=v.size()-1;i>=0;i--){
    if(sum > 9){
    if(focc==1 && v[i]==first){
        sum=sum-v[i]+1;
    }
    else if(v[i]==first){
        sum-=v[i];
        focc--;
    }
    else sum-=v[i];
    ans++;
    }
    else break;

}
cout<<ans<<nl;



}







return 0;
}
