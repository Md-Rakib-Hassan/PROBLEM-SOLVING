//https://leetcode.com/problems/toeplitz-matrix/

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        bool ans=true;
        int r=matrix.size(),c=matrix[0].size();
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(matrix[i][j]!=matrix[i-1][j-1]){
                    ans=false;
                    break;
                }
                if(!ans)break;
            }
        }
    return ans;
    }
};