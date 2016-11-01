class Solution {
public:
    /**
     * @param A an integer array sorted in ascending order
     * @param target an integer
     * @return an integer
     */
    int findPosition(vector<int>& A, int target) {
        // Write your code here
        if(A.size() == 0) return -1;
        
        int len = A.size();
        int start = 0;
        int end = len-1;
        int mid;
        
        while(start <= end){
            mid = start + (end-start)/2;
            if(A[mid] == target) return mid;
            else if(A[mid] < target){
                start = mid+1;
            }else end = mid-1;
        }
        if(A[start] == target) return start;
        //if(A[end] == target) return end;
        return -1;
    }
};