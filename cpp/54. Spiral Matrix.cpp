class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return {};
        int nr = matrix.size();//几行
        int nl =matrix[0].size();//几列
        if(nl == 0 || nr == 0) return result;
        int minRow = 0, minCol = 0;
        int maxRow = nr-1;
        int maxCol = nl-1;
       
        
        while(minRow <= maxRow && minCol <= maxCol){
            for(int i = minCol; i <= maxCol; ++i){
                result.push_back(matrix[minRow][i]);
            }
            minRow ++;
            
            for(int j = minRow; j <= maxRow; ++j){
                result.push_back(matrix[j][maxCol]);
            }
            maxCol --;
            
            if(minRow <= maxRow){
                for(int k = maxCol; k >= minCol; --k){
                    result.push_back(matrix[maxRow][k]);
                }
            }
            maxRow --;
            
            if(minCol <= maxCol){
                for(int p = maxRow; p >= minRow; --p){
                    result.push_back(matrix[p][minCol]);
                }
            }
            minCol++;
        }
        return result;
    }
};