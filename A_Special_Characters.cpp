// https://codeforces.com/problemset/problem/1948/A
#include<bits/stdc++.h>
using namespace std;
#define test int tt; cin>>tt; for(int tc=1;tc<=tt;tc++)

int main()
{
test{
    int n;
    cin>>n;

    if(n&1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=0;i<n/2;i++)cout<<"AAB";
        cout<<endl;
    }


}

return 0;
}
