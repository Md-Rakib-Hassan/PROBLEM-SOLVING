//https://leetcode.com/problems/flood-fill

class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int src_color, int color){
        int r=image.size(),c=image[0].size();
        if(sr<0 || sc<0 || sr>=r || sc>=c ||image[sr][sc]!=src_color)return;
        image[sr][sc]=color;
        dfs(image,sr+1,sc,src_color,color);
        dfs(image,sr,sc+1,src_color,color);
        dfs(image,sr-1,sc,src_color,color);
        dfs(image,sr,sc-1,src_color,color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)dfs(image,sr,sc,image[sr][sc],color);
        return image;
        
    }
};