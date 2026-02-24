//https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/


///////// O(Mlog(N))/////////////

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size(),ans=0;

        int s=0,e=c-1;
        for(int i=0;i<r;i++){
            while(s<=e){
                int m=s+(e-s+1)/2;
                if(grid[i][m]>=0)s=m+1;
                else e=m-1;
            }
            ans+=c-s; 
            e=s;
        }
        return ans; 

    }
};




/////////////// O(M+N)//////////////

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size(),ans=0,idx=c-1;
        
        for(int i=0;i<r;i++){
            while(idx>=0 && grid[i][idx]<0)idx--;
            ans+=(c-idx-1);
        }
        return ans;
    }
};