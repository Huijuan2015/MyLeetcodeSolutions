class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        // write your code here
        //f[][]
        if(triangle.empty() || triangle.size() == 0){
            return 0;
        }
        
        int row =triangle.size();
        vector<vector<int>> f(row, vector<int>(row));
        f[0][0] = triangle[0][0];
        //row行中有row个元素
        //两边初始化
        for(int i = 1; i < row;++i){
            f[i][0] = f[i-1][0]+triangle[i][0];
            f[i][i] = f[i-1][i-1]+triangle[i][i];
        }
        
        for(int i = 1; i < row;++i){
            for(int j = 1; j < i; ++j){
                f[i][j] = min(f[i-1][j-1], f[i-1][j])+triangle[i][j];
            }
        }
       

        sort(f[row-1].begin(), f[row-1].end());
        return f[row-1][0];
    }
};
