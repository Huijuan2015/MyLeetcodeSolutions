class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        if(A.size() == 0) return -1;
        
        int len = A.size();
        int low = 0;
        int high = len-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(A[mid]>A[mid-1] && A[mid] > A[mid+1]) return mid;
            else if(A[mid]<A[mid-1]) high = mid-1;
            else if(A[mid] > A[mid-1]) low = mid+1;
        }
        return -1;
    }
};

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        // write your code here
        if(A.size() == 0) return -1;
        
        int len = A.size();
        int low = 0;
        int high = len-1;
        
        while(low+1 < high){
            int mid = low + (high-low)/2;
            if(A[mid]>A[mid-1] && A[mid] > A[mid+1]) return mid;
            else if(A[mid]<A[mid-1]) high = mid;
            else if(A[mid] > A[mid-1]) low = mid;
        }
        // if(high>0&&high<len-1&&A[high]>A[high-1]&&A[high]>A[high+1])return high;
        // if(low>0&&low<len-1&&A[low]>A[low-1]&&A[low]>A[low+1]) return low;
        return -1;
    }
};

