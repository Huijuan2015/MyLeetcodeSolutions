class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //reverse down to up
        //swap symmetry
        if(matrix.empty()) return;
        
        int nRow = matrix.size()-1;
        int nCol = matrix[0].size()-1;
        
        reverse(matrix.begin(), matrix.end());
        
        for(int i = 0; i <= nRow; ++i){
            for(int j = i+1; j <= nCol; ++j){        //i+1
                swap(matrix[i][j], matrix[j][i]);
            }
        }
   
    }
};

//如果是逆时针 anticlockwise rotate
//reverse left to right
//swap symmetry

for(auto vi : matrix){
    reverse(vi.begin(), vi.end());
}