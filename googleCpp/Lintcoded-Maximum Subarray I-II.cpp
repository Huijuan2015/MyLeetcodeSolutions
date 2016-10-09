class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        if(nums.empty() || nums.size() == 0) return 0;
        int maxSum = INT_MIN;
        int f = 0;
        for(int i = 0; i < nums.size(); ++i){
            f = max(f+nums[i], nums[i]);
            maxSum = max(maxSum, f);
        }
        return maxSum;
    }
};

当我们从头到尾遍历这个数组的时候，对于数组里的一个整数，它有几种选择呢？
它只有两种选择： 1、加入之前的SubArray；2. 自己另起一个SubArray。
那什么时候会出现这两种情况呢？

如果之前SubArray的总体和大于0的话，我们认为其对后续结果是有贡献的。
这种情况下我们选择加入之前的SubArray

如果之前SubArray的总体和为0或者小于0的话，我们认为其对后续结果是没有贡献，
甚至是有害的（小于0时）。这种情况下我们选择以这个数字开始，另起一个SubArray。

----------------
2.
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
        // write your code here
        //i左右求max
        if(nums.size() < 2 || nums.empty()) return 0;
        int len = nums.size();
        if(nums.size() == 2) return nums[0]+nums[1];
        vector<int> maxRight(len,INT_MIN);
        vector<int> maxLeft(len,INT_MIN);
        int prevPosSum = max(nums[0],0);
        int maxRes = INT_MIN;
        maxLeft[0] = nums[0];
        
        for(int i = 1; i < len; ++i){
            prevPosSum = max(prevPosSum+nums[i], nums[i]);
            maxLeft[i] = max(maxLeft[i-1],prevPosSum);
        }
        
        prevPosSum = max(nums[len-1],0);
        maxRight[len-1] = nums[len-1];
        
        for(int i = len-2; i >= 0; --i){
            prevPosSum = max(prevPosSum+nums[i], nums[i]);
            maxRight[i] = max(maxRight[i+1],prevPosSum);
        }

        for(int i = 0; i < len-1; ++i){
           maxRes = max(maxRes, maxLeft[i] + maxRight[i+1]);
        }
        return maxRes;
    }
};
-II