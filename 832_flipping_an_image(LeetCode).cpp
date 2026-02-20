//https://leetcode.com/problems/flipping-an-image

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int r=image.size(),c=r;
        for(int i=0;i<r;i++){
            for(int j=0;j<(c+1)/2;j++){
                image[i][j]^=1;
                if(j!=c-j-1)image[i][c-j-1]^=1;
                swap(image[i][j],image[i][c-j-1]);
            }
        }
        return image;
    }
};