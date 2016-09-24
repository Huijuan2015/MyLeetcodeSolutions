class Solution {
    /** 
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        // write your code here
        if(A.size() == 0) return 0;
        
        int len = A.size();
        int start = 0;
        int end = len - 1;
        
        while(start <= end){
            int mid = start + (end - start)/2;
            if(A[mid] == target) return mid;
            else if(A[mid] < target) start = mid + 1;
            else if(A[mid] > target) end = mid - 1;
        }
        
        if(A[start] >= target) return start;
        else if(A[end] >= target) return end;
        else return end+1;
    }
};
