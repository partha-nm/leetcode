class Solution {
public:
 
    bool solve(vector<vector<char>>&board, string word, int n, int m , int i, int j, int k)
    {
        if(k == word.size()) return true;
        if(i == n || j == m || i<0 || j< 0) return false;
        if(board[i][j] != word[k]) return false;
        
        char temp = board[i][j];
        board[i][j] = '_';
        if(solve(board, word, n, m, i+1, j , k+1) || solve(board , word , n, m, i, j+1, k+1) || solve(board, word, n, m, i-1, j , k+1) || solve(board , word , n, m, i, j-1, k+1)) return true;
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int n = board.size();
        int m = board[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(solve(board, word, n, m , i  , j , 0)) return true;
            }
        }
        return false;
    }
};