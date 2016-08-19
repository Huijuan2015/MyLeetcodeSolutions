class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if( dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int cur, int row, int col){
        int n = word.length();
        if(cur == n) return true;
        if(row >= board.size() || col >= board[0].size() || row < 0 || col < 0 ) return false;
        
        
        
        if(board[row][col] != word[cur] || board[row][col] == '*') 
            return false;
        char temp = board[row][col];
        board[row][col] = '*';
        if(dfs(board, word, cur+1, row+1, col) || dfs(board, word, cur+1, row-1, col) || dfs(board, word, cur+1, row, col+1) || dfs(board, word, cur+1, row, col-1)) return true;
        board[row][col] = temp;
        
        return false;
    }
};