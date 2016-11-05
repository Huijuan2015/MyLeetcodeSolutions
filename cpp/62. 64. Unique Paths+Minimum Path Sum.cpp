class Solution {
public:
    int uniquePaths(int m, int n) {
        vector< vector < int > > f(m, vector< int > (n));
        
        for(int i = 0;i < m; ++i){
            f[i][0] = 1;
        }
        for(int i = 0; i < n; ++i){
            f[0][i] = 1;
        }
        
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m-1][n-1];
    }
};

64. Minimum Path Sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector< vector< int> > sum(grid.size(), vector<int> (grid[0].size()));
        int tmpsum= 0;
        for(int i = 0; i < grid.size(); ++i){
            tmpsum += grid[i][0];
            sum[i][0] = tmpsum;
        }
        tmpsum = 0;
        for(int i = 0; i < grid[0].size(); ++i){
            tmpsum += grid[0][i];
            sum[0][i] = tmpsum;
        }
        
        for(int i = 1; i < grid.size(); ++i){
            for(int j = 1; j < grid[0].size(); ++j){
                sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
            }
        }
        return sum[grid.size()-1][grid[0].size()-1];
    }
};