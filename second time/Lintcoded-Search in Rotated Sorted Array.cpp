class Solution {
    /** 
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        // write your code here
        if(A.size() ==  0) return -1;
        
        int len = A.size();
        int low = 0;
        int high = len-1;
        
        while(low+1 < high){
            int mid = low + (high - low)/2;

            if(A[mid] == target) return mid;
            if(A[low] <= A[mid]){//down
                if(target >= A[low] && target <= A[mid]){
                    high = mid;
                }else low = mid;
            }else{
                if(target >= A[mid] && target <= A[high]){
                    low = mid;
                }else high = mid;
            }
        }
        
        if(A[high] == target) return high;
        if(A[low] == target) return low;
        return -1;
    }
};
