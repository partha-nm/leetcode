class Solution {
public:
    
    void solve(vector<vector<int>>&image, int i, int j, int newColor , int color)
    {
        if(i < 0 || i>= image.size() || j < 0 || j>= image[0].size()) return;
        if(image[i][j] != color) return;
        image[i][j] = newColor;
        solve(image ,i+1 , j , newColor, color);
        solve(image ,i-1 , j , newColor, color);
        solve(image ,i, j+1 , newColor, color);
        solve(image ,i , j-1 , newColor, color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        int color = image[sr][sc];
        if(color == newColor) return image;
        solve(image , sr, sc, newColor, color);
        return image;
    }
};