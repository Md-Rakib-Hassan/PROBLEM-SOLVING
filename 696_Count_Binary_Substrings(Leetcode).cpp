//https://leetcode.com/problems/count-binary-substrings

class Solution {
public:
    int countBinarySubstrings(string s) {
        int one=0,zero=0,temp=0,ans=0;
        char running=s[0];

        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                if(running=='0'){
                    temp=zero;
                }
                running=s[i];
                zero=0;
                one++;
                if(temp>0){
                ans++;
                temp--;
                }
            }
            else{
                 if(running=='1'){
                    temp=one;
                }
                running=s[i];
                one=0;
                zero++;
                if(temp>0){
                ans++;
                temp--;
                }
            }
        }
        return ans;
    }
};