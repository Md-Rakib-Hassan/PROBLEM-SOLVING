//https://www.codechef.com/practice/course/2to3stars/LP2TO301/problems/MAKEDIV3
#include<bits/stdc++.h>
using namespace std;
#define with_test_case int test_no; cin>>test_no; for(int test_case=1;test_case<=test_no;test_case++)
#define coutcase cout<<"Case "<<test_case<<": " 
#define nl "\n"

void solve()
{

    int n;
    cin >> n;
    if (n == 1)
        cout << 3 << nl;
    else
    {
        string s = "1";
        s.append(n - 2, '0');
        s.push_back('5');
        cout << s << nl;
    }
}

int main()
{
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
with_test_case solve();
return 0;
}