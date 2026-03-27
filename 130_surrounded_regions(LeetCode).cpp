//https://leetcode.com/problems/surrounded-regions

class Solution {
public:
    bool vis[201][201];
    void dfs(vector<vector<char>>& board,int i,int j){
        int m=board.size(),n=board[0].size();
        if(i>=m || j>=n || i<0 || j<0 || vis[i][j] ||board[i][j]=='X')return;
        vis[i][j]=true;
        dfs(board,i+1,j);
        dfs(board,i,j+1);
        dfs(board,i-1,j);
        dfs(board,i,j-1);
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0 && i<m-1 && j!=0 && j!=n-1)continue;
                if(board[i][j]=='O' && !vis[i][j]){
                    dfs(board,i,j);
                }
            }
        }


         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j])board[i][j]='X';
            }
        }

    }
};