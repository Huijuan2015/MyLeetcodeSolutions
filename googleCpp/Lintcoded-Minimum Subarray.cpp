class Solution {
public:
    /**
     * @param nums: a list of integers
     * @return: A integer denote the sum of minimum subarray
     */
    int minSubArray(vector<int> nums) {
        // write your code here
        if(nums.empty() || nums.size() == 0) return 0;
        
        int minRes = INT_MAX;
        int prevSum = 0;
        for(int i = 0; i < nums.size(); ++i){
            prevSum = min(nums[i],prevSum+nums[i]);
            minRes = min(minRes, prevSum);
        }
        return minRes;
    }
};
