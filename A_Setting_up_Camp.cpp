//https://codeforces.com/problemset/problem/1945/A

#include<bits/stdc++.h>
using namespace std;


#define test int test_no; cin>>test_no; for(int test_case=1;test_case<=test_no;test_case++)
#define coutcase cout<<"Case "<<test_case<<": " 
#define nl "\n" 


int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif


test{
    int a,b,c;
    cin>>a>>b>>c;
    if(((b%3)==2 && c==0) || ((b%3)==1 && c<2) )cout<<-1<<nl;
    else{
        int room_no=a+ceil((b+c)/3.0);
        cout<<room_no<<nl;
    }

}


return 0;
}