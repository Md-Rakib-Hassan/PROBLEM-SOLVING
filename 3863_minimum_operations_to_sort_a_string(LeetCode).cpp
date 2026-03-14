//https://leetcode.com/problems/minimum-operations-to-sort-a-string/


class Solution {
public:
    int minOperations(string s) {
        bool sorted=true;
        int multiple_mx=0,multiple_mn=0;
        char mx=s[0],mn=s[0];
        for(int i=1;i<s.size();i++){
            mx=max(mx,s[i]);
            mn=min(mn,s[i]);
            if(s.size()>1 && s[i-1]>s[i])sorted=false;
        }
        for(char ch:s){
            if(ch==mx)multiple_mx++;
            if(ch==mn)multiple_mn++;
        }
        if(sorted) return 0;
        if(s.size()==2 && s[0]==mx)return -1;
        if(s[0]==mn || s.back()==mx)return 1;
        if(s[0]==mx && s.back()==mn && multiple_mx==1 && multiple_mn==1)return 3;
        return 2;
    }
};