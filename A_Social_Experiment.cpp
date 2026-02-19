//https://codeforces.com/contest/2184/problem/A
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
    int n;
    cin>>n;
    int rem=n%2;
    if (n == 2) {
            cout << 2 << nl;
        } else if (n == 3) {
            cout << 3 << nl;
        } else if (rem == 0) {
            cout << 0 << nl;
        } else {
            cout << 1 << nl;
        }
    


}
return 0;

}

