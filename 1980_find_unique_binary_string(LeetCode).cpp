//https://leetcode.com/problems/find-unique-binary-string


//O(n) by using Cantor's diagonal argument

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string s="";
        int sz=nums.size();
        for(int i=0;i<nums.size();i++)
            nums[i][i]=='1'?s.push_back('0'):s.push_back('1');
        return s;
    }
};



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//O(N∗2^N)

class Solution {
public:

    string binary(int n, int sz){
        string s="";
        while(n){
            n&1?s.push_back('1'):s.push_back('0');
            n>>=1;
        }
        for(int i=s.size();i<sz;i++){
            s.push_back('0');
        }
        reverse(s.begin(),s.end());
        return s;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(),nums.end());
        int sz=nums.size(),j=0;
        string s;

        for(int i=0;i<=1<<16;i++){
                s=binary(i,sz);
                if(j>=sz)return s;
                if(s!=nums[j])return s;
                else j++;
            
        }
        return s;
        
    }
};