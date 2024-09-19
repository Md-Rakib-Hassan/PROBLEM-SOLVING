#include<bits/stdc++.h>
using namespace std;
#define nl "\n"

int main(){

    string s;
    cin >> s;
    set<char> st;
    for(auto ch:s)st.insert(ch);
    if(st.size()&1)
        cout << "IGNORE HIM!" << nl;
    else cout << "CHAT WITH HER!" << nl;
return 0;
}