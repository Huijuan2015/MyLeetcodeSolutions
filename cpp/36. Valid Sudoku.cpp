class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //每行每列每9格
        /*bool row[9][9] = {false}, col[9][9] = {false}, box[9][9] = {false};
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int num = board[i][j] - '0' - 1;
                    int k = i/3*3 + j/3;
                    if(row[i][num] || col[j][num] || box[k][num]) return false;
                    row[i][num] = col[j][num] = box[k][num] = true;//将所在行列方格都置为true
                }
            }
        }
        return true;*/
        
        
        
        int rowValid[10] = {0};//用于判断某一行是否合法
        int columnValid[10] = {0};//用于判断某一列是否合法
        int subBoardValid[10] = {0};//用于判断某一个九宫格是否合法
        for(int i = 0; i < 9; i++){
          memset(rowValid, 0, sizeof(rowValid));
          memset(columnValid, 0, sizeof(columnValid));
          memset(subBoardValid, 0, sizeof(subBoardValid));
          for(int j = 0; j < 9; j++)
          {
              if(!checkValid(rowValid, board[i][j]-'0') ||
                 !checkValid(columnValid, board[j][i]-'0') ||
                 !checkValid(subBoardValid, board[3*(i/3) + j/3][3*(i%3) + j%3]-'0'))
                 return false;
          }
        }
        return true;
  }
  bool checkValid(int vec[], int val)
  {
    if(val < 0)return true;//对应的是字符‘.’
    if(vec[val] == 1)return false;
    vec[val] = 1;
    return true;
  }
};