class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int lastPosition(vector<int>& A, int target) {
        
        // Write your code here
        if(A.size() == 0) return -1;
        
        int len = A.size();
        int low = 0;
        int high = len - 1;
        
        while(low <= high){
            int mid = low + ((high - low)>>1);
            if(A[mid] == target){
                low = mid;
                if(low == len -1) return low;
                if(low < len-1 && A[low] != A[low+1]){
                    return low;
                }
                low ++;
                
            }else if(A[mid] < target){
                low = mid +1;
            }else high = mid - 1;
        }
        
        return -1;
    }
};