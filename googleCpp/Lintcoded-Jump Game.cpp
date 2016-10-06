class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
        // write you code here
        
        if(A.size() == 0)return false;
        
        int curMax = A[0];//当前可以抵达的最远位置
        int len = A.size();
        for(int i = 1; i < len; ++i){
            if(i > curMax) return false;
            else if(A[i]+i >= len-1) return true;
            curMax = max(A[i]+i, curMax);
        }
        return true;
    }
};


f[i]能否跳到i