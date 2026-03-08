//https://leetcode.com/problems/spiral-matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        int t=0,b=m.size()-1,l=0,r=m[0].size()-1;
        vector<int>a;

        while(t<=b && l<=r){

            for(int i=l;i<=r;i++){
                a.push_back(m[t][i]);
            }t++;
            for(int i=t;i<=b;i++){
                a.push_back(m[i][r]);
            }r--;
            
            if(t>b || l>r)break;

            for(int i=r;i>=l;i--){
                a.push_back(m[b][i]);
            }b--;
            
            for(int i=b;i>=t;i--){
                a.push_back(m[i][l]);
            }l++;
        }
        return a;

    }
};