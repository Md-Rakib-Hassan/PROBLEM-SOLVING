//https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    
   vector<string> generate(vector<string>&v,string &cur,int s,int e){
    if(s==0 && e==0){
        v.push_back(cur);
        return v;
    }
    if(s>0){
        cur.push_back('(');
        generate(v,cur,s-1,e);
        cur.pop_back();
    }
    if(e>0 && s<e){
        cur.push_back(')');
        generate(v,cur,s,e-1);
        cur.pop_back();
    }
    return v;
   }


    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string s="";
        return generate(v,s,n,n);
    }
};