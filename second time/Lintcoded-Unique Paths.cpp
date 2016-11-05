class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        // wirte your code here
        if(n == 0){
            return 0;
        }
        
        int sum[m][n] ;
        //vector<vector<int> > f(m, vector<int>(n));
        for(int i = 0; i< m; ++i){
            sum[i][0] = 1;
        }
        
        for(int i = 0; i< n; ++i){
            sum[0][i] = 1;
        }
        
        for(int i = 1; i< m; ++i){
            for(int j = 1; j < n ; ++j){
                sum[i][j] = sum[i-1][j] + sum[i][j-1];
            }
            }
            
            return sum[m-1][n-1];
    }
};