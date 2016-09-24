class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // write your code here
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int high = row*col-1;
        int low = 0;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            int midrow = mid/col;
            int midcol = mid%col;
            
            if(matrix[midrow][midcol] == target){
                return true;
            }else if(matrix[midrow][midcol] > target){
                    high = mid-1;
            }else low = mid+1;
        }
        
        return false;
    }
};

